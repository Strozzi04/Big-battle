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
#include <cstdlib>
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
				getline(intputfile,barca);
				Tabellone_2_attacco[i][j]=barca;
			}
		}
		intputfile.close();
	}
		ifstream intputfile("tab_att_1.txt");
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				getline(intputfile,barca);
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
	void giocatore_1(){
		int scelta;
		int x,y;
			cout<<endl<<"Giocatore 1: "<<endl;
		do{
			cout<<"vuoi attaccare = 1"<<endl<<"vuoi vedere il tabellone = 2"<<endl<<"inserisci: ";
			cin>>scelta;
		}while(!(scelta==1||scelta==2));
		if(scelta==1){
		Output_1();
		do{
		cout<<"inserisci la coordinata y:";
		cin>>y;
		cout<<"inserisci la coordinata x:";
		cin>>x;
		}while((x<0||x>(N-1))||(y<0||y>(N-1)));
		if(Tabellone_2[y][x]=="1"){
			Tabellone_1_attacco[y][x]="2";
			Tabellone_2[y][x]="2";
			cout<<"colpito"<<endl;
			string pin;
			ifstream intputfile("tabellone_2.txt");
			getline(intputfile,pin);
			intputfile.close();
			ofstream outputfile("tabellone_2.txt",ios::trunc);
			outputfile<<pin<<endl;
			for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        outputfile<<Tabellone_2[i][j]<<endl;
    }
}
    outputfile.close();
		}else{
			cout<<"colpo nullo"<<endl;
			Tabellone_1_attacco[y][x]="3";
		}
		}else{
			system("tabellone.exe");
			system("pause");
			system("cls");
		}
		ofstream outputfile("tab_att_2.txt",ios::trunc);
		for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
        outputfile<<Tabellone_2_attacco[i][j]<<endl;
    }
}
		 outputfile.close();
	}
	
	void giocatore_2(){
		int scelta;
		int x,y;
		cout<<endl<<"Giocatore 2: "<<endl;
		do{
			cout<<"vuoi attaccare = 1"<<endl<<"vuoi vedere il tabellone = 2"<<endl<<"inserisci: ";
			cin>>scelta;
		}while(!(scelta==1||scelta==2));
		if(scelta==1){
		Output_2();
		do{
		cout<<"inserisci la coordinata y:";
		cin>>y;
		cout<<"inserisci la coordinata x: ";
		cin>>x;
		}while((x<0||x>(N-1))||(y<0||y>(N-1)));
		if(Tabellone_1[y][x]=="1"){
			Tabellone_1[y][x]="2";
			Tabellone_2_attacco[y][x]="2";
			cout<<"colpito"<<endl;
			string pin;
			ifstream intputfile("tabellone_1.txt");
			getline(intputfile,pin);
			intputfile.close();
			ofstream outputfile("tabellone_1.txt",ios::trunc);
			outputfile<<pin<<endl;
			for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        outputfile<<Tabellone_1[i][j]<<endl;
    }
}
    outputfile.close();
		}else{
			cout<<"colpo nullo"<<endl;
				Tabellone_2_attacco[y][x]="3";
		}
		}else{
			system("tabellone2.exe");
			system("pause");
			system("cls");
		}
		ofstream outputfile("tab_att_2.txt",ios::trunc);
		for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
        outputfile<<Tabellone_2_attacco[i][j]<<endl;
    }
}
		 outputfile.close();
		
	}
int main() {
	int pos_barche;
	string pin;
	do{
	cout<<"hai gia posizionato le barche? si = 1, no = 0"<<endl<<"inserisci: ";
	cin>>pos_barche;
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
   cout<<"Avete gia comiciato ? si = 1 no = 0: ";
   cin>>a;
}while(!(a==1||a==0));
   if(a==0){
   	riempi();
   }else{
   	riempi_1();
   }
   int continua=continuare();
	while(continua==1){
	giocatore_1();
	giocatore_2();
	continua=continuare();
	}
	cout<<endl<<"PARTITA FINITA : "<<endl<<"Tabellone giocatore 1: "<<endl;
	Output_1();
	cout<<endl<<"Tabellone giocatore 2: "<<endl;
	Output_2();
	system("pause");
	return 0;
}