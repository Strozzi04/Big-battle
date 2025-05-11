#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
//#include <process.h>
#include <sstream>
//#include <windows.h>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int n=10;
string Tabellone [n][n];
void OutputTabellone(){
	char a=219;
	cout<<"ecco il tabellone : "<<endl;
	cout<<"  ";
	for(int k=0;k<=(n-1);k++)
			{
				cout<<k<<" ";
			}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			if(Tabellone[i][j]=="0"){
			if(j==0){
			cout<<endl<<i<<" "<<"_"<<" ";
			}else{
			cout<<"_"<<" ";
		}
		}else if(Tabellone[i][j]=="1"){
		    if(j==0){
			cout<<endl<<i<<" "<<a<<" ";
		    }else{
		        cout<<a<<" ";
		    }
			}else if(Tabellone[i][j]=="2")
		{
			if(j==0){
			cout<<endl<<i<<" "<<"X"<<" ";
		    }else{
		        cout<<"X"<<" ";
		    }
		}
}
}
cout<<endl;
}
int main(){
    ifstream inputfile("tabellone_1.txt");
    string pin;
    string line1;
    string pos;
    cout<<"inserisci il pin: ";
    cin>>pin;
    getline(inputfile,line1);
    
    if(pin==line1){//alla linea che prende allora faccio vedere il tabellone
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            getline(inputfile,pos);
            Tabellone[i][j]=pos;
    }
    }
    OutputTabellone();
}else{
    cout<<"pin errato";
}

inputfile.close();
return 0;
}
