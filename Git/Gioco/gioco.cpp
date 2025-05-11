#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <process.h>
#include <sstream>
#include <windows.h>
using namespace std;
int main() {
	int sceltassoluta;
		cout<<"Cosa vuoi fare:"<<endl<<"indovina il pin = 1"<<endl<<"indovina la parola = 2"<<endl<<"Modalita' single player pin = 3"<<endl<<"Modalita' single player parola = 4"<<endl<<"Battaglia navale = 5"<<endl<<"Tris = 6"<<endl<<"Aggiungi una parola alla modalita' singol player = 7"<<endl<<"inserisci: ";
		cin>>sceltassoluta;
	switch (sceltassoluta){
	case 1:
		system("Pin.exe");
	break;
	case 2:	
		system("Parola.exe");
	break;
	case 3: 
		system("singolplayer.exe");	
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
	default:
		cout<<"errore";
		system("pause");
		return 0;
	break;
	}
}