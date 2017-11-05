#include <iostream>
#include <vector>

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


/*void Name_Pairs::get_values(vector<Name_Pairs> rebut){
	for(int i=0;i<rebut.size();i++) {
              cout <<" posició" << i<< "conté " << rebut[i].name << ", " << rebut[i].age << endl;
        }

}
*/
int main () {
	vector<Name_Pairs> namepairs;
	Name_Pairs tem;
	
	cout << "\nPer acabar el programa entra \" 0\" i surtiràs de l'introducció de dades i et mostraré tot el que has introduit\n" ;
	
	while ( tem.age!=0){
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

	
//	get_values(namepairs);
	for(int i=0;i<namepairs.size();i++) cout << "Posició " << i << " conté : " << namepairs[i].name << ", " << namepairs[i].age << endl;
		
  return 0;
}

