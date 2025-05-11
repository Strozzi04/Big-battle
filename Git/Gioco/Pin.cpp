#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <process.h>
#include <sstream>
#include <windows.h>
using namespace std;
string parola;
string intput_parola={" "};

int main() {
	bool presenza;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 14);
	int scelta=0,scelta1=0,numerolettere=0,cgiustev=0,gl=0;
		int tentativi;
		bool vinto=false;
	string lett,lineg,line2;
	do {
		cout<<"1 = sei tu chi decide il pin"<<endl<<"2 = sei chi indovina il pin"<<endl;
		cout<<"Inserisci: ";
		cin>>scelta;
	} while(!(scelta==1||scelta==2));
		do {
		cout<<"Inserisci il numero di cifre: ";
		cin>>numerolettere;
	} while(numerolettere<=1);
	if(scelta==1) {
		ofstream outputfile("pin.txt",ios::trunc);
		string pin;
		int c=0;
		string line;
			cout<<"inserci il pin: ";
			cin>>pin;
			for(int i=0; i<numerolettere; i++) {
			if(i!=numerolettere) {
				outputfile<<pin[i]<<endl;
			} else {
				outputfile<<pin[i];
			}
		}
		outputfile.close();
		ifstream inputfile("pin.txt");
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
	cout<<"Decidi la difficolta: "<<endl<<"Facile = 1"<<endl<<"In questa modalita' saprai sostanzialmente tutto, quindi sia le cifre nella posizione scorretta che corretta."<<endl<<"Media = 2"<<endl<<" In questa modalita' saprai quali cifre hai indovinato se e solo se saranno nella posizione giusta"<<endl<<"Difficile = 3"<<endl<<"In questa modalita' saprai soltanto quante cifre hai indovinato se e solo se saranno nella posizione corretta"<<endl;
	do{
		cout<<"inserisci: ";
		cin>>scelta1;
	}while(!(scelta1==1||scelta1==3||scelta1==2));
	int posizionegiusta=0;
	if(scelta1==3){
			do{
		cout<<"Inserisci quanti tentativi voi fare: ";
		cin>>tentativi;
	}while(tentativi<1||tentativi>numerolettere);
		for(int contatentativi=1;contatentativi<=tentativi&&vinto==false;contatentativi++){
		ifstream inputfile("pin.txt");
		int cgiuste=0;
		string pin=" ",line1=" ";
		
			cout<<"Inserisci il pin: ";
			cin>>pin;
			for(int i=0; i<numerolettere; i++) {
			getline(inputfile,line1);
			if(pin[i]==line1[0]) {
				cgiuste++;
			}
		}
		inputfile.close();
		if(cgiuste!=numerolettere) {
			cout<<"ha indovinato "<<cgiuste<<"/"<<numerolettere<<" cifre"<<endl;
			system("pause");
		} else {
			cout<<"ha indovinato il pin"<<endl;
			system("pause");
			vinto=true;
		}
	}
}else{ 
if(scelta1==1){
	system("pin_test.exe");
}else{

	do{
		cout<<"Inserisci quanti tentativi voi fare: ";
		cin>>tentativi;
	}while(tentativi<1||tentativi>(numerolettere*2));
		for(int contatentativi=1;contatentativi<=tentativi&&vinto==false;contatentativi++){
				string lineg;
		ifstream inputfile("pin.txt");
		int cgiuste=0;
		string pin=" ",line1=" ";
			cout<<"Inserisci la cifra: ";
			cin>>pin;
			for(int i=0; i<numerolettere; i++) {
			getline(inputfile,line1);
			if(pin[i]==line1[0]) {
				string posizione;
				posizione=to_string(i+1 );
				string pin_1="-11";
				pin_1=pin[i];
				lineg+=pin_1+"$"+" "+posizione+" ; ";
				cgiuste++;
			}
		}
		inputfile.close();
		if(cgiuste!=numerolettere) {
			cout<<"*********************************"<<endl<<"ha indovinato "<<cgiuste<<"/"<<numerolettere<<" : "<<lineg<<" cifre"<<endl<<"le cifre con affianco il dollaro significa che sono nella posiszione giusta."<<endl;
			system("pause");
		} else {
			cout<<"ha indovinato il pin"<<endl;
			system("pause");
			vinto=true;
		}
	}
	return 0;
}
}
}
}