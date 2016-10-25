#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

double ktoc(double c);
double ctok(double c);
double ctof(double c);
double ftoc(double c);
double faren_to_c(double c);
//double celsius_to_f(double c);
double celsius_to_f(double c);

double ktoc(double c)
{
if(c<-273.15|| c>273.15) return(-500);
double k = c - 273.15;
return (k);
}
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
int k_to_c()
{
double c = 0;
// converts Celsius to Kelvin
// declare input variable
do{
cout << "\nConverteix graus Kelvin a celsius :\t" ;
cin >> c;
if(c<0) cout << "Aquesta temperatura NO pot existir, torna a introduir la temperatura\n És inferior al 0 absolut";
} while(c<0);
double k = ktoc(c);
if(k == -500) cout << "ERROR DE CONVERSIÓ\n Temperatura inexistent ..." ;
else cout << "són "<<  k << " graus celsius \n" ;
// retrieve temperature to input variable
// convert temperature
// print out temperature
return(0);
}
int celsius_to_f()
{

//double df = 9.0/5*dc+32;
double c = 0;
// converts Celsius to Kelvin
// declare input variable
do{
cout << "Converteix graus celsius a Farenheid:\t" ;
cin >> c;
if(c<-273.15) cout << "Aquesta temperatura NO pot existir, torna a introduir la temperatura\n";
} while(c<-273.15);
double temp = ctof(c);
//double df = 9.0/5*c+32;

return (0);
}
double ctof(double c)
{
	c=9.0/5*c+32;
	return (c);
}
double ftoc(double c)
{

	c=(c-32)*(5/9.0);
	return (c);
}
int main()
{
int opcio=4;
//while(true){
	while(opcio!=5) {
		cout << "\nconverteix graus celsius a kelvin -> 1 \n" << "\nconverteix graus kelvin a celsius -> 2 \t \n\n sortir -> 3\n\n opcio : ";
		cin >> opcio;
/*		if(opcio >=1 && opcio <=3) {
			break;
		}
		else {
			cout << "Error, please enter today's date (as an integer):" << std::endl;
			cin.clear();
			cin.ignore();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}*/
		switch(opcio){
			case 1: c_to_k();break;
			case 2: cout << "kevin to celsius"; k_to_c();break;
			case 3: cout << "celsius to farenheit"; celsius_to_f(); break;
			case 4: cout << "farenheit to celsius"; ftoc();break;
			case 5: break;
			default: break;
		}
//	}
}
return (0);
}
