#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
//#include <functional>


#include "name_pairs_nou.h"

using namespace std;

bool myfunction (const double& i,const double& j) { return i<j; }

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

	cout << endl << endl << endl << endl  << "Llegeix edats" << endl << endl << endl << endl;
	double val = name.size();
	vector<string>::iterator it_nom = name.begin();
	while(val >1){ 
		cout << endl << "Introdueix l'edat  de "<< *it_nom << " : " ;
		it_nom++;
		cin >> edat;
		set_age(edat);
		val--;
	}
	
};	

void Name_Pairs::print(){
//https://www.youtube.com/watch?v=ZTH328L5V-U
	vector<string>::iterator it_nom = name.begin();
	cout << endl << "Escriure dades" << endl;
	vector<double>::iterator it_age = age.begin();

	for(; it_nom != name.end()-1; it_nom++){
		cout << "Nom = " << *it_nom << endl;
		cout << "edat = " << *it_age << endl;
		it_age++;
	}
}

bool ordena (double a, double b) { return a<b; }
void Name_Pairs::sort(){
//https://es.stackoverflow.com/questions/41478/ordenar-dos-vectores-con-sort
	cout << endl << "Ordena els vectors" << endl;
//	sort(age.begin(), age.end());//,ordena(age.begin(), age.end());
//	sort(age.begin(), age.end(), myfunction);
	vector<double>::iterator it_age = age.begin(); //escriu el primer element entrat 
	vector<double>::iterator it_age_fi = age.end()-1;
//com ho puc fer per recorrer i ordenar els valors ?
	
	cout << endl << "age.begin = " << *it_age << "\nage.end = " << *it_age_fi << endl;
//	sort(age.begin(), age.end());
//	sort(begin(age), end(age));
//	sort(it_age, it_age_fi);	
//	sort( it_age, it_age_fi, myfunction);
//	sort(age.rbegin(), age.rend());
}

int main () {
	Name_Pairs np;

	cout << endl << endl << "NAME-PAIRS_NOU" << endl << endl;


//bucle per comparar valor diferent a 0, tant de nom com d'edat 
	cout << "Llegeix dades, primer es llegeixen els noms, després es llegeixen les edats, per finalitzar els nom, escriu 0, es llegiran el mateix nombre d'edats" << endl;	
	np.read_names();
	np.read_ages();

	np.print();

	np.sort();

	np.print();
  return (0);

}
