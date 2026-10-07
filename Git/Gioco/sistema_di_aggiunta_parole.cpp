#include "comune.h"
// aggiunge una parola al file parola_N.txt usato dalla modalita' single player
// (N = numero di lettere, da 4 a 15). Ogni riga del file contiene una parola
// con le lettere separate da ';' (es. g;u;i;d;a;)
int main(){
	string parola;
	while(true){
		cout<<"inserisci la parola da aggiungere (da 4 a 15 lettere, senza accenti): ";
		if(!(cin>>parola)){
			return 0;
		}
		parola=minuscolo(parola);
		if(!valida(GIOCO_PAROLA,parola)){
			cout<<"la parola puo' contenere solo lettere"<<endl;
		}else if(parola.size()<4||parola.size()>15){
			cout<<"la parola deve essere da 4 a 15 lettere"<<endl;
		}else{
			break;
		}
	}
	int i=parola.size();
	cout<<"la parola e' da "<<i<<" lettere"<<endl;
	string nome_file="parola_"+to_string(i)+".txt";
	// controllo se la parola esiste gia' e se il file finisce con un a capo
	bool esiste=false;
	bool a_capo=true;
	{
		ifstream leggi(nome_file.c_str());
		string line;
		while(getline(leggi,line)){
			string p;
			for(int k=0;k<(int)line.size();k++){
				if(isalpha((unsigned char)line[k])){
					p+=(char)tolower((unsigned char)line[k]);
				}
			}
			if(p==parola){
				esiste=true;
			}
			a_capo=!leggi.eof();
		}
		leggi.close();
	}
	if(esiste){
		cout<<endl<<"parola gia' esistente nel sistema"<<endl;
	}else{
		ofstream outputfile(nome_file.c_str(),ios::app);
		if(!a_capo){
			outputfile<<endl;
		}
		for(int j=0;j<i;j++){
			outputfile<<parola[j]<<";";
		}
		outputfile<<endl;
		outputfile.close();
		cout<<endl<<"parola aggiunta"<<endl;
	}
	system("pause");
	return 0;
}
