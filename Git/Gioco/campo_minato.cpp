#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
// CAMPO MINATO: scopri tutte le caselle senza mine. Ogni numero dice quante
// mine ci sono nelle 8 caselle intorno. Con la bandiera segni dove pensi che
// ci sia una mina. La prima casella scoperta non e' mai una mina.
const int MAX=30;
int righe,colonne,mine;
bool mina[MAX][MAX];
bool scoperta[MAX][MAX];
bool bandiera[MAX][MAX];
int vicine[MAX][MAX];  // numero di mine nelle caselle intorno
bool mine_piazzate=false;
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
bool dentro(int y,int x){
	return y>=0&&y<righe&&x>=0&&x<colonne;
}
// le mine vengono messe dopo la prima mossa, lontano dalla casella scelta
void piazza_mine(int py,int px){
	int messe=0;
	// se il campo e' molto pieno basta tenere libera solo la prima casella
	bool zona_libera=(righe*colonne-mine)>=9;
	while(messe<mine){
		int y=rand()%righe;
		int x=rand()%colonne;
		bool vicino=zona_libera?(abs(y-py)<=1&&abs(x-px)<=1):(y==py&&x==px);
		if(!mina[y][x]&&!vicino){
			mina[y][x]=true;
			messe++;
		}
	}
	for(int y=0;y<righe;y++){
		for(int x=0;x<colonne;x++){
			vicine[y][x]=0;
			for(int a=-1;a<=1;a++){
				for(int b=-1;b<=1;b++){
					if(dentro(y+a,x+b)&&mina[y+a][x+b]){
						vicine[y][x]++;
					}
				}
			}
		}
	}
	mine_piazzate=true;
}
// scopre la casella; se e' uno 0 scopre anche quelle intorno
void scopri(int y,int x){
	if(!dentro(y,x)||scoperta[y][x]||bandiera[y][x]){
		return;
	}
	scoperta[y][x]=true;
	if(vicine[y][x]==0&&!mina[y][x]){
		for(int a=-1;a<=1;a++){
			for(int b=-1;b<=1;b++){
				scopri(y+a,x+b);
			}
		}
	}
}
bool vinto(){
	for(int y=0;y<righe;y++){
		for(int x=0;x<colonne;x++){
			if(!mina[y][x]&&!scoperta[y][x]){
				return false;
			}
		}
	}
	return true;
}
int bandiere_messe(){
	int c=0;
	for(int y=0;y<righe;y++){
		for(int x=0;x<colonne;x++){
			if(bandiera[y][x]){
				c++;
			}
		}
	}
	return c;
}
// mostra_tutto = true alla fine della partita (si vedono tutte le mine)
void output(bool mostra_tutto){
	const int COLORI[9]={7,9,10,12,1,4,3,13,8};
	cout<<endl<<"    ";
	for(int x=0;x<colonne;x++){
		cout<<(x<10?" ":"")<<x<<" ";
	}
	cout<<endl;
	for(int y=0;y<righe;y++){
		cout<<(y<10?" ":"")<<y<<"  ";
		for(int x=0;x<colonne;x++){
			if(bandiera[y][x]&&!(mostra_tutto&&!mina[y][x])){
				SetConsoleTextAttribute(h,14);
				cout<<" F ";
			}else if(mostra_tutto&&bandiera[y][x]){//bandiera sbagliata
				SetConsoleTextAttribute(h,13);
				cout<<" X ";
			}else if(mina[y][x]&&(scoperta[y][x]||mostra_tutto)){
				SetConsoleTextAttribute(h,scoperta[y][x]?192:12);
				cout<<" * ";
			}else if(!scoperta[y][x]){
				SetConsoleTextAttribute(h,8);
				cout<<" # ";
			}else if(vicine[y][x]==0){
				cout<<" . ";
			}else{
				SetConsoleTextAttribute(h,COLORI[vicine[y][x]]);
				cout<<" "<<vicine[y][x]<<" ";
			}
			SetConsoleTextAttribute(h,7);
		}
		cout<<endl;
	}
	cout<<endl<<"Mine: "<<mine<<"   Bandiere: "<<bandiere_messe()<<endl;
}
void nuova_partita(){
	cout<<"Scegli la difficolta':"<<endl
		<<"Facile    = 1 (9 x 9, 10 mine)"<<endl
		<<"Media     = 2 (12 x 16, 30 mine)"<<endl
		<<"Difficile = 3 (16 x 20, 60 mine)"<<endl
		<<"Personalizzata = 4"<<endl;
	int scelta;
	do{
		scelta=leggi_intero("inserisci: ");
	}while(scelta<1||scelta>4);
	if(scelta==1){righe=9;colonne=9;mine=10;}
	else if(scelta==2){righe=12;colonne=16;mine=30;}
	else if(scelta==3){righe=16;colonne=20;mine=60;}
	else{
		do{
			righe=leggi_intero("numero di righe (da 5 a 30): ");
		}while(righe<5||righe>MAX);
		do{
			colonne=leggi_intero("numero di colonne (da 5 a 30): ");
		}while(colonne<5||colonne>MAX);
		do{
			mine=leggi_intero("numero di mine (da 1 a "+to_string(righe*colonne-1)+"): ");
		}while(mine<1||mine>righe*colonne-1);
	}
	for(int y=0;y<MAX;y++){
		for(int x=0;x<MAX;x++){
			mina[y][x]=false;
			scoperta[y][x]=false;
			bandiera[y][x]=false;
			vicine[y][x]=0;
		}
	}
	mine_piazzate=false;
}
int main(){
	srand(unsigned(time(NULL)));
	cout<<"CAMPO MINATO"<<endl<<"Scopri tutte le caselle senza mine. I numeri dicono quante mine ci sono intorno."<<endl<<endl;
	bool ancora=true;
	while(ancora){
		nuova_partita();
		time_t inizio=time(NULL);
		bool finita=false,esploso=false;
		while(!finita){
			system("cls");
			output(false);
			int azione;
			do{
				azione=leggi_intero("scopri = 1, bandiera (metti/togli) = 2, arrenditi = 0: ");
			}while(azione<0||azione>2);
			if(azione==0){
				esploso=true;
				break;
			}
			int y=leggi_intero("inserisci la coordinata y (riga): ");
			int x=leggi_intero("inserisci la coordinata x (colonna): ");
			string errore="";
			if(!dentro(y,x)){
				errore="coordinate non valide";
			}else if(scoperta[y][x]){
				errore="casella gia' scoperta";
			}else if(azione==1&&bandiera[y][x]){
				errore="su questa casella c'e' una bandiera, toglila prima di scoprirla";
			}
			if(errore!=""){
				//si torna alla scelta dell'azione
				cout<<errore<<endl;
				system("pause");
				continue;
			}
			if(azione==2){
				bandiera[y][x]=!bandiera[y][x];
				continue;
			}
			if(!mine_piazzate){
				piazza_mine(y,x);
				inizio=time(NULL);
			}
			if(mina[y][x]){
				scoperta[y][x]=true;
				esploso=true;
				finita=true;
			}else{
				scopri(y,x);
				finita=vinto();
			}
		}
		system("cls");
		if(!mine_piazzate){//arreso prima di iniziare
			piazza_mine(0,0);
		}
		output(true);
		if(esploso){
			cout<<"BOOM! Hai preso una mina, hai perso."<<endl;
		}else{
			cout<<"HAI VINTO! Hai scoperto tutte le caselle in "<<(long)(time(NULL)-inizio)<<" secondi."<<endl;
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
