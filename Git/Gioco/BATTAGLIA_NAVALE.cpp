#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <process.h>
#include <sstream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <limits>
//srand(unsigned(time(NULL))); 
//n1 = rand()%10;
//SetConsoleTextAttribute(h, 14);
using namespace std;
const int N=10;
	string Tabellone_1 [N][N];
	string Tabellone_2 [N][N];
	string Tabellone_1_attacco [N][N];
	string Tabellone_2_attacco [N][N];
	void riempi_1(){
	string barca;
	{
		ifstream intputfile("tab_att_2.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!getline(intputfile,barca)||barca==""){
					barca="0";
				}
				Tabellone_2_attacco[i][j]=barca;
			}
		}
		intputfile.close();
	}
		ifstream intputfile("tab_att_1.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!getline(intputfile,barca)||barca==""){
					barca="0";
				}
				Tabellone_1_attacco[i][j]=barca;
			}
		}
		intputfile.close();
	}
	void riempi(){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				Tabellone_1_attacco[i][j]="0";
			}
		}
			for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				Tabellone_2_attacco[i][j]="0";
			}
		}
		
		
	}
	int continuare(){
	bool continuare_1=true;
	bool continuare_2=true;
	int c_1=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Tabellone_1[i][j]=="1"){
				c_1++;
			}
		}
	}
	if(c_1==0){
		continuare_1=false;
	}
	int c_2=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Tabellone_2[i][j]=="1"){
				c_2++;
			}
		}
	}
	if(c_2==0){
		continuare_2=false;
	}
	if(continuare_1==false||continuare_2==false){
		return 2;
	}else{
		return 1;
	}
	
}
	void Output_1(){
	cout<<"ecco il tabellone : "<<endl<<"Giocatore 1 : "<<endl;
	cout<<"  ";
	for(int k=0;k<=(N-1);k++)
			{
				cout<<k<<" ";
			}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
			if(Tabellone_1_attacco[i][j]=="0"){
			if(j==0)
			cout<<endl<<i<<" "<<"_"<<" ";
			else
			cout<<"_"<<" ";
		}else if(Tabellone_1_attacco[i][j]=="2"){
		    if(j==0){
			cout<<endl<<i<<" "<<"X"<<" ";
		    }else{
		        cout<<"X"<<" ";
		    }
		}else if(Tabellone_1_attacco[i][j]=="3"){
		    if(j==0){
			cout<<endl<<i<<" "<<"O"<<" ";
		    	}else{
		        cout<<"O"<<" ";
		    	}
			}
		}
	}
cout<<endl;
}
	void Output_2(){
	cout<<"ecco il tabellone : "<<endl<<"Giocatore 2 : "<<endl;
	cout<<"  ";
	for(int k=0;k<=(N-1);k++)
			{
				cout<<k<<" ";
			}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
			if(Tabellone_2_attacco[i][j]=="0"){
			if(j==0)
			cout<<endl<<i<<" "<<"_"<<" ";
			else
			cout<<"_"<<" ";
		}else if(Tabellone_2_attacco[i][j]=="2"){
		    if(j==0){
			cout<<endl<<i<<" "<<"X"<<" ";
		    }else{
		        cout<<"X"<<" ";
		    }
		}else if(Tabellone_2_attacco[i][j]=="3"){
		    if(j==0){
			cout<<endl<<i<<" "<<"O"<<" ";
		    	}else{
		        cout<<"O"<<" ";
		    	}
			}
		}
	}
