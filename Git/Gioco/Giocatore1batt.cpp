#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
//#include <process.h>
#include <sstream>
//#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int barca;
const int N=10;
ofstream outputfile("tabellone_1.txt",ios::trunc);
int Tabellone [N][N] = {};
//srand(unsigned(time(NULL))); 
//n1 = rand()%10;
//SetConsoleTextAttribute(h, 14);
void OutputTabellone(){
	char a=219;
	cout<<"ecco il tabellone : "<<endl;
	cout<<"  ";
	for(int k=0;k<=(N-1);k++)
			{
				cout<<k<<" ";
			}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			
			if(Tabellone[i][j]==0){
			if(j==0)
			cout<<endl<<i<<" "<<"_"<<" ";
			else
			cout<<"_"<<" ";
		}else if(Tabellone[i][j]==1){
		    if(j==0){
			cout<<endl<<i<<" "<<a<<" ";
		    }else{
		        cout<<a<<" ";
		    }
		}
}
}
cout<<endl;
}
void Barca1(){
	bool posizionamento=true;
	barca=barca+1;
	int orientamento;
	do{
	cout<<"vuoi metterla in verticale = 1 o in orizzontale = 2 :";
	cin>>orientamento;
}while(orientamento!=1&&orientamento!=2);
	OutputTabellone();
//	Tabellone [8](x)[8](y) = {
//							{0,0,0,0,0,0,0,0},//0
//							{0,0,0,0,0,0,0,0},//1
//							{0,0,0,0,0,0,0,0},//2
//							{0,0,0,0,0,0,0,0},//3
//							{0,0,0,0,0,0,0,0},//4
//							{0,0,0,0,0,0,0,0},//5
//							{0,0,0,0,0,0,0,0},//6
//							{0,0,0,0,0,0,1,1}//7
//};	
cout<<endl;
int x=0,y=0;
if(orientamento==2){//ORIZZONTALE
do{
    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y][x+i]==0){
		c++;
	}
}
if((x<0||x>(N-2))||(y<0||y>(N-1))){
    posizionamento=false;
}else{
    posizionamento=true;
}
	if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-2))||(y<0||y>(N-1))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}else{//VERTICALE
	do{
	    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
if((x<0||x>(N-1))||(y<0||y>(N-2))){
    posizionamento=false;
}else{
    posizionamento=true;
}
c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y+i][x]==0)
	{
		c++;
	}
}
if(c==barca){
	    posizionamento=true;
	    if((x<0||x>(N-1))||(y<0||y>(N-2))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}
if(orientamento==2){//orizzontale
	for(int i=0;i<barca;i++){
	Tabellone[y][x+i]=1;
}
}else{//verticale
		for(int i=0;i<barca;i++){
	Tabellone[y+i][x]=1;
}
}
OutputTabellone();
}
void Barca2(){
		bool posizionamento=true;
	barca=barca+1;
	int orientamento;
	do{
	cout<<"vuoi metterla in verticale = 1 o in orizzontale = 2 :";
	cin>>orientamento;
}while(orientamento!=1&&orientamento!=2);
	OutputTabellone();
//	Tabellone [8](x)[8](y) = {
//							{0,0,0,0,0,0,0,0},//0
//							{0,0,0,0,0,0,0,0},//1
//							{0,0,0,0,0,0,0,0},//2
//							{0,0,0,0,0,0,0,0},//3
//							{0,0,0,0,0,0,0,0},//4
//							{0,0,0,0,0,0,0,0},//5
//							{0,0,0,0,0,0,0,0},//6
//							{0,0,0,0,0,0,1,1}//7
//};	
cout<<endl;
int x=0,y=0;
if(orientamento==2){//ORIZZONTALE
do{
    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y][x+i]==0){
		c++;
	}
}
if((x<0||x>(N-3))||(y<0||y>(N-1))){
    posizionamento=false;
}else{
    posizionamento=true;
}
	if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-3))||(y<0||y>(N-1))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}else{//VERTICALE
	do{
	    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
if((x<0||x>(N-1))||(y<0||y>(N-3))){
    posizionamento=false;
}else{
    posizionamento=true;
}
c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y+i][x]==0)
	{
		c++;
	}
}
if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-1))||(y<0||y>(N-3))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}
if(orientamento==2){//orizzontale
	for(int i=0;i<barca;i++){
	Tabellone[y][x+i]=1;
}
}else{//verticale
		for(int i=0;i<barca;i++){
	Tabellone[y+i][x]=1;
}
}
OutputTabellone();
}
void Barca3(){
   	bool posizionamento=true;
	barca=barca+1;
	int orientamento;
	do{
	cout<<"vuoi metterla in verticale = 1 o in orizzontale = 2 :";
	cin>>orientamento;
}while(orientamento!=1&&orientamento!=2);
	OutputTabellone();
//	Tabellone [8](x)[8](y) = {
//							{0,0,0,0,0,0,0,0},//0
//							{0,0,0,0,0,0,0,0},//1
//							{0,0,0,0,0,0,0,0},//2
//							{0,0,0,0,0,0,0,0},//3
//							{0,0,0,0,0,0,0,0},//4
//							{0,0,0,0,0,0,0,0},//5
//							{0,0,0,0,0,0,0,0},//6
//							{0,0,0,0,0,0,1,1}//7
//};	
cout<<endl;
int x=0,y=0;
if(orientamento==2){//ORIZZONTALE
do{
    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y][x+i]==0){
		c++;
	}
}
if((x<0||x>(N-4))||(y<0||y>(N-1))){
    posizionamento=false;
}else{
    posizionamento=true;
}
	if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-4))||(y<0||y>(N-1))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}else{//VERTICALE
	do{
	    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
if((x<0||x>(N-1))||(y<0||y>(N-4))){
    posizionamento=false;
}else{
    posizionamento=true;
}
c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y+i][x]==0)
	{
		c++;
	}
}
if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-1))||(y<0||y>(N-4))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}
if(orientamento==2){//orizzontale
	for(int i=0;i<barca;i++){
	Tabellone[y][x+i]=1;
}
}else{//verticale
		for(int i=0;i<barca;i++){
	Tabellone[y+i][x]=1;
}
}
OutputTabellone();
} 
void Barca4(){
    	bool posizionamento=true;
	barca=barca+1;
	int orientamento;
	do{
	cout<<"vuoi metterla in verticale = 1 o in orizzontale = 2 :";
	cin>>orientamento;
}while(orientamento!=1&&orientamento!=2);
	OutputTabellone();
//	Tabellone [8](x)[8](y) = {
//							{0,0,0,0,0,0,0,0},//0
//							{0,0,0,0,0,0,0,0},//1
//							{0,0,0,0,0,0,0,0},//2
//							{0,0,0,0,0,0,0,0},//3
//							{0,0,0,0,0,0,0,0},//4
//							{0,0,0,0,0,0,0,0},//5
//							{0,0,0,0,0,0,0,0},//6
//							{0,0,0,0,0,0,1,1}//7
//};	
cout<<endl;
int x=0,y=0;
if(orientamento==2){//ORIZZONTALE
do{
    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y][x+i]==0){
		c++;
	}
}
if((x<0||x>+(N-5))||(y<0||y>(N-1))){
    posizionamento=false;
}else{
    posizionamento=true;
}
	if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-5))||(y<0||y>(N-1))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}else{//VERTICALE
	do{
	    posizionamento=false;
cout<<"inserisci la coordinata y della barca: ";
cin>>y;
cout<<"inserisci la coordinata x della barca: ";
cin>>x;
int c=0;
if((x<0||x>(N-1))||(y<0||y>(N-5))){
    posizionamento=false;
}else{
    posizionamento=true;
}
c=0;
for(int i=0;i<barca;i++){
	if(Tabellone[y+i][x]==0)
	{
		c++;
	}
}
if(c==barca){
	    posizionamento=true;
	     if((x<0||x>(N-1))||(y<0||y>(N-5))){
    posizionamento=false;}
	}else{
	    posizionamento=false;
	}
}while(posizionamento==false);
}
if(orientamento==2){//orizzontale
	for(int i=0;i<barca;i++){
	Tabellone[y][x+i]=1;
}
}else{//verticale
		for(int i=0;i<barca;i++){
	Tabellone[y+i][x]=1;
}
}
OutputTabellone();
}
int main() {
int pin;
do{
cout<<"Inserisci il pin (min 5 cifre):";
cin>>pin;
}while((pin/10000)<1);
outputfile<<pin<<endl;
for(int i=0;i<4;i++){
cout<<"inserisci quale barca vuoi piazzare: "<<endl<<"barca da 2 = 1"<<endl<<"barca da 3 = 2"<<endl<<"barca da 4 = 3"<<endl<<"barca da 5 = 4"<<endl<<"inserisci: ";
cin>>barca;
switch(barca){
	case 1:
		Barca1();
		break;
	case 2:
		Barca2();
	break;
	case 3:
		Barca3();
	break;
	case 4:
		Barca4();
	break;
		default:
	cout<<"errore";	
	break;
}
}
for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        outputfile<<Tabellone[i][j]<<endl;
    }
}
		outputfile.close();
return 0;
}