#include <iostream>
#include <vector>
#include <algorithm>


#include "name_pairs_nou.h"

using namespace std;

void Name_Pairs::read_names(){
	string nome;
	cout << endl << "Llegeix noms" << endl;
	cout << endl << "Introdueix el nom : " ;
	cin >> nome;
	set_nom(nome);
//	set_nom(nom);	
/*	if (nom.length<=0){
			 cout << endl << "error d'introducció" << endl;
			 
			}
	else{
			cout << endl << "Anem bé" << endl;
			name_pairs.name=nom;

	}
*/
};
void Name_Pairs::set_nom(string nome){
	name = nome;
}
void Name_Pairs::set_age(double edat){
	age=edat;
}
void Name_Pairs::read_ages(){
	double edat;
	cout << endl << "Llegeix edats" << endl;
	cout << endl << "Introdueix l'edat : " ;
	cin >> edat;
	set_age(edat);
};	

void Name_Pairs::print(){
	cout << endl << "Escriure dades" << endl;
//	for(int i=0;i<size;i++)
		cout << /*" i = " << i << */" nom = " << name << " edat = " << age << endl;
		
}

void Name_Pairs::sort(){
	cout << endl << "Ordena els vectors" << endl;
}

int main () {
	Name_Pairs np;

	cout << endl << endl << "NAME-PAIRS_NOU" << endl << endl;

	np.read_names();
	np.read_ages();
	
	np.print();
		np.sort();
  return (0);

}
