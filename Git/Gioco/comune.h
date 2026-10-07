// Funzioni in comune tra i giochi "indovina il pin" e "indovina la parola".
// La soluzione viene salvata in un file di testo con un carattere per riga
// (pin.txt oppure parola.txt).
#ifndef COMUNE_H
#define COMUNE_H
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <windows.h>
using namespace std;

// "pin" (maschile, cifre) oppure "parola" (femminile, lettere)
struct Gioco{
	string nome;      // pin / parola
	string articolo;  // il / la
	string unita;     // cifre / lettere
	string file;      // pin.txt / parola.txt
};
const Gioco GIOCO_PIN={"pin","il","cifre","pin.txt"};
const Gioco GIOCO_PAROLA={"parola","la","lettere","parola.txt"};

// legge un numero intero senza andare in loop se l'utente scrive una lettera
inline int leggi_intero(string messaggio){
	int n;
	while(true){
		cout<<messaggio;
		if(cin>>n){
			return n;
		}
		if(cin.eof()){
			exit(0);
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"devi inserire un numero"<<endl;
	}
}

inline string minuscolo(string s){
	for(int i=0;i<(int)s.size();i++){
		s[i]=tolower((unsigned char)s[i]);
	}
	return s;
}

// controlla che il testo sia fatto solo di cifre (pin) o solo di lettere (parola)
inline bool valida(const Gioco &g,const string &s){
	for(int i=0;i<(int)s.size();i++){
		unsigned char c=s[i];
		if(g.nome=="pin"&&!isdigit(c)){
			return false;
		}
		if(g.nome=="parola"&&!isalpha(c)){
			return false;
		}
	}
	return true;
}

// chiede una parola/pin lunga esattamente n caratteri
inline string leggi_tentativo(const Gioco &g,string messaggio,int n){
	string s;
	while(true){
		cout<<messaggio;
		if(!(cin>>s)){
			exit(0);
		}
		s=minuscolo(s);
		if((int)s.size()!=n){
			cout<<"devi inserire esattamente "<<n<<" "<<g.unita<<endl;
		}else if(!valida(g,s)){
			cout<<"puoi usare solo "<<g.unita<<endl;
		}else{
			return s;
		}
	}
}

// legge il file (un carattere per riga) saltando le righe vuote
inline string leggi_soluzione(const Gioco &g){
	ifstream inputfile(g.file.c_str());
	string line,soluzione;
	while(getline(inputfile,line)){
		for(int i=0;i<(int)line.size();i++){
			if(!isspace((unsigned char)line[i])){
				soluzione+=(char)tolower((unsigned char)line[i]);
				break;
			}
		}
	}
	inputfile.close();
	return soluzione;
}

inline bool salva_soluzione(const Gioco &g,const string &s){
	ofstream outputfile(g.file.c_str(),ios::trunc);
	for(int i=0;i<(int)s.size();i++){
		outputfile<<s[i]<<endl;
	}
	outputfile.close();
	return leggi_soluzione(g)==s;
}

inline void spiega_difficolta(const Gioco &g){
	cout<<"Decidi la difficolta: "<<endl
		<<"Facile = 1"<<endl<<"In questa modalita' saprai sostanzialmente tutto, quindi sia le "<<g.unita<<" nella posizione scorretta che corretta."<<endl
		<<"Media = 2"<<endl<<"In questa modalita' saprai quali "<<g.unita<<" hai indovinato se e solo se saranno nella posizione giusta"<<endl
		<<"Difficile = 3"<<endl<<"In questa modalita' saprai soltanto quante "<<g.unita<<" hai indovinato se e solo se saranno nella posizione corretta"<<endl;
}

inline int scegli_difficolta(const Gioco &g){
	spiega_difficolta(g);
	int scelta;
	do{
		scelta=leggi_intero("inserisci: ");
	}while(scelta<1||scelta>3);
	return scelta;
}

// difficolta: 1 = facile, 2 = media, 3 = difficile
inline void gioca(const Gioco &g,int difficolta){
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	string soluzione=leggi_soluzione(g);
	if(soluzione.empty()){
		cout<<"non c'e' nessun"<<(g.nome=="parola"?"a ":" ")<<g.nome<<" salvat"<<(g.nome=="parola"?"a":"o")<<", prima bisogna crearl"<<(g.nome=="parola"?"a":"o")<<endl;
		system("pause");
		return;
	}
	int n=soluzione.size();
	cout<<g.articolo<<" "<<g.nome<<" e' da "<<n<<" "<<g.unita<<endl;
	if(difficolta==1){
		cout<<"sappi che in questa modalita' le "<<g.unita<<" indovinate nella posizione corretta saranno indicate in ";
		SetConsoleTextAttribute(h, 2);
		cout<<" verde ";
		SetConsoleTextAttribute(h, 7);
		cout<<" e quelle nella posizione scorretta in ";
		SetConsoleTextAttribute(h, 14);
		cout<<" giallo "<<endl;
		SetConsoleTextAttribute(h, 7);
	}
	int massimo=0; // 0 = nessun limite
	if(difficolta==2){
		massimo=n*2;
	}else if(difficolta==3){
		massimo=n;
	}
	int tentativi;
	while(true){
		tentativi=leggi_intero("Inserisci quanti tentativi vuoi fare: ");
		if(tentativi<1){
			cout<<"devi fare almeno un tentativo"<<endl;
		}else if(massimo>0&&tentativi>massimo){
			cout<<"in questa difficolta' puoi fare al massimo "<<massimo<<" tentativi"<<endl;
		}else{
			break;
		}
	}
	for(int t=0;t<tentativi;t++){
		string tentativo=leggi_tentativo(g,"\ninserisci "+g.articolo+" "+g.nome+": ",n);
		// 0 = assente, 1 = posizione scorretta, 2 = posizione corretta
		string stato(n,'0');
		int rimasti[256]={0};
		int giuste=0;
		for(int i=0;i<n;i++){
			if(tentativo[i]==soluzione[i]){
				stato[i]='2';
				giuste++;
			}else{
				rimasti[(unsigned char)soluzione[i]]++;
			}
		}
		if(giuste==n){
			cout<<"HAI INDOVINATO "<<(g.nome=="parola"?"LA PAROLA":"IL PIN")<<"!"<<endl;
			system("pause");
			return;
		}
		for(int i=0;i<n;i++){
			if(stato[i]=='0'&&rimasti[(unsigned char)tentativo[i]]>0){
				stato[i]='1';
				rimasti[(unsigned char)tentativo[i]]--;
			}
		}
		cout<<"*********************************"<<endl;
		cout<<"hai indovinato "<<giuste<<"/"<<n<<" "<<g.unita;
		if(difficolta==1){
			cout<<" : ";
			for(int i=0;i<n;i++){
				if(stato[i]=='2'){
					SetConsoleTextAttribute(h, 2);
				}else if(stato[i]=='1'){
					SetConsoleTextAttribute(h, 14);
				}else{
					SetConsoleTextAttribute(h, 8);
				}
				cout<<tentativo[i];
			}
			SetConsoleTextAttribute(h, 7);
		}else if(difficolta==2){
			cout<<" : ";
			for(int i=0;i<n;i++){
				if(stato[i]=='2'){
					cout<<tentativo[i]<<"$ "<<i+1<<" ; ";
				}
			}
			cout<<endl<<"le "<<g.unita<<" con affianco il dollaro sono nella posizione giusta (il numero e' la posizione).";
		}
		cout<<endl<<"tentativi rimasti: "<<tentativi-t-1<<endl;
		system("pause");
	}
	cout<<"hai finito i tentativi, "<<g.articolo<<" "<<g.nome<<" era: "<<soluzione<<endl;
	system("pause");
}
#endif
