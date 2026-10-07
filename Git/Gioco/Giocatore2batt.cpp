#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;
const int N=10;
const char *NOME_FILE="tabellone_2.txt";
int Tabellone [N][N] = {};
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
void OutputTabellone(){
	char a=219;
	cout<<"ecco il tabellone : "<<endl;
	cout<<"  ";
	for(int k=0;k<=(N-1);k++)
			{
				cout<<k<<" ";
			}
	for(int i=0;i<N;i++){
		cout<<endl<<i<<" ";
		for(int j=0;j<N;j++){
			if(Tabellone[i][j]==0){
				cout<<"_"<<" ";
			}else{
				cout<<a<<" ";
			}
		}
	}
	cout<<endl;
}
// controlla che la barca stia dentro il tabellone e non si sovrapponga ad altre
bool PuoiPosizionare(int x,int y,int lunghezza,int orientamento){
	for(int i=0;i<lunghezza;i++){
		int r=y,c=x;
		if(orientamento==2){//orizzontale
			c=x+i;
		}else{//verticale
			r=y+i;
		}
		if(r<0||r>=N||c<0||c>=N||Tabellone[r][c]!=0){
			return false;
		}
	}
	return true;
}
void Barca(int lunghezza){
	int orientamento;
	do{
		orientamento=leggi_intero("vuoi metterla in verticale = 1 o in orizzontale = 2 :");
	}while(orientamento!=1&&orientamento!=2);
	OutputTabellone();
	cout<<endl;
	int x=0,y=0;
	while(true){
		y=leggi_intero("inserisci la coordinata y della barca: ");
		x=leggi_intero("inserisci la coordinata x della barca: ");
		if(PuoiPosizionare(x,y,lunghezza,orientamento)){
			break;
		}
		cout<<"la barca esce dal tabellone o si sovrappone a un'altra, riprova"<<endl;
	}
	for(int i=0;i<lunghezza;i++){
		if(orientamento==2){//orizzontale
			Tabellone[y][x+i]=1;
		}else{//verticale
			Tabellone[y+i][x]=1;
		}
	}
	OutputTabellone();
}
int main() {
	int pin;
	do{
		pin=leggi_intero("Inserisci il pin (min 5 cifre):");
	}while((pin/10000)<1);
	bool piazzata[5]={false};
	for(int i=0;i<4;i++){
		int barca=leggi_intero("inserisci quale barca vuoi piazzare: \nbarca da 2 = 1\nbarca da 3 = 2\nbarca da 4 = 3\nbarca da 5 = 4\ninserisci: ");
		if(barca<1||barca>4){
			cout<<"errore, scelta non valida"<<endl;
			i--;
		}else if(piazzata[barca]){
			cout<<"hai gia' piazzato questa barca"<<endl;
			i--;
		}else{
			piazzata[barca]=true;
			Barca(barca+1);
		}
	}
	ofstream outputfile(NOME_FILE,ios::trunc);
	outputfile<<pin<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			outputfile<<Tabellone[i][j]<<endl;
		}
	}
	outputfile.close();
	return 0;
}
