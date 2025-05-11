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
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
bool vinto=false;
int c=0;
int tentativi;
bool presenza=false;
int scelta=0,scelta1=0,cgiustev=0,gl=0;
void ScriviParola_4(){
	srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_4.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_4.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_5(){
	srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_5.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_5.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_6(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_6.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_6.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_7(){
	srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_7.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_7.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_8(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_8.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_8.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_9(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_9.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_9.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_10(){
	srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_10.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_10.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_11(){
	srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_11.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_11.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_12(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_12.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_12.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_13(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_13.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_13.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_14(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_14.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_14.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void ScriviParola_15(){
		srand(unsigned(time(NULL))); 
	string line;
	ifstream inputfile("parola_15.txt");
		for(; getline(inputfile,line,';'); c++);
		inputfile.close();
		c/=numerolettere;
		int n1;
				string line5;
				ifstream leggi("parola_15.txt");
					n1 = rand()%c+1;
				for(int j=0;j<=(numerolettere)*n1-1;j++){
					getline(leggi,line5,';');
				}
				string line4[numerolettere]={};
				for(int p=0;p<numerolettere;p++){
					getline(leggi,line4[p],';');
				}
				{
				ofstream outputfile("parola.txt",ios::trunc);
				outputfile.close();
			}
				ofstream outputfile("parola.txt",ios::out);
				for(int j=0;j<numerolettere;j++){
					if(j!=numerolettere){
					outputfile<<line4[j]<<endl;
					}else{
						getline(leggi,line4[j],';');
						outputfile<<line4;
					}
				}
				outputfile.close();
}
void Difficolta_facile(){
	system("single_parola_test.exe");
}
void Difficolta_media(){
		do{
		cout<<"Inserisci quanti tentativi voi fare: ";
		cin>>tentativi;
	}while(tentativi<1||tentativi>(numerolettere*2));
		for(int contatentativi=1;contatentativi<=tentativi&&vinto==false;contatentativi++){
				string lineg;
		ifstream inputfile("parola.txt");
		int cgiuste=0;
		string parola=" ",line1=" ";
		getline(inputfile,line1);
		line1=" ";
			cout<<"Inserisci la parola: ";
			cin>>parola;
			for(int i=0; i<numerolettere; i++) {
			getline(inputfile,line1);
			if(parola[i]==line1[0]) {
				string posizione;
				posizione=to_string(i );
				string parola_1="-11";
				parola_1=parola[i];
				lineg+=parola_1+"$"+" "+posizione+" ; ";
				cgiuste++;
			}
		}
		inputfile.close();
		if(cgiuste!=numerolettere) {
			cout<<"*********************************"<<endl<<"ha indovinato "<<cgiuste<<"/"<<numerolettere<<" : "<<lineg<<" cifre"<<endl<<"le lettere con affianco il dollaro significa che sono nella posiszione giusta."<<endl;
			system("pause");
		} else {
			cout<<"ha indovinato la parola"<<endl;
			system("pause");
			vinto=true;
		}
}
}
void Difficolta_difficile(){
do{
		cout<<"Inserisci quanti tentativi voi fare: ";
		cin>>tentativi;
	}while(tentativi<1||tentativi>numerolettere);
		for(int contatentativi=1;contatentativi<=tentativi&&vinto==false;contatentativi++){
		ifstream inputfile("parola.txt");
		int cgiuste=0;
		string parola=" ",line1=" ";
		getline(inputfile,line1);
		line1=" ";
			cout<<"Inserisci la lettera: ";
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
			cout<<"ha indovinato la parola"<<endl;
			system("pause");
			vinto=true;
		}
	}

}
int main() {
	srand(unsigned(time(NULL))); 
		do {
		cout<<"Inserisci il numero di lettere: ";
		cin>>numerolettere;
	} while(numerolettere<=3||numerolettere>15);
	switch(numerolettere){
		case 4:
			ScriviParola_4();
		break;
		case 5:
			ScriviParola_5();
		break;
		case 6:
			ScriviParola_6();
		break;
		case 7:
			ScriviParola_7();
		break;
		case 8:
			ScriviParola_8();
		break;
		case 9:
			ScriviParola_9();
		break;
		case 10:
			ScriviParola_10();
		break;
		case 11:
			ScriviParola_11();
		break;
		case 12:
			ScriviParola_12();
		break;
		case 13:
			ScriviParola_13();
		break;
		case 14:
			ScriviParola_14();
		break;
		case 15:
			ScriviParola_15();
		break;
		default: 
			cout<<"errore";
			system("pause");
			return 0;
		break;
	}
	cout<<"Decidi la difficolta: "<<endl<<"Facile = 1"<<endl<<"In questa modalita' saprai sostanzialmente tutto, quindi sia le lettere nella posizione scorretta che corretta."<<endl<<"Media = 2"<<endl<<" In questa modalita' saprai quali lettere hai indovinato se e solo se saranno nella posizione giusta"<<endl<<"Difficile = 3"<<endl<<"In questa modalita' saprai soltanto quante lettere hai indovinato se e solo se saranno nella posizione corretta"<<endl;
	do{
		cout<<"inserisci: ";
		cin>>scelta1;
	}while(!(scelta1==1||scelta1==3||scelta1==2));
	int posizionegiusta=0;
	vinto==false;
	switch(scelta1){
	case 1:
		Difficolta_facile();
	break;
	case 2:
		Difficolta_media();
	break;
	case 3:
		Difficolta_difficile();	
	break;
	default:
		cout<<"errore";
		system("pause");
		return 0;
	break;	
	}
	return 0;
}