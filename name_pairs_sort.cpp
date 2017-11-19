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

void print (vector<Name_Pairs> &namepairs)
{

	for(int i=0; i<namepairs.size();i++){
		cout << " i = " << i << " namepairs[i].name = " << namepairs[i].name << ", namepairs[i].age =" << namepairs[i].age << endl;
	}
}

void llegir (vector<Name_Pairs> &namepairs, Name_Pairs &tem)
{
 while ( tem.age!='0' && tem.name!="0"){
                cout << "Entra el nom \t : ";
                string nom;
                cin >> nom;             //carrega a la variable
                tem.set_nom(nom);  //carrega a la clase
                cout << "Entra l'edat \t : ";
                double age;
                cin >> age;             //carrega a la variable
                tem.set_age(age); //carrega a la clase
                namepairs.push_back(tem); //carrega al vector
        }




}

int main () {

	vector<Name_Pairs> namepairs;
	Name_Pairs tem;
	
	cout << "\nPer acabar el programa entra \" 0\" i surtiràs de l'introducció de dades i et mostraré tot el que has introduit\n" ;
	
	llegir(namepairs, tem);
	
	cout << endl << "Sense ordenar"<< endl;

	print(namepairs);
	cout << endl << "Ordenat" << endl;

		//funció d'ordenació.

	sort(namepairs.begin(), namepairs.end(), ordena);

		//cout << "namepairs.size()= " << namepairs.size() << endl; 

	print(namepairs);
  return (0);

}
