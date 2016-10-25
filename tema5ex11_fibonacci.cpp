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
 char surt='|';
int j=2;
bool mentre=true;
int suma=0;
int para=0;
cout << "Calculo el MÀXIM enter que cap a la sèria de fibonacci " << endl ;
serie.push_back(0); //n=0
cout << "\nserie.at(0) = " << serie.at(0) << /*" serie.at((serie.size()-2))=" << serie.at(serie.size()-2) << */"suma = " << serie.at(0) << "\n";
serie.push_back(1); //n=1
cout << "\nserie.at(0) = " << serie.at(0) << " serie.at(1)=" << serie.at(1) << "suma = " << serie.at(1) << "\n";
serie.push_back(1); //n=2
cout << "\nserie.at(serie.size()-1) = " << serie.at(serie.size()-1) << " serie.at((serie.size()-2))=" << serie.at(serie.size()-2) << "suma = " << serie.at(1) << "\n";
//for (int i=2; i=j;
while(mentre){
//	for(int i=serie.size()-2; i<=serie.size(); ++i){
		suma=serie.at((serie.size()-2))+serie.at((serie.size()-1));
		serie.push_back(suma);		
		cout << "\nserie.at(serie.size()-1) = " << serie.at(serie.size()-1) << " serie.at((serie.size()-2))=" << serie.at(serie.size()-2) << "suma = " << suma << "\n"; 
//	}
para++;
if(para==44) mentre=false;

}
return (0);
}
