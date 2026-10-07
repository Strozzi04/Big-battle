#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
// 2048: con le frecce (o W A S D) sposti tutte le tessere. Due tessere con
// lo stesso numero che si scontrano diventano una sola con la somma.
// Dopo ogni mossa compare una nuova tessera (2 o 4). Arriva a 2048!
const int N=4;
const char *FILE_RECORD="2048_record.txt";
int griglia[N][N];
int punti=0;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

int leggi_record(){
	int record=0;
	ifstream inputfile(FILE_RECORD);
	inputfile>>record;
	inputfile.close();
	return record;
}
void salva_record(int record){
	ofstream outputfile(FILE_RECORD,ios::trunc);
	outputfile<<record<<endl;
	outputfile.close();
}
// aggiunge un 2 (90%) o un 4 (10%) in una casella vuota a caso
void nuova_tessera(){
	int vuote[N*N],n=0;
	for(int i=0;i<N*N;i++){
		if(griglia[i/N][i%N]==0){
			vuote[n]=i;
			n++;
		}
	}
	if(n==0){
		return;
	}
	int i=vuote[rand()%n];
	griglia[i/N][i%N]=(rand()%10==0)?4:2;
}
// sposta e unisce una riga verso sinistra; restituisce true se e' cambiato qualcosa
bool sposta_riga(int riga[N]){
	int nuova[N]={0};
	int k=0;
	bool unita=false; // l'ultima tessera messa e' gia' il risultato di un'unione
	for(int i=0;i<N;i++){
		if(riga[i]==0){
			continue;
		}
		if(k>0&&nuova[k-1]==riga[i]&&!unita){
			nuova[k-1]*=2;
			punti+=nuova[k-1];
			unita=true;
		}else{
			nuova[k]=riga[i];
			k++;
			unita=false;
		}
	}
	bool cambiato=false;
	for(int i=0;i<N;i++){
		if(riga[i]!=nuova[i]){
			cambiato=true;
		}
		riga[i]=nuova[i];
	}
	return cambiato;
}
// direzione: 0 = sinistra, 1 = destra, 2 = su, 3 = giu'
bool muovi(int direzione){
	bool cambiato=false;
	for(int a=0;a<N;a++){
		int riga[N];
		// copio la riga/colonna in modo che la mossa sia sempre "verso sinistra"
		for(int b=0;b<N;b++){
			if(direzione==0){riga[b]=griglia[a][b];}
			else if(direzione==1){riga[b]=griglia[a][N-1-b];}
			else if(direzione==2){riga[b]=griglia[b][a];}
			else{riga[b]=griglia[N-1-b][a];}
		}
		if(sposta_riga(riga)){
			cambiato=true;
		}
		for(int b=0;b<N;b++){
			if(direzione==0){griglia[a][b]=riga[b];}
			else if(direzione==1){griglia[a][N-1-b]=riga[b];}
			else if(direzione==2){griglia[b][a]=riga[b];}
			else{griglia[N-1-b][a]=riga[b];}
		}
	}
	return cambiato;
}
bool mosse_possibili(){
	for(int r=0;r<N;r++){
		for(int c=0;c<N;c++){
			if(griglia[r][c]==0){
				return true;
			}
			if(c<N-1&&griglia[r][c]==griglia[r][c+1]){
				return true;
			}
			if(r<N-1&&griglia[r][c]==griglia[r+1][c]){
				return true;
			}
		}
	}
	return false;
}
int massimo(){
	int m=0;
	for(int r=0;r<N;r++){
		for(int c=0;c<N;c++){
			if(griglia[r][c]>m){
				m=griglia[r][c];
			}
		}
	}
	return m;
}
int colore(int v){
	switch(v){
		case 0: return 8;
		case 2: return 15;
		case 4: return 14;
		case 8: return 12;
		case 16: return 13;
		case 32: return 11;
		case 64: return 10;
		case 128: return 9;
		case 256: return 6;
		case 512: return 5;
		case 1024: return 3;
		case 2048: return 224;
		default: return 207;
	}
}
void output(int record){
	system("cls");
	cout<<"2048      Punti: "<<punti<<"   Record: "<<record<<endl<<endl;
	for(int r=0;r<N;r++){
		cout<<"  +------+------+------+------+"<<endl<<"  |";
		for(int c=0;c<N;c++){
			SetConsoleTextAttribute(h,colore(griglia[r][c]));
			if(griglia[r][c]==0){
				cout<<"  .   ";
			}else{
				string s=to_string(griglia[r][c]);
				int spazi=6-s.size();
				cout<<string(spazi/2,' ')<<s<<string(spazi-spazi/2,' ');
			}
			SetConsoleTextAttribute(h,7);
			cout<<"|";
		}
		cout<<endl;
	}
	cout<<"  +------+------+------+------+"<<endl<<endl;
	cout<<"Frecce o W A S D per muovere, N = nuova partita, Q = esci"<<endl;
}
void nuova_partita(){
	for(int r=0;r<N;r++){
		for(int c=0;c<N;c++){
			griglia[r][c]=0;
		}
	}
	punti=0;
	nuova_tessera();
	nuova_tessera();
}
int main(){
	srand(unsigned(time(NULL)));
	int record=leggi_record();
	nuova_partita();
	bool vinto_mostrato=false;
	while(true){
		if(punti>record){
			record=punti;
			salva_record(record);
		}
		output(record);
		if(massimo()>=2048&&!vinto_mostrato){
			vinto_mostrato=true;
			cout<<endl<<"HAI FATTO 2048, HAI VINTO! Puoi continuare a giocare per fare piu' punti."<<endl;
		}
		if(!mosse_possibili()){
			cout<<endl<<"GAME OVER! Non ci sono piu' mosse. Hai fatto "<<punti<<" punti."<<endl;
			cout<<"Premi N per una nuova partita o Q per uscire"<<endl;
		}
		int tasto=_getch();
		if(tasto==0||tasto==224){//frecce
			tasto=_getch();
			if(tasto==72){tasto='w';}
			else if(tasto==80){tasto='s';}
			else if(tasto==75){tasto='a';}
			else if(tasto==77){tasto='d';}
		}
		tasto=tolower(tasto);
		int direzione=-1;
		if(tasto=='a'){direzione=0;}
		else if(tasto=='d'){direzione=1;}
		else if(tasto=='w'){direzione=2;}
		else if(tasto=='s'){direzione=3;}
		else if(tasto=='q'||tasto==EOF||tasto==-1){break;}
		else if(tasto=='n'){
			nuova_partita();
			vinto_mostrato=false;
		}
		if(direzione>=0&&muovi(direzione)){
			nuova_tessera();//la tessera nuova compare solo se la mossa ha spostato qualcosa
		}
	}
	system("cls");
	return 0;
}
