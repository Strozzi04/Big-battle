#include "comune.h"
#include <ctime>
// modalita' single player del pin: il pin viene generato a caso
int main() {
	srand(unsigned(time(NULL)));
	int numerolettere;
	do{
		numerolettere=leggi_intero("Da quante cifre deve essere il pin? (minimo 3) ");
	}while(numerolettere<3||numerolettere>30);
	string pin;
	for(int i=0;i<numerolettere;i++){
		pin+=(char)('0'+rand()%10);
	}
	salva_soluzione(GIOCO_PIN,pin);
	gioca(GIOCO_PIN,scegli_difficolta(GIOCO_PIN));
	return 0;
}