cout<<endl;
}
	void PosizionaBarche(){
		string pin;
	int a;
	int giocatore;
	do{
		cout<<"che giocatore sei 1 o 2 "<<" inserisci: ";
		cin>>giocatore;
	}while(!(giocatore==1||giocatore==2));
	if(giocatore==1){
	do{
	cout<<"clicca 1 per posizionare le barche giocatore 1: ";
	cin>>a;
	}while(a!=1);
	if(a==1){
	system("Giocatore1batt.exe");
	system("pause");
	system("cls");
   }
}else{
   do{
   cout<<"clicca 2 per posizionare le barche giocatore 2: ";
	cin>>a;
	}while(a!=2);
   if(a==2){
	system("Giocatore2batt.exe");
	system("pause");
	system("cls");
}
}
}
	// legge un numero intero senza andare in loop se l'utente scrive una lettera
	int leggi_intero(string messaggio){
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
	// salva il tabellone delle barche del giocatore (mantenendo il pin)
	void salva_tabellone(string nome_file,string Tabellone[N][N]){
		string pin;
		ifstream intputfile(nome_file.c_str());
		getline(intputfile,pin);
		intputfile.close();
		ofstream outputfile(nome_file.c_str(),ios::trunc);
		outputfile<<pin<<endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				outputfile<<Tabellone[i][j]<<endl;
			}
		}
		outputfile.close();
	}
	void salva_attacchi(string nome_file,string Tabellone[N][N]){
		ofstream outputfile(nome_file.c_str(),ios::trunc);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				outputfile<<Tabellone[i][j]<<endl;
			}
		}
		outputfile.close();
	}
	// turno del giocatore g (1 o 2): attacca le barche dell'avversario
	void turno(int g){
		string (*attacco)[N]=(g==1)?Tabellone_1_attacco:Tabellone_2_attacco;
		string (*avversario)[N]=(g==1)?Tabellone_2:Tabellone_1;
		int scelta;
		int x,y;
		cout<<endl<<"Giocatore "<<g<<": "<<endl;
		do{
			scelta=leggi_intero("vuoi attaccare = 1\nvuoi vedere il tabellone = 2\ninserisci: ");
			if(scelta==2){
				//si puo' vedere il proprio tabellone e poi attaccare
				system(g==1?"tabellone.exe":"tabellone2.exe");
				system("pause");
				system("cls");
				cout<<endl<<"Giocatore "<<g<<": "<<endl;
			}
		}while(scelta!=1);
		if(g==1){
			Output_1();
		}else{
			Output_2();
		}
		while(true){
			y=leggi_intero("inserisci la coordinata y: ");
			x=leggi_intero("inserisci la coordinata x: ");
			if(x<0||x>(N-1)||y<0||y>(N-1)){
				cout<<"coordinate non valide, devono essere tra 0 e "<<N-1<<endl;
			}else if(attacco[y][x]!="0"){
				cout<<"hai gia' attaccato questa casella, scegline un'altra"<<endl;
			}else{
				break;
			}
		}
		if(avversario[y][x]=="1"){
			attacco[y][x]="2";
			avversario[y][x]="2";
			cout<<"colpito"<<endl;
			salva_tabellone(g==1?"tabellone_2.txt":"tabellone_1.txt",avversario);
		}else{
			cout<<"colpo nullo"<<endl;
			attacco[y][x]="3";
		}
		salva_attacchi(g==1?"tab_att_1.txt":"tab_att_2.txt",attacco);
	}
int main() {
	int pos_barche;
	string pin;
	do{
		pos_barche=leggi_intero("hai gia posizionato le barche? si = 1, no = 0\ninserisci: ");
	}while(!(pos_barche==1||pos_barche==0));
	if(pos_barche==0){
	PosizionaBarche();
	system("pause");
	return 0;
	}
	{
	ifstream inputfile("tabellone_2.txt");
	getline(inputfile,pin);
	string pos;
	for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            getline(inputfile,pos);
            Tabellone_2[i][j]=pos;
    }
}
	inputfile.close();
}
		{
	ifstream inputfile("tabellone_1.txt");
	getline(inputfile,pin);
	string pos;
	for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            getline(inputfile,pos);
            Tabellone_1[i][j]=pos;
    }						
   }
   	inputfile.close();
   }
   int a;
   do{
   a=leggi_intero("Avete gia comiciato ? si = 1 no = 0: ");
}while(!(a==1||a==0));
   if(a==0){
   	riempi();
   }else{
   	riempi_1();
   }
   int continua=continuare();
   int vincitore=0;
	while(continua==1){
	turno(1);
	continua=continuare();
	if(continua!=1){
		vincitore=1;
		break;
	}
	turno(2);
	continua=continuare();
	if(continua!=1){
		vincitore=2;
	}
	}
	cout<<endl<<"PARTITA FINITA";
	if(vincitore!=0){
		cout<<" : HA VINTO IL GIOCATORE "<<vincitore;
	}
	cout<<endl<<"Tabellone attacchi giocatore 1: "<<endl;
	Output_1();
	cout<<endl<<"Tabellone attacchi giocatore 2: "<<endl;
	Output_2();
	system("pause");
	return 0;
}
