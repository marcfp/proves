#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<double> numero;
//	vector<double> distancia;
	int contador=0;
	double suma=0;
	int j;
	for (double n1; cin >> n1;) {
		++contador;
		numero.push_back(n1);
		suma=suma+n1;
	}
	for(int i=0; i < numero.size()-1; i++){ //posicio menys a l'allargada del vector numero!!!
		if(i<numero.size()) {
					j=i+1;
			int dist=numero.at(j)-numero.at(i);
//			distancia.push_back(dist);		
			cout << endl << " distancia entre " << i+1 << " i " << j+1 << " és " << dist; //+1 pk posicio 0 quina és ?
		
		}
		else cout << "fi del vector ";
		
	}
	cout << " contador = " << contador << " suma = " << suma  << " minim = " << *min_element(numero.begin(),numero.end()) << " maxim = " << *max_element(numero.begin(),numero.end()) << endl;
return(0);
}
