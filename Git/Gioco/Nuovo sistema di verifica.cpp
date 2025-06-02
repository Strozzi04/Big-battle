#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <process.h>
#include <sstream>
#include <windows.h>
#include <vector>
using namespace std;
int main(){
	string line1;
	int numerolettere;
	cin>>numerolettere;
	string parola[numerolettere] = {};
	ifstream inputfile("parola.txt");
	for(int i=0;i<numerolettere;i++){
	getline(inputfile,line1);
	parola[i]=line1;
	}
for(int j=0;j<numerolettere;j++)
	cout<<parola[j];
}