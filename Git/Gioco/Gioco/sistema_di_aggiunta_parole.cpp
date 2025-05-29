#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <process.h>
#include <sstream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
string parola[16]={" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
int i=-1;
//sistema per aggiungere parole generalizzato
/*
int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_4.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_4.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_4.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
	outputfile.close();
}
*/
void AggiungiParola_4(){
	int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_4.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_4.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_4.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_5(){
	int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_5.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_5.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_5.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_6(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_6.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_6.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_6.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_7(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_7.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_7.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_7.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_8(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_8.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_8.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_8.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_9(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_9.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_9.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_9.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_10(){
	int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_10.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_10.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_10.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_11(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_11.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_11.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_11.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_12(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_12.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_12.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_12.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_13(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_13.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_13.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_13.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_14(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_14.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_14.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_14.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
void AggiungiParola_15(){
		int c=0;
	bool esiste=false;
	string parola_ver[i];
	string line;
	int j=0;
	{
	line="";
	ifstream leggi("parola_15.txt");
	for(; getline(leggi,line,';'); j++);
	leggi.close();
	}
	j/=i;
	line="";
	for(int k=1;k<j;k++){
		ifstream leggi("parola_15.txt");
		for(int x=0;x<=((i)*k-1);x++){
					getline(leggi,line,';');
				}
	for(int z=0;z<i;z++){
			getline(leggi,parola_ver[z],';');	
	}
	c=1;
	for(int d=0;d<i;d++){
		if(parola[d]==parola_ver[d]){
			c++;
		}
	}
	if(c==i){
		break;
	}
		leggi.close();
	}
	if(c==i){
		cout<<endl<<"parola gia esisistente nel sistema "<<endl;
		esiste=true;
	}
	if(esiste==false){
	ofstream outputfile("parola_15.txt",ios::app);
			for(int j=0;j<i; j++) {
				if(j==0){
				outputfile<<endl<<parola[j]<<";";
			}else{
				outputfile<<parola[j]<<";";
			}
		}
		cout<<endl<<"parola aggiunta";
	outputfile.close();
}
}
int main(){
	cout<<"inserisci la parola lettera per lettera facendo invio a ongi lettera e poi alla fine inserisci 0"<<endl;
	bool finito=false;
	while(finito!=true){
	if(parola[i]!="0"){
		i++;
		cout<<"inserisci lettera: ";
		cin>>parola[i];
	}else{
		finito=true;
	}

	}
	cout<<"parola e' da "<<i<<" lettere";
	switch (i){
		case 4:
			AggiungiParola_4();
		break;
			case 5:
			AggiungiParola_5();
		break;
			case 6:
			AggiungiParola_6();
		break;
			case 7:
			AggiungiParola_7();
		break;
			case 8:
			AggiungiParola_8();
		break;
			case 9:
			AggiungiParola_9();
		break;
			case 10:
			AggiungiParola_10();
		break;
			case 11:
			AggiungiParola_11();
		break;
			case 12:
			AggiungiParola_12();
		break;
			case 13:
			AggiungiParola_13();
		break;
			case 14:
			AggiungiParola_14();
		break;
			case 15:
			AggiungiParola_15();
		break;
			default:
				cout<<"errore"<<endl;
				system("pause");
				return 0;
			break;
	}
			cout<<endl;
			system("pause");
	return 0;
}