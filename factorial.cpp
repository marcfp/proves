#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
float factorial(float factor);
float permutacio(float p, float r);
float permutacio_repeticio();
int main()
{
	float fact, factorial_total;
	float permuta, p, r;
	cout << "S'han de demanar 2 números primer de tot, i després preguntar si es vol calcular una permutació o una combinació, i si és amb repetició o sense ?, el programa hauria de tenir comprobació d'errors, tots els errors haurien d'estar controlats i donar un bon missatge d'error" << endl << " A CONTINUACIÓ ESTÀ FET SENSE FER RES D'AIXÒ" << endl;
	try{
		cout << "entra el número que vols calcular el factorial :";
		cin >> fact;
		if (cin.good())
    		{
		        if (fact < 0) {
					cout << "Negative.";
					//sortir del programa si és negatiu, no es pot calcular el factorial d'un nombre negatiu
			}
		        else { 
				cout << "Positive.";
				//continuar amb normalitat, tot està bé 
				factorial_total = factorial(fact);
			        cout << "El valor del " << fact << "! és de " << factorial_total << endl << "Gràcies!! "<< endl;
			}
    		}                            
    		else{
		        cout << endl << "Això no és un nombre ENTER!!!"<< endl;
		        cin.clear();
		        cin.ignore(256, '\n'); // NB: preferred method for flushing cin
			exit;
   		}
	}
	catch(exception& e) {
			cout << "Hi ha hagut un error : " << e.what() << endl;
			cin.clear();
			cin.ignore(256, '\n');
			fflush(stdin);
	}
	cout << endl << "Permutació ?" << endl;
	cout << endl << "llegir p \t";
	cin >> p;
	cout << endl <<  "llegir r \t" ;
	cin >> r;
	
	permuta=permutacio(p,r);
	cout << endl << " la permutació és " << permuta << endl;
	cout << endl << "Permutació amb repetició " << endl;
	permuta = permutacio_repeticio();
return (0);
}
float factorial(float factor)
{
	float total=1;
	for(float i=factor; i>=2;i--) 
		total=total*i;
	cout << "VALOR factorial = " << total << endl;
	return(total);
return(0);
}
float permutacio(float p, float r)
{
	cout << "VALOR TOTAL de lapermutació sense repetició" << factorial(p)/factorial(p-r) << endl;
	
	return(factorial(p)/factorial(p-r));
}
float permutacio_repeticio()
{
	float repeteix=0;
	float conta=0;
	float repeticio=0;
	float permut=0;
	float total=0;
	float ordre=0;
	cout << "Permutació amb repetició " << endl;
	cout << "Elements a ordenar :" << endl;
	cin >> ordre;
	cout << "Número de permutacions amb repetició ?" << endl;
	cin >> repeteix;
	conta=repeteix;
	repeteix=1;
	for(int i=0;i<conta;i++){
		cout << "Valor permutació " << i+1 << "\t:";
		cin >> permut;
		repeteix=repeteix*factorial(permut);
	}
	cout << "Elements a ordenar = " << ordre << " grups a fer = " << repeteix << endl;
	total=permutacio(ordre, repeteix)/repeteix;
//	total=total/repeteix;
	cout << "VALOR TOTAL DE LA PERMUTACIÓ AMB REPETICIÓ = " << total << endl;
	return(total);
}
