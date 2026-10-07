#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
// SNAKE: il serpente si muove da solo, si cambia direzione con le frecce o
// con W A S D. Mangiando la mela (@) si allunga e si guadagnano punti.
// Si perde toccando il bordo o il proprio corpo. P = pausa, Q = esci.
const int LARGHEZZA=30;
const int ALTEZZA=18;
const char *FILE_RECORD="snake_record.txt";
struct Punto{
	int x,y;
};
deque<Punto> serpente; // serpente.front() e' la testa
Punto mela;
int dx=1,dy=0;         // direzione attuale (parte verso destra)
int punti=0;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

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
void vai_a(int x,int y){
	COORD c;
	c.X=(SHORT)x;
	c.Y=(SHORT)y;
	SetConsoleCursorPosition(h,c);
}
void nascondi_cursore(bool nascondi){
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(h,&info);
	info.bVisible=!nascondi;
	SetConsoleCursorInfo(h,&info);
}
// disegna un carattere nella cella (x,y) del campo (il bordo occupa la riga/colonna 0)
void disegna(int x,int y,char c,int colore){
	vai_a((x+1)*2,y+1);
	SetConsoleTextAttribute(h,colore);
	cout<<c<<' ';
	SetConsoleTextAttribute(h,7);
}
bool sul_serpente(int x,int y){
	for(int i=0;i<(int)serpente.size();i++){
		if(serpente[i].x==x&&serpente[i].y==y){
			return true;
		}
	}
	return false;
}
// mette la mela in una casella libera; false se il campo e' pieno
bool nuova_mela(){
	if((int)serpente.size()>=LARGHEZZA*ALTEZZA){
		return false;
	}
	do{
		mela.x=rand()%LARGHEZZA;
		mela.y=rand()%ALTEZZA;
	}while(sul_serpente(mela.x,mela.y));
	disegna(mela.x,mela.y,'@',12);
	return true;
}
void disegna_campo(){
	system("cls");
	SetConsoleTextAttribute(h,8);
	for(int x=0;x<LARGHEZZA+2;x++){
		vai_a(x*2,0);
		cout<<"# ";
		vai_a(x*2,ALTEZZA+1);
		cout<<"# ";
	}
	for(int y=1;y<=ALTEZZA;y++){
		vai_a(0,y);
		cout<<"#";
		vai_a((LARGHEZZA+1)*2,y);
		cout<<"#";
	}
	SetConsoleTextAttribute(h,7);
}
void scrivi_punti(int record){
	vai_a(0,ALTEZZA+2);
	cout<<"Punti: "<<punti<<"   Record: "<<record<<"   Lunghezza: "<<serpente.size()<<"      "<<endl;
	cout<<"Frecce o W A S D per muoverti, P = pausa, Q = esci";
}
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
// legge i tasti premuti; restituisce false se il giocatore vuole uscire
bool leggi_tasti(int &nuovo_dx,int &nuovo_dy){
	while(_kbhit()){
		int tasto=_getch();
		if(tasto==0||tasto==224){//frecce
			tasto=_getch();
			if(tasto==72){tasto='w';}
			else if(tasto==80){tasto='s';}
			else if(tasto==75){tasto='a';}
			else if(tasto==77){tasto='d';}
		}
		tasto=tolower(tasto);
		int ndx=nuovo_dx,ndy=nuovo_dy;
		if(tasto=='w'){ndx=0;ndy=-1;}
		else if(tasto=='s'){ndx=0;ndy=1;}
		else if(tasto=='a'){ndx=-1;ndy=0;}
		else if(tasto=='d'){ndx=1;ndy=0;}
		else if(tasto=='q'){return false;}
		else if(tasto=='p'){
			vai_a(0,ALTEZZA+4);
			cout<<"PAUSA: premi un tasto per continuare";
			_getch();
			vai_a(0,ALTEZZA+4);
			cout<<"                                    ";
		}
		// non si puo' tornare indietro sul proprio corpo
		if(!(ndx==-dx&&ndy==-dy)){
			nuovo_dx=ndx;
			nuovo_dy=ndy;
		}
	}
	return true;
}
int main(){
	srand(unsigned(time(NULL)));
	cout<<"SNAKE"<<endl<<"Mangia le mele (@) senza toccare il bordo o la tua coda."<<endl;
	int livello;
	do{
		livello=leggi_intero("Scegli la velocita': lento = 1, normale = 2, veloce = 3: ");
	}while(livello<1||livello>3);
	int attesa=(livello==1)?160:(livello==2)?110:70;
	int record=leggi_record();
	bool ancora=true;
	while(ancora){
		serpente.clear();
		for(int i=0;i<3;i++){
			Punto p={LARGHEZZA/2-i,ALTEZZA/2};
			serpente.push_back(p);
		}
		dx=1;
		dy=0;
		punti=0;
		nascondi_cursore(true);
		disegna_campo();
		for(int i=0;i<(int)serpente.size();i++){
			disegna(serpente[i].x,serpente[i].y,i==0?'O':'o',10);
		}
		nuova_mela();
		scrivi_punti(record);
		bool vivo=true;
		bool uscito=false;
		bool vinto=false;
		while(vivo){
			Sleep(dy!=0?attesa*4/3:attesa);//in verticale i caratteri sono piu' alti
			int nuovo_dx=dx,nuovo_dy=dy;
			if(!leggi_tasti(nuovo_dx,nuovo_dy)){
				uscito=true;
				break;
			}
			dx=nuovo_dx;
			dy=nuovo_dy;
			Punto testa={serpente.front().x+dx,serpente.front().y+dy};
			bool mangia=(testa.x==mela.x&&testa.y==mela.y);
			// se non mangia la coda si sposta, quindi la sua casella si libera
			Punto coda=serpente.back();
			bool sulla_coda=(!mangia&&testa.x==coda.x&&testa.y==coda.y);
			if(testa.x<0||testa.x>=LARGHEZZA||testa.y<0||testa.y>=ALTEZZA||(sul_serpente(testa.x,testa.y)&&!sulla_coda)){
				vivo=false;
				break;
			}
			if(!mangia){
				serpente.pop_back();
				disegna(coda.x,coda.y,' ',7);
			}
			disegna(serpente.front().x,serpente.front().y,'o',10);
			serpente.push_front(testa);
			disegna(testa.x,testa.y,'O',10);
			if(mangia){
				punti+=10*livello;
				if(!nuova_mela()){
					vinto=true;
					vivo=false;
				}
			}
			scrivi_punti(record);
		}
		nascondi_cursore(false);
		vai_a(0,ALTEZZA+4);
		if(vinto){
			cout<<"HAI RIEMPITO TUTTO IL CAMPO, HAI VINTO!"<<endl;
		}else if(!uscito){
			cout<<"GAME OVER! Hai fatto "<<punti<<" punti"<<endl;
		}
		if(punti>record){
			record=punti;
			salva_record(record);
			cout<<"NUOVO RECORD!"<<endl;
		}
		if(uscito){
			break;
		}
		while(_kbhit()){
			_getch();
		}
		int scelta;
		do{
			scelta=leggi_intero("Vuoi giocare ancora? si = 1, no = 0: ");
		}while(scelta!=0&&scelta!=1);
		ancora=(scelta==1);
	}
	system("cls");
	return 0;
}
