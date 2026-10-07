#include "comune.h"
// modalita' a due giocatori: uno decide, l'altro indovina
int main() {
	const Gioco &g=GIOCO_PAROLA;
	int scelta;
	do {
		cout<<"1 = sei tu chi decide "<<g.articolo<<" "<<g.nome<<endl<<"2 = sei chi indovina "<<g.articolo<<" "<<g.nome<<endl;
		scelta=leggi_intero("Inserisci: ");
	} while(!(scelta==1||scelta==2));
	if(scelta==1) {
		int numerolettere;
		do {
			numerolettere=leggi_intero("Inserisci il numero di "+g.unita+": ");
		} while(numerolettere<=1||numerolettere>30);
		string segreto=leggi_tentativo(g,"inserisci "+g.articolo+" "+g.nome+": ",numerolettere);
		if(salva_soluzione(g,segreto)) {
			cout<<endl<<"E' avvenuto tutto con successo"<<endl;
		} else {
			cout<<endl<<"ci sono stati degli errori."<<endl;
		}
		system("pause");
		system("cls");
		return 0;
	}
	gioca(g,scegli_difficolta(g));
	return 0;
}
