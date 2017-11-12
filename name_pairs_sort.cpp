#include <iostream>
#include <vector>
#include <algorithm>


#include "name_pairs.h"

using namespace std;

void Name_Pairs::set_nom(string nom_entrat)
{
	name=nom_entrat;
	
}

void Name_Pairs::set_age(double edat_entrada)
{
	age=edat_entrada;
}

bool ordena (Name_Pairs i, Name_Pairs j) { return (i.age<j.age); } 

int main () {

	vector<Name_Pairs> namepairs;
	Name_Pairs tem;
	
	cout << "\nPer acabar el programa entra \" 0\" i surtiràs de l'introducció de dades i et mostraré tot el que has introduit\n" ;
	//falta fer metode de lectura	
	while ( tem.age!='0' && tem.name!="0"){
		cout << "Entra el nom \t : ";
		string nom;
		cin >> nom;		//carrega a la variable
		tem.set_nom(nom);  //carrega a la clase
		cout << "Entra l'edat \t : ";
		double age;
		cin >> age;		//carrega a la variable
		tem.set_age(age); //carrega a la clase
		namepairs.push_back(tem); //carrega al vector
	}

	cout << endl << "Sense ordenar"<< endl;
	//falta fer metode print
	for(int i=0;i<namepairs.size();i++) cout << "Posició " << i << " conté : " << namepairs[i].name << ", " << namepairs[i].age << endl;
	cout << endl << "Ordenat" << endl;
	//funció d'ordenació.
	sort(namepairs.begin(), namepairs.end(), ordena);
	//falta fer mètode print
	cout << "namepairs.size()= " << namepairs.size() << endl; //<< "\n namepairs.end() =" << namepairs.end() << endl;
	for(int i=0;i<namepairs.size();i++) cout << "Posició " << i << " conté : " << namepairs[i].name << ", " << namepairs[i].age << endl; 
	
  return (0);

}
