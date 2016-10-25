#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	double primer;
	double segon;
	double resultat;
	string operacio;
	string mes="+";
	string menys="-";
	string multiplica="*";
	string divideix="/";
	do{
	cout << "Entra'm 2 números seguit d'una operació (+,-,*,/) i et donaré el resultat: ";
	cin  >> primer >> segon >> operacio;
	}while(isdigit(primer) && isdigit(segon) && (operacio.compare(mes) && operacio.compare(menys) && operacio.compare(multiplica) && operacio.compare(divideix)));
	cout << endl << "primer número = " << primer << " Segon número = " << segon << " Operació = " << operacio << endl;
	if(operacio.compare(mes)==0) { cout << endl << "suma" << endl;
					cout << "Pimer operant " << primer << endl;
					cout << "Segon operant " << segon << endl;
					resultat = primer+segon;
					cout << "Resultat de " << primer << " + " << segon << " = " << resultat << endl;
	}
	else if(operacio.compare(menys)==0) {cout << endl << "resta" << endl; 
						cout << "Pimer operant " << primer << endl;
                                        cout << "Segon operant " << segon << endl;
                                        resultat = primer-segon ;
                                        cout << "Resultat de " << primer << " - " << segon << " = " << resultat << endl;
	}
	else if(operacio.compare(multiplica)==0) { cout << endl << "multiplica" << endl; 
						 cout << "Pimer operant " << primer << endl;
                                        cout << "Segon operant " << segon << endl;
                                        resultat = primer*segon;
                                        cout << "Resultat de " << primer << " * " << segon << " = " << resultat << endl;
	} 
	else if(operacio.compare(divideix)==0) { cout << endl << "divideix" << endl ;
					 cout << "Pimer operant " << primer << endl;
                                        cout << "Segon operant " << segon << endl;
                                        resultat = primer/segon;
                                        cout << "Resultat de " << primer << " / " << segon << " = " << resultat << endl;	
	 }
	else {
		cout << "OPERACIÓ NO SUPORTADA!" << endl;
	}
return(0);
}
