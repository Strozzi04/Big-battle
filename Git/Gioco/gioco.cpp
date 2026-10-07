#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <process.h>
#include <sstream>
#include <windows.h>
using namespace std;
int main() {
	system("caricamento.exe");
	cout<<endl;
	system("cls");
	while(1==1){
	int sceltassoluta;
		cout<<"Cosa vuoi fare:"<<endl<<"indovina il pin = 1"<<endl<<"indovina la parola = 2"<<endl<<"Modalita' single player pin = 3"<<endl<<"Modalita' single player parola = 4"<<endl<<"Battaglia navale = 5"<<endl<<"Tris = 6"<<endl<<"Aggiungi una parola alla modalita' single player = 7"<<endl<<"Apri l'interfaccia grafica = 8"<<endl<<"Esci = 0"<<endl<<"inserisci: ";
		if(!(cin>>sceltassoluta)){
			if(cin.eof()){
				return 0;
			}
			cin.clear();
			cin.ignore(10000,'\n');
			sceltassoluta=-1;
		}
	switch (sceltassoluta){
	case 1:
		system("Pin.exe");
	break;
	case 2:	
		system("Parola.exe");
	break;
	case 3: 
		system("singolplayer.exe");	
		break;
	case 4:
		system("singolplayerparola.exe");
	break;
	case 5:
		system("BATTAGLIA_NAVALE.exe");
	break;
	case 6:
		system("tris.exe");
	break;
	case 7:
		system("sistema_di_aggiunta_parole.exe");
	break;
	case 8:
		system("start \"\" BigBattle.html");
	break;
	case 0:
		return 0;
	default:
		cout<<"scelta non valida"<<endl;
		system("pause");
	break;
	}
	system("cls");
	}
}