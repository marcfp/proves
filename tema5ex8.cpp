#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
//llegeix una sèries d'enters i fa la seva suma dels primers N termes introduits.
vector<int> serie;
int numero;
char valors;
int resultat=0;
 char surt='|';
cout << "Entra el número de valors que vols entrar per després sumar-los\t:\t" ;
cin >> numero;
cout<< "\nEntra els valors, escriu | per finalitzar \n" ;

while(valors!='|'){
	if (!(cin >> valors)) {
		cin.clear();
	}
	if(valors!= static_cast<int>(valors)) cout << "\nAixò no és un enter ?\n";
	else serie.push_back(int(valors));
	cout << "\nvalors.size = " << serie.size() << "\n";
}//while(valors!='|');
//int val=serie.size()-numero;
try{
	for(int i=0; i< serie.size()-1/*-numero*/; ++i) {
				
				if(i<numero) {
					if(serie[i]!= static_cast<int>(serie[i])) cout << "\nAixò no és un enter ?\n";
//	else cout << "\nAixò és un enter!!!!\n";
					resultat=int(resultat)+(int(serie[i])-48);
					cout << "\nresultat = " << resultat << " serie[" << i << "] = " << serie[i] << "int(serie[i])-48 = " << int(serie[i])-48;
				}
				else {
					cout << "\nper " << i << " no sumo ...\n" ;
				}
		}
	cout << "\nValor total de la suma de " << numero << " elements és " << resultat << "\n i els seus sumants són : ";
		for(int i=0; i<numero; ++i) cout << "\n posició: " << i << "\t sumant : " << int(serie[i])-48 << "\n";
	}
catch (exception& e) {
	cout << "\nAixò no és un enter i no ho puc representar";
	}
return(0);

}
