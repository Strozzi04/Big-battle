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
using namespace std;
string parola;
string intput_parola={" "};
//srand(unsigned(time(NULL))); 
//n1 = rand()%10;
//SetConsoleTextAttribute(h, 14);
int numerolettere=0;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
int main() {
	bool presenza=false;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	int scelta=0,scelta1=0,cgiustev=0,gl=0;
		int tentativi;
		bool vinto=false;
	string lett,lineg,line2;
	do {
		cout<<"1 = sei tu chi decide la parola"<<endl<<"2 = sei chi indovina la parola"<<endl;
		cout<<"Inserisci: ";
		cin>>scelta;
	} while(!(scelta==1||scelta==2));
		do {
		cout<<"Inserisci il numero di lettere: ";
		cin>>numerolettere;
	} while(numerolettere<=1);
	int sicurezza=numerolettere;
	if(scelta==1) {
		ofstream outputfile("parola.txt",ios::trunc);
		int c=0;
		string line;
			cout<<"inserci la parola: ";
			cin>>parola;
			for(int i=0; i<numerolettere; i++) {
			if(i!=numerolettere) {
				outputfile<<parola[i]<<endl;
			} else {
				outputfile<<parola[i];
			}
		}
		outputfile.close();
		ifstream inputfile("parola.txt");
		for(; getline(inputfile,line); c++);
		if(c==numerolettere) {
			cout<<endl<<"E' avvenuto tutto con successo"<<endl;
		} else {
			cout<<endl<<"ci sono stati degli errori."<<endl;
		}
		inputfile.close();
		system("pause");
		return 0;
}else{
	cout<<"Decidi la difficolta: "<<endl<<"Facile = 1"<<endl<<"In questa modalita' saprai sostanzialmente tutto, quindi sia le lettere nella posizione scorretta che corretta."<<endl<<"Media = 2"<<endl<<" In questa modalita' saprai quali lettere hai indovinato se e solo se saranno nella posizione giusta"<<endl<<"Difficile = 3"<<endl<<"In questa modalita' saprai soltanto quante lettere hai indovinato se e solo se saranno nella posizione corretta"<<endl;
	do{
		cout<<"inserisci: ";
		cin>>scelta1;
	}while(!(scelta1==1||scelta1==3||scelta1==2));
	int posizionegiusta=0;
	vinto==false;
	if(scelta1==3){
			do{
		cout<<"Inserisci quanti tentativi voi fare: ";
		cin>>tentativi;
		}while(tentativi<1||tentativi>numerolettere);
		for(int contatentativi=1;contatentativi<=tentativi&&vinto==false;contatentativi++){
		ifstream inputfile("parola.txt");
		int cgiuste=0;
		string parola=" ",line1=" ";
			cout<<"Inserisci la parola: ";
			cin>>parola;
			for(int i=0; i<numerolettere; i++) {
			getline(inputfile,line1);
			if(parola[i]==line1[0]) {
				cgiuste++;
			}
		}
		inputfile.close();
		if(cgiuste!=numerolettere) {
			cout<<"ha indovinato "<<cgiuste<<"/"<<numerolettere<<" lettere"<<endl;
			system("pause");
		} else {
			cout<<endl<<"HAI INDOVINATO LA PAROLA"<<endl;
			system("pause");
			vinto=true;
		}
	}
}else{ if(scelta1==1){
		system("parola_test.exe");
	}
	return 0;
}
}
}
