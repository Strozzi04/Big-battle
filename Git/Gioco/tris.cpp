#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;
// 0 = casella vuota, 1 = X (giocatore 1), 2 = O (giocatore 2)
int Tabellone[3][3]={ {0,0,0},
					  {0,0,0},
					  {0,0,0}
 };
// legge un numero intero senza andare in loop se l'utente scrive una lettera
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
void output(){
	cout<<"ecco il tabellone : "<<endl;
	cout<<"  0 1 2";
	for(int i=0;i<3;i++){
		cout<<endl<<i<<" ";
		for(int j=0;j<3;j++){
			if(Tabellone[i][j]==0){
				cout<<"_ ";
			}else if(Tabellone[i][j]==1){
				cout<<"X ";
			}else{
				cout<<"O ";
			}
		}
	}
	cout<<endl;
}
// fa giocare il giocatore (1 = X, 2 = O)
void mossa(int giocatore){
	cout<<endl<<"giocatore "<<giocatore<<" ("<<(giocatore==1?"X":"O")<<"): "<<endl;
	output();
	int x,y;
	while(true){
		y=leggi_intero("inserisci la coordinata y (riga) : ");
		x=leggi_intero("inserisci la coordinata x (colonna) : ");
		if(x<0||x>2||y<0||y>2){
			cout<<"coordinate non valide, devono essere tra 0 e 2"<<endl;
		}else if(Tabellone[y][x]!=0){
			cout<<"casella gia' occupata, scegline un'altra"<<endl;
		}else{
			break;
		}
	}
	Tabellone[y][x]=giocatore;
}
// controlla se il giocatore ha fatto tris
bool ha_vinto(int g){
	for(int i=0;i<3;i++){
		if(Tabellone[i][0]==g&&Tabellone[i][1]==g&&Tabellone[i][2]==g){//righe
			return true;
		}
		if(Tabellone[0][i]==g&&Tabellone[1][i]==g&&Tabellone[2][i]==g){//colonne
			return true;
		}
	}
	if(Tabellone[0][0]==g&&Tabellone[1][1]==g&&Tabellone[2][2]==g){//diagonale principale
		return true;
	}
	if(Tabellone[0][2]==g&&Tabellone[1][1]==g&&Tabellone[2][0]==g){//diagonale secondaria
		return true;
	}
	return false;
}
// 1 = si continua, 2 = vince il giocatore 1, 3 = vince il giocatore 2, 4 = pareggio
int continuare(){
	if(ha_vinto(1)){
		return 2;
	}
	if(ha_vinto(2)){
		return 3;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(Tabellone[i][j]==0){
				return 1;
			}
		}
	}
	return 4;
}
int main() {
	cout<<"il giocatore 1 sara' la X il 2 la O"<<endl;
	srand(time(NULL));
	int turno=rand()%2+1;
	cout<<"comincia il giocatore "<<turno<<endl;
	int b=1;
	while(b==1){
		mossa(turno);
		b=continuare();
		turno=(turno==1)?2:1;
	}
	cout<<endl;
	if(b==2){
		cout<<"HA VINTO IL GIOCATORE 1"<<endl;
	}else if(b==3){
		cout<<"HA VINTO IL GIOCATORE 2"<<endl;
	}else{
		cout<<"PAREGGIO"<<endl;
	}
	output();
	system("pause");
	return 0;
}
