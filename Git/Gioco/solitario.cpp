#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
// SOLITARIO (Klondike): porta tutte le carte nelle 4 fondazioni, una per seme,
// in ordine dall'Asso al Re. Nelle 7 colonne le carte si mettono in ordine
// decrescente alternando rosso e nero; in una colonna vuota va solo un Re.
struct Carta{
	int valore;   // 1 = Asso ... 11 = J, 12 = Q, 13 = K
	int seme;     // 0 = cuori, 1 = quadri, 2 = fiori, 3 = picche
	bool scoperta;
};
vector<Carta> mazzo,scarti;
vector<Carta> colonne[7];
int fondazione[4];      // valore piu' alto messo nella fondazione di ogni seme (0 = vuota)
int pesca_quante=1;     // si pescano 1 o 3 carte alla volta
int mosse=0;
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
bool rossa(const Carta &c){
	return c.seme<2;
}
// stampa la carta con il simbolo del seme (caratteri 3-6 della console: cuori, quadri, fiori, picche)
void stampa(const Carta &c){
	if(!c.scoperta){
		SetConsoleTextAttribute(h,8);
		cout<<"[##]";
		SetConsoleTextAttribute(h,7);
		return;
	}
	const string VALORI[14]={"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	SetConsoleTextAttribute(h,rossa(c)?252:240);//sfondo bianco, rosso o nero
	string v=VALORI[c.valore];
	cout<<(v.size()==1?" ":"")<<v<<(char)(3+c.seme)<<" ";
	SetConsoleTextAttribute(h,7);
}
void stampa_vuota(){
	SetConsoleTextAttribute(h,8);
	cout<<"[  ]";
	SetConsoleTextAttribute(h,7);
}
void nuova_partita(){
	mazzo.clear();
	scarti.clear();
	for(int i=0;i<7;i++){
		colonne[i].clear();
	}
	for(int s=0;s<4;s++){
		fondazione[s]=0;
		for(int v=1;v<=13;v++){
			Carta c={v,s,false};
			mazzo.push_back(c);
		}
	}
	for(int i=(int)mazzo.size()-1;i>0;i--){//mescolo
		int j=rand()%(i+1);
		Carta t=mazzo[i];mazzo[i]=mazzo[j];mazzo[j]=t;
	}
	// colonna i: i+1 carte, solo l'ultima scoperta
	for(int i=0;i<7;i++){
		for(int j=0;j<=i;j++){
			Carta c=mazzo.back();
			mazzo.pop_back();
			c.scoperta=(j==i);
			colonne[i].push_back(c);
		}
	}
	mosse=0;
}
void output(){
	system("cls");
	cout<<"SOLITARIO   mosse: "<<mosse<<endl<<endl;
	cout<<"  Mazzo  Scarti";
	cout<<"        Fondazioni"<<endl<<"  ";
	if(mazzo.empty()){
		stampa_vuota();
	}else{
		Carta dorso={1,0,false};
		stampa(dorso);
	}
	cout<<"   ";
	// degli scarti si vedono le ultime 3 carte, si gioca solo l'ultima
	int da=max(0,(int)scarti.size()-(pesca_quante==3?3:1));
	int mostrate=0;
	for(int i=da;i<(int)scarti.size();i++){
		stampa(scarti[i]);
		mostrate++;
	}
	if(scarti.empty()){
		stampa_vuota();
		mostrate=1;
	}
	cout<<string((3-mostrate)*4+5,' ');
	for(int s=0;s<4;s++){
		if(fondazione[s]==0){
			SetConsoleTextAttribute(h,8);
			cout<<"[ "<<(char)(3+s)<<"]";
			SetConsoleTextAttribute(h,7);
		}else{
			Carta c={fondazione[s],s,true};
			stampa(c);
		}
		cout<<" ";
	}
	cout<<"  ("<<mazzo.size()<<" nel mazzo)"<<endl<<endl;
	cout<<"   ";
	for(int i=0;i<7;i++){
		cout<<"  "<<i+1<<"  ";
	}
	cout<<endl;
	int altezza=0;
	for(int i=0;i<7;i++){
		altezza=max(altezza,(int)colonne[i].size());
	}
	for(int r=0;r<max(altezza,1);r++){
		cout<<"   ";
		for(int i=0;i<7;i++){
			if(r<(int)colonne[i].size()){
				stampa(colonne[i][r]);
			}else if(r==0){
				stampa_vuota();
			}else{
				cout<<"    ";
			}
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
// la carta c si puo' mettere sopra la colonna i?
bool va_su_colonna(const Carta &c,int i){
	if(colonne[i].empty()){
		return c.valore==13;
	}
	const Carta &sotto=colonne[i].back();
	return sotto.scoperta&&rossa(sotto)!=rossa(c)&&sotto.valore==c.valore+1;
}
bool va_in_fondazione(const Carta &c){
	return fondazione[c.seme]==c.valore-1;
}
void scopri_ultima(int i){
	if(!colonne[i].empty()){
		colonne[i].back().scoperta=true;
	}
}
void pesca(){
	if(mazzo.empty()){
		if(scarti.empty()){
			cout<<"non ci sono piu' carte da pescare"<<endl;
			system("pause");
			return;
		}
		// gli scarti tornano nel mazzo coperti
		while(!scarti.empty()){
			Carta c=scarti.back();
			scarti.pop_back();
			c.scoperta=false;
			mazzo.push_back(c);
		}
	}else{
		for(int k=0;k<pesca_quante&&!mazzo.empty();k++){
			Carta c=mazzo.back();
			mazzo.pop_back();
			c.scoperta=true;
			scarti.push_back(c);
		}
	}
	mosse++;
}
// destinazione: 1-7 = colonna, 8 = fondazione
int chiedi_destinazione(){
	int d;
	do{
		d=leggi_intero("dove? colonna 1-7, fondazione = 8: ");
	}while(d<1||d>8);
	return d;
}
string sposta_da_scarti(){
	if(scarti.empty()){
		return "non ci sono carte negli scarti";
	}
	Carta c=scarti.back();
	int d=chiedi_destinazione();
	if(d==8){
		if(!va_in_fondazione(c)){
			return "questa carta non puo' andare nella fondazione";
		}
		fondazione[c.seme]=c.valore;
	}else{
		if(!va_su_colonna(c,d-1)){
			return "questa carta non puo' andare su quella colonna";
		}
		colonne[d-1].push_back(c);
	}
	scarti.pop_back();
	mosse++;
	return "";
}
string sposta_da_colonna(){
	int da=leggi_intero("da quale colonna (1-7)? ");
	if(da<1||da>7){
		return "colonna non valida";
	}
	vector<Carta> &col=colonne[da-1];
	if(col.empty()){
		return "la colonna e' vuota";
	}
	int d=chiedi_destinazione();
	if(d==8){
		if(!va_in_fondazione(col.back())){
			return "questa carta non puo' andare nella fondazione";
		}
		fondazione[col.back().seme]=col.back().valore;
		col.pop_back();
	}else{
		if(d==da){
			return "la colonna di partenza e di arrivo e' la stessa";
		}
		// cerco la carta scoperta piu' in alto che si puo' spostare insieme alle carte sopra
		int parte=-1;
		for(int k=0;k<(int)col.size();k++){
			if(col[k].scoperta&&va_su_colonna(col[k],d-1)){
				parte=k;
				break;
			}
		}
		if(parte<0){
			return "nessuna carta di questa colonna puo' andare su quella colonna";
		}
		for(int k=parte;k<(int)col.size();k++){
			colonne[d-1].push_back(col[k]);
		}
		col.erase(col.begin()+parte,col.end());
	}
	scopri_ultima(da-1);
	mosse++;
	return "";
}
string sposta_da_fondazione(){
	int s=leggi_intero("quale seme? cuori = 1, quadri = 2, fiori = 3, picche = 4: ");
	if(s<1||s>4){
		return "seme non valido";
	}
	if(fondazione[s-1]==0){
		return "quella fondazione e' vuota";
	}
	int d=leggi_intero("su quale colonna (1-7)? ");
	if(d<1||d>7){
		return "colonna non valida";
	}
	Carta c={fondazione[s-1],s-1,true};
	if(!va_su_colonna(c,d-1)){
		return "questa carta non puo' andare su quella colonna";
	}
	colonne[d-1].push_back(c);
	fondazione[s-1]--;
	mosse++;
	return "";
}
// mette nelle fondazioni tutte le carte possibili; restituisce quante ne ha spostate
int automatico(){
	int spostate=0;
	bool ancora=true;
	while(ancora){
		ancora=false;
		if(!scarti.empty()&&va_in_fondazione(scarti.back())){
			fondazione[scarti.back().seme]=scarti.back().valore;
			scarti.pop_back();
			ancora=true;
			spostate++;
		}
		for(int i=0;i<7;i++){
			if(!colonne[i].empty()&&va_in_fondazione(colonne[i].back())){
				fondazione[colonne[i].back().seme]=colonne[i].back().valore;
				colonne[i].pop_back();
				scopri_ultima(i);
				ancora=true;
				spostate++;
			}
		}
	}
	mosse+=spostate;
	return spostate;
}
bool vinto(){
	for(int s=0;s<4;s++){
		if(fondazione[s]!=13){
			return false;
		}
	}
	return true;
}
int main(){
	srand(unsigned(time(NULL)));
	cout<<"SOLITARIO"<<endl<<"Porta tutte le carte nelle fondazioni, dall'Asso al Re per ogni seme."<<endl<<endl;
	bool ancora=true;
	while(ancora){
		int p;
		do{
			p=leggi_intero("Quante carte vuoi pescare alla volta? 1 (facile) o 3 (difficile): ");
		}while(p!=1&&p!=3);
		pesca_quante=p;
		nuova_partita();
		time_t inizio=time(NULL);
		bool arreso=false;
		while(!vinto()){
			output();
			cout<<"pesca = 1, sposta dagli scarti = 2, sposta da una colonna = 3,"<<endl
				<<"sposta dalla fondazione = 4, metti in fondazione tutto il possibile = 5, arrenditi = 0"<<endl;
			int azione;
			do{
				azione=leggi_intero("inserisci: ");
			}while(azione<0||azione>5);
			string errore="";
			if(azione==0){
				arreso=true;
				break;
			}else if(azione==1){
				pesca();
			}else if(azione==2){
				errore=sposta_da_scarti();
			}else if(azione==3){
				errore=sposta_da_colonna();
			}else if(azione==4){
				errore=sposta_da_fondazione();
			}else if(automatico()==0){
				errore="nessuna carta puo' andare nelle fondazioni";
			}
			if(errore!=""){
				cout<<errore<<endl;
				system("pause");
			}
		}
		output();
		if(arreso){
			cout<<"Ti sei arreso. Hai messo nelle fondazioni "<<fondazione[0]+fondazione[1]+fondazione[2]+fondazione[3]<<" carte su 52."<<endl;
		}else{
			cout<<"HAI VINTO! "<<mosse<<" mosse in "<<(long)(time(NULL)-inizio)<<" secondi."<<endl;
		}
		int scelta;
		do{
			scelta=leggi_intero("Vuoi giocare ancora? si = 1, no = 0: ");
		}while(scelta!=0&&scelta!=1);
		ancora=(scelta==1);
		system("cls");
	}
	return 0;
}
