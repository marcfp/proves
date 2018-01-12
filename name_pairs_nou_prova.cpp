#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#include "name_pairs_nou.h"

using namespace std;

void Name_Pairs::read_names(){// return int per printar ?
	string nome;
	string zero="0";
	while(nome.compare(zero)!=0) {
		cout << endl << "Llegeix noms" << endl;
		cout << endl << "Introdueix el nom : " ;
		cin >> nome;
		set_nom(nome);
	
	}
};
void Name_Pairs::set_nom(string nome){
	name.push_back(nome);
}

void Name_Pairs::set_age(double edat){
	age.push_back(edat);
}

void Name_Pairs::read_ages(){ //return int per printar ?
	double edat;
	cout << endl << "Llegeix edats" << endl;
	while(edat!=-1){
		cout << endl << "Introdueix l'edat : " ;
		cin >> edat;
		set_age(edat);
	}
	
};	

void Name_Pairs::print(){
//https://www.youtube.com/watch?v=ZTH328L5V-U
	vector<string>::iterator it_nom = name.begin();
	cout << endl << "Escriure dades" << endl;
	for(; it_nom != name.end(); it_nom++){
		cout << "Nom = " << *it_nom << endl;
	}
	vector<double>::iterator it_age = age.begin();
	for(; it_age != age.end(); it_age++){
		cout << "edat = " << *it_age << endl;
	}
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

	np.print();
		np.sort();
  return (0);

}
