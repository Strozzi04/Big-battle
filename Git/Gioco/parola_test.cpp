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
#include <cctype> 
using namespace std;
//srand(unsigned(time(NULL))); 
//n1 = rand()%10;
//SetConsoleTextAttribute(h, 14);
string parola;
string intput_parola={" "};
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
int c_int_p[26]={0};
int c_ver_p[26]={0};
int main(){
int numerolettere;
bool vinto=false;
		cout<<"sappi che in questa modalita' le lettere indovianate nella posizione corretta saranno indicate in ";
		SetConsoleTextAttribute(h, 2);
		cout<<" verde ";
		SetConsoleTextAttribute(h, 7);
		cout<<" e quelle nella posizione scorretta in ";
		SetConsoleTextAttribute(h, 14);
		cout<<" giallo "<<endl<<endl;
		SetConsoleTextAttribute(h, 7);
			cout<<"Inserisci il numero delle lettere: ";
		cin>>numerolettere;
			string lettere_pos_errata[numerolettere];
			int tentativi;
			vinto=false;
			bool fatto=false;
			int cgiustev=0;
			string line1;
			string line;
			string lettere_nella_posizione_corretta;
			string lettere_posiszione_scorretta;
			do{
				cout<<endl<<"Inserisci quanti tentativi voi fare: ";
				cin>>tentativi;
			}while(tentativi<1);
			for(int contatentativi=0;contatentativi<tentativi&&vinto==false;contatentativi++){       
					int c_int2_p[26]={0};
				for(int k=0;k<26;k++){
				 c_int_p[k]={0};  
				 c_ver_p[k]={0}; 
				 c_int2_p[k]={0};
			}
			//lettere_pos_errata[numerolettere]={NULL};  
				parola={" "};           
			ifstream inputfile("parola.txt");
			for(int i=0;i<numerolettere;i++){
				getline(inputfile,line1);
				char let=line1[0];
				parola[i]=let;
				line1=" ";
			}
				inputfile.close();
				string lettere_nella_posizione_corretta=" ",lettere_posizione_scorretta=" ";
				intput_parola={" "};
				cout<<endl<<"inserisci la parola: ";
				//fatto=false;
				//presenza=false;
				cin>>intput_parola;
				for(int i=0; i<numerolettere; i++){
			if(parola[i]==intput_parola[i]){
				string posizione=" ";
				posizione=to_string(i+1 );
				string g=" -11  ";
				g=intput_parola[i];
				lettere_nella_posizione_corretta+=g+"$"+" "+posizione+" "+";"+" ";
				cgiustev++;	
				parola[i]='0';
				intput_parola[i]='1';
				posizione=" ";
			}}
			for(int u=0;u<numerolettere;u++){
				char ch = parola[u];
				int indice=ch-'a';
				c_ver_p[indice]++;
				}
				for(int b=0;b<numerolettere;b++){
				for(int j=0;j<numerolettere;j++){
					if(parola[j]==intput_parola[b]&&j!=b){
								char ch = parola[j];
								int indice=ch-'a';
						c_int2_p[indice]++;
						if(	c_int2_p[indice]>c_ver_p[indice]){
						}else{
							string f="-11";
							f=intput_parola[b];
					lettere_posizione_scorretta+=f+" ; ";
				}
					}
				}
			}
			if(cgiustev!=numerolettere) {
			cout<<endl<<"*********************************"<<endl;
			cout<<"ha indovinato "<<cgiustev<<"/"<<numerolettere<<endl;
			SetConsoleTextAttribute(h, 2);
			cout<<":"<<lettere_nella_posizione_corretta<<endl;
			SetConsoleTextAttribute(h, 7);
			cout<<"nella parola ci sono anche:"<<endl;
			SetConsoleTextAttribute(h, 14);
			cout<<lettere_posizione_scorretta;
			cout<<endl;
			SetConsoleTextAttribute(h, 7);
			system("pause");
		} else {
			cout<<"ha indovinato la parola"<<endl;
			system("pause");
			vinto=true;
		}
		cgiustev=0;
	}
}