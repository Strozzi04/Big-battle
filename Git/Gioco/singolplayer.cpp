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
int numerolettere=0;
void Creazione_Pin(){
	int lettera;
	ofstream outputfile("pin.txt",ios::trunc);
	srand(unsigned(time(NULL))); 
	for(int i=0; i<numerolettere; i++) {
			lettera = rand()%10;
			if(i!=numerolettere) {
				outputfile<<lettera<<endl;
			} else {
				outputfile<<lettera;
			}
		}
				outputfile.close();	
}
int main() {
	//dichiarazione variabili e comandi utili
		bool presenza;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(h, 14);
	int scelta=0,scelta1=0,cgiustev=0,gl=0;
		int tentativi;
		bool vinto=false;
	string lett,lineg,line2;
		//n1 = rand()%10;
		int c=0;
		string line;
	do{
		cout<<"Da quante cifre deve essere il pin?"<<endl;
		cin>>numerolettere;
	}while(numerolettere<3);
		Creazione_Pin();
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
			for(int i=1; i<=numerolettere; i++) {
			getline(inputfile,line1);
			if(pin[i]==line1[0]) {
				cgiuste++;
			}
		}
		inputfile.close();
		if(cgiuste!=numerolettere) {
			cout<<"ha indovinato "<<cgiuste<<"/"<<numerolettere<<" lettere"<<endl;
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
			cout<<"Inserisci il pin: ";
			cin>>pin;
			for(int i=0; i<numerolettere; i++) {
			getline(inputfile,line1);
			if(pin[i]==line1[0]) {
				string posizione;
				posizione=to_string(i );
				string pin_2="-11";
				pin_2=pin[i];
				lineg+=pin_2+"$"+" "+posizione+" ; ";
				cgiuste++;
			}
		}
		inputfile.close();
		if(cgiuste!=numerolettere) {
			cout<<endl<<"*********************************"<<endl<<"ha indovinato "<<cgiuste<<"/"<<numerolettere<<" : "<<lineg<<" cifre"<<endl<<"le cifre con affianco il dollaro significa che sono nella posiszione giusta."<<endl;
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
