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
int Tabellone[3][3];
output(){
		cout<<"ecco il tabellone : "<<endl;
	cout<<"  ";
	for(int k=0;k<=(2);k++)
			{
				cout<<k<<" ";
			}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(Tabellone[i][j]==0){
			if(j==0){
			cout<<endl<<i<<" "<<"_"<<" ";
			}else{
			cout<<"_"<<" ";
		}
		}else if(Tabellone[i][j]==1){
		    if(j==0){
			cout<<endl<<i<<" "<<"X"<<" ";
		    }else{
		        cout<<"X"<<" ";
		    }
		}else if(Tabellone[i][j]==2)
		{
			if(j==0){
			cout<<endl<<i<<" "<<"O"<<" ";
		    }else{
		        cout<<"O"<<" ";
		    }
		}
}
}
cout<<endl;
}
giocatore_1(){
	cout<<endl<<"giocatore 1: "<<endl;
	output();
	bool pos=true;
		int x,y;
	do{
	cout<<"inserisci la coordinata y : ";
	cin>>y;
	cout<<"inserisci la coordinata x : ";
	cin>>x;
	if(Tabellone[y][x]==2){
		pos=false;
	}
	}while(((x<0||x>(2))||(y<0||y>(2)))&&pos==true);
	Tabellone[y][x]=1;
}
giocatore_2(){
	cout<<endl<<"giocatore 2: "<<endl;
	output();
		bool pos=true;
		int x,y;
	do{
	cout<<"inserisci la coordinata y : ";
	cin>>y;
	cout<<"inserisci la coordinata x : ";
	cin>>x;
	if(Tabellone[y][x]==1){
		pos=false;
	}
	}while(((x<0||x>(2))||(y<0||y>(2)))&&pos==true);
	Tabellone[y][x]=2;
}
int continuare(){
	int c=0;
	for(int j=0;j<3;j++){
		c=0;
		for(int i=0;i<3;i++){
			if(Tabellone[j][i]==1){
				c++;
			}
		}
		if (c==3){
			return 2;
		}
	}
	c=0;
	for(int j=0;j<3;j++){
		c=0;
		for(int i=0;i<3;i++){
			if(Tabellone[i][j]==1){
				c++;
			}
		}
		if (c==3){
			return 2;	
	}
}
	c=0;
	for(int j=0;j<3;j++){
			if(Tabellone[j][j]==1){
				c++;
			}
		}
		if (c==3){
				return 2;
			}
	c=0;
	for(int j=2;j>=0;j--){
			if(Tabellone[j][j]==1){
				c++;
			}
		}
		if (c==3){
				return 2;
			}
			
		c=0;	
		for(int j=0;j<3;j++){
		c=0;
		for(int i=0;i<3;i++){
			if(Tabellone[j][i]==2){
				c++;
			}
		}
		if (c==3){
			return 3;
		}
	}
	c=0;
	for(int j=0;j<3;j++){
		c=0;
		for(int i=0;i<3;i++){
			if(Tabellone[i][j]==2){
				c++;
			}
		}
		if (c==3){
			return 3;	
	}
}
	c=0;
	for(int j=0;j<3;j++){
			if(Tabellone[j][j]==2){
				c++;
			}
		}
		if (c==3){
				return 3;
			}
	c=0;
	for(int j=2;j>=0;j--){
			if(Tabellone[j][j]==2){
				c++;
			}
		}
		if (c==3){
				return 3;
			}		
	return 1;
}
int main() {
	bool pos=true;
	cout<<"il giocatore 1 sara la X il 2 la O";
	srand(time(NULL));
	int a=rand()%2+1;
	if(a==1){
	cout<<"comincia il giocatore 1: ";
	giocatore_1();
}else{
	cout<<"comincia il giocatore 2";
	giocatore_2();
}
int b=continuare();
while(b==1){
	if(a==2){
	giocatore_1();
	giocatore_2();
	b=continuare();
}else{
	giocatore_2();
	giocatore_1();
	b=continuare();
}
}
if(b==2){
cout<<endl<<"HA VINTO IL GIOCATORE 1"<<endl;
output();
system("pause");
}else if(b==3){
cout<<endl<<"HA VINTO IL GIOCATORE 2"<<endl;
output();
system("pause");
}
}