#include "comune.h"
#include <vector>
#include <ctime>
// modalita' single player della parola: la parola viene scelta a caso dal
// file parola_N.txt (N = numero di lettere), dove ogni riga contiene una
// parola con le lettere separate da ';' (es. g;u;i;d;a;)

// legge tutte le parole lunghe numerolettere dal file
vector<string> LeggiParole(int numerolettere){
	vector<string> parole;
	ifstream inputfile(("parola_"+to_string(numerolettere)+".txt").c_str());
	string line;
	while(getline(inputfile,line)){
		string parola;
		for(int i=0;i<(int)line.size();i++){
			if(isalpha((unsigned char)line[i])){
				parola+=(char)tolower((unsigned char)line[i]);
			}
		}
		if((int)parola.size()==numerolettere){
			parole.push_back(parola);
		}
	}
	inputfile.close();
	return parole;
}
int main() {
	srand(unsigned(time(NULL)));
	int numerolettere;
	do {
		numerolettere=leggi_intero("Inserisci il numero di lettere (da 4 a 15): ");
	} while(numerolettere<4||numerolettere>15);
	vector<string> parole=LeggiParole(numerolettere);
	if(parole.empty()){
		cout<<"non ci sono ancora parole da "<<numerolettere<<" lettere, aggiungile con l'opzione 7 del menu"<<endl;
		system("pause");
		return 0;
	}
	salva_soluzione(GIOCO_PAROLA,parole[rand()%parole.size()]);
	gioca(GIOCO_PAROLA,scegli_difficolta(GIOCO_PAROLA));
	return 0;
}
