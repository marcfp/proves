#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int i;
	int f;
	int contador=1;
	cout << "Entra un número: ";
	cin  >> i;
	while(contador<=7){
		cout << endl <<"Entra un número entre 1 i 100, tens 7 possibilitats per adivinar-l'ho, vas per la possibilitat " << contador << " a veure si l'endivines!!" << endl;
		cin >> f;
		if(i<f){
			cout << endl << "El número és major que l'entrat, prova-ho amb un de més PETIT " << endl;
		}
		else if(i>f) {
				cout << endl << "El número és menor que l'entrat, prova-ho amb un de més GRAN " << endl;
			}
			else{
				cout << endl << "L'has endevinat!!!" << endl;
				contador=8;
			}
		++contador;
		//cout << "contador dowhile = "<< contador;
	}
	//while(contador!=7);
	cout << "contador = " << contador;
return(0);
}
