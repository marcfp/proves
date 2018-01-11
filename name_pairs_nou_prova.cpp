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
	name.push_back(nome);
	cout << "name.size = " << name.size();
}
void Name_Pairs::set_age(double edat){
	age.push_back(edat);
	cout << "age.size = " << age.size();
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
//	for(int i=0;i<name.size();i++) //cout << "i = " << i << "name.pop_back= " << name.pop_back << endl;
//		cout << /*" i = " << i << */" nom = " << name << " edat = " << age << endl;
		
}

void Name_Pairs::sort(){
	cout << endl << "Ordena els vectors" << endl;
}

int main () {
	Name_Pairs np;

	cout << endl << endl << "NAME-PAIRS_NOU" << endl << endl;


//bucle per comparar valor diferent a 0, tant de nom com d'edat
	np.read_names();
	np.read_ages();

//	cout (np.age.);	
	np.print();
		np.sort();
  return (0);

}
