#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
// SUDOKU: riempi la griglia 9x9 in modo che ogni riga, ogni colonna e ogni
// quadrato 3x3 contenga tutti i numeri da 1 a 9 una sola volta.
// Il puzzle viene generato a caso e ha sempre una sola soluzione.
int soluzione[9][9];
int griglia[9][9];   // 0 = casella vuota
bool fissa[9][9];    // numeri dati all'inizio, non si possono cambiare
int aiuti_usati=0;
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
// controlla se n si puo' mettere in (r,c) senza ripetizioni
bool valido(int g[9][9],int r,int c,int n){
	for(int i=0;i<9;i++){
		if(i!=c&&g[r][i]==n){
			return false;
		}
		if(i!=r&&g[i][c]==n){
			return false;
		}
	}
	int r0=r/3*3,c0=c/3*3;
	for(int i=r0;i<r0+3;i++){
		for(int j=c0;j<c0+3;j++){
			if((i!=r||j!=c)&&g[i][j]==n){
				return false;
			}
		}
	}
	return true;
}
// riempie la griglia con backtracking provando i numeri in ordine casuale
bool riempi(int g[9][9]){
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			if(g[r][c]==0){
				int numeri[9]={1,2,3,4,5,6,7,8,9};
				for(int i=8;i>0;i--){
					int j=rand()%(i+1);
					int t=numeri[i];numeri[i]=numeri[j];numeri[j]=t;
				}
				for(int k=0;k<9;k++){
					if(valido(g,r,c,numeri[k])){
						g[r][c]=numeri[k];
						if(riempi(g)){
							return true;
						}
						g[r][c]=0;
					}
				}
				return false;
			}
		}
	}
	return true;
}
// conta le soluzioni (si ferma a 2: basta sapere se e' unica)
int conta_soluzioni(int g[9][9]){
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			if(g[r][c]==0){
				int totale=0;
				for(int n=1;n<=9&&totale<2;n++){
					if(valido(g,r,c,n)){
						g[r][c]=n;
						totale+=conta_soluzioni(g);
						g[r][c]=0;
					}
				}
				return totale;
			}
		}
	}
	return 1;
}
// genera un puzzle togliendo numeri finche' la soluzione resta unica
void genera(int da_togliere){
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			soluzione[r][c]=0;
		}
	}
	riempi(soluzione);
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			griglia[r][c]=soluzione[r][c];
		}
	}
	int ordine[81];
	for(int i=0;i<81;i++){
		ordine[i]=i;
	}
	for(int i=80;i>0;i--){
		int j=rand()%(i+1);
		int t=ordine[i];ordine[i]=ordine[j];ordine[j]=t;
	}
	int tolti=0;
	for(int i=0;i<81&&tolti<da_togliere;i++){
		int r=ordine[i]/9,c=ordine[i]%9;
		int vecchio=griglia[r][c];
		griglia[r][c]=0;
		if(conta_soluzioni(griglia)!=1){
			griglia[r][c]=vecchio;//senza questo numero le soluzioni sarebbero piu' di una
		}else{
			tolti++;
		}
	}
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			fissa[r][c]=(griglia[r][c]!=0);
		}
	}
}
bool completo(){
	for(int r=0;r<9;r++){
		for(int c=0;c<9;c++){
			if(griglia[r][c]!=soluzione[r][c]){
				return false;
			}
		}
	}
	return true;
}
// segna_errori = true mostra in rosso i numeri sbagliati
void output(bool segna_errori){
	cout<<endl<<"     0 1 2   3 4 5   6 7 8"<<endl;
	for(int r=0;r<9;r++){
		if(r%3==0){
			cout<<"   +-------+-------+-------+"<<endl;
		}
		cout<<" "<<r<<" ";
		for(int c=0;c<9;c++){
			if(c%3==0){
				cout<<"| ";
			}
			if(griglia[r][c]==0){
				SetConsoleTextAttribute(h,8);
				cout<<". ";
			}else{
				if(fissa[r][c]){
					SetConsoleTextAttribute(h,15);
				}else if(segna_errori&&griglia[r][c]!=soluzione[r][c]){
					SetConsoleTextAttribute(h,12);
				}else if(!valido(griglia,r,c,griglia[r][c])){
					SetConsoleTextAttribute(h,13);//si ripete nella riga, colonna o quadrato
				}else{
					SetConsoleTextAttribute(h,11);
				}
				cout<<griglia[r][c]<<" ";
			}
			SetConsoleTextAttribute(h,7);
		}
		cout<<"|"<<endl;
	}
	cout<<"   +-------+-------+-------+"<<endl;
	cout<<"bianco = numeri dati, azzurro = i tuoi numeri, viola = numero ripetuto"<<endl;
}
int main(){
	srand(unsigned(time(NULL)));
	cout<<"SUDOKU"<<endl<<"Ogni riga, colonna e quadrato 3x3 deve contenere i numeri da 1 a 9 una sola volta."<<endl<<endl;
	bool ancora=true;
	while(ancora){
		cout<<"Scegli la difficolta':"<<endl<<"Facile = 1"<<endl<<"Media = 2"<<endl<<"Difficile = 3"<<endl;
		int livello;
		do{
			livello=leggi_intero("inserisci: ");
		}while(livello<1||livello>3);
		cout<<"sto generando il sudoku..."<<endl;
		genera(livello==1?40:livello==2?48:56);
		aiuti_usati=0;
		time_t inizio=time(NULL);
		bool segna=false,arreso=false;
		while(!completo()){
			system("cls");
			output(segna);
			segna=false;
			int azione;
			do{
				azione=leggi_intero("inserisci un numero = 1, cancella = 2, controlla errori = 3, aiuto = 4, arrenditi = 0: ");
			}while(azione<0||azione>4);
			if(azione==0){
				arreso=true;
				break;
			}
			if(azione==3){
				segna=true;
				continue;
			}
			if(azione==4){
				//mette il numero giusto nella prima casella vuota o sbagliata
				bool fatto=false;
				for(int i=0;i<81&&!fatto;i++){
					int r=i/9,c=i%9;
					if(griglia[r][c]!=soluzione[r][c]){
						griglia[r][c]=soluzione[r][c];
						aiuti_usati++;
						fatto=true;
					}
				}
				continue;
			}
			int r=leggi_intero("inserisci la riga (0-8): ");
			int c=leggi_intero("inserisci la colonna (0-8): ");
			string errore="";
			if(r<0||r>8||c<0||c>8){
				errore="coordinate non valide";
			}else if(fissa[r][c]){
				errore="questo numero e' dato all'inizio e non si puo' cambiare";
			}
			if(errore==""){
				if(azione==2){
					griglia[r][c]=0;
				}else{
					int n=leggi_intero("inserisci il numero (1-9): ");
					if(n<1||n>9){
						errore="il numero deve essere da 1 a 9";
					}else{
						griglia[r][c]=n;
					}
				}
			}
			if(errore!=""){
				cout<<errore<<endl;
				system("pause");
			}
		}
		system("cls");
		if(arreso){
			for(int r=0;r<9;r++){
				for(int c=0;c<9;c++){
					griglia[r][c]=soluzione[r][c];
				}
			}
			output(false);
			cout<<"ecco la soluzione"<<endl;
		}else{
			output(false);
			cout<<"COMPLIMENTI, HAI RISOLTO IL SUDOKU in "<<(long)(time(NULL)-inizio)<<" secondi";
			if(aiuti_usati>0){
				cout<<" con "<<aiuti_usati<<" aiut"<<(aiuti_usati==1?"o":"i");
			}
			cout<<"!"<<endl;
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
