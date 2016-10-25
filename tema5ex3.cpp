#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


double ctok(double c)
{
if(c<-273.15|| c>273.15) return(-500);
double k = c + 273.15;
return (k);
}
int c_to_k()
{
double c = 0;
// converts Celsius to Kelvin
// declare input variable
do{
cout << "Converteix graus celsius a Kelvin:\t" ;
cin >> c;
if(c<-273.15) cout << "Aquesta temperatura NO pot existir, torna a introduir la temperatura\n";
} while(c<-273.15);
double k = ctok(c);
if(k == -500) cout << "ERROR DE CONVERSIÓ\n Temperatura inexistent ..." ;
else cout << "són "<<  k << " graus kelvin \n" ;
// retrieve temperature to input variable
// convert temperature
// print out temperature
return(0);
}
int main()
{
int opcio=4;
while(opcio!=3) {
	cout << "\nconverteix graus celsius a kelvin -> 1 \n" << "\nconverteix graus kelvin a celsius -> 2 \t \n\n sortir -> 3\n\n opcio : ";
	cin >> opcio;
	switch(opcio){
		case 1: c_to_k();break;
		case 2: cout << "kevin to celsius"; break;
		case 3: break;
		default: break;
	}
}
return (0);
}
