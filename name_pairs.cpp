#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
//#include <functional>


#include "name_pairs.h"

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
	vector<string>::iterator it_nom = name.begin();
	cout << endl << "Escriure dades(ordenadas alfabéticament A .. Z)" << endl;
	vector<double>::iterator it_age = age.begin();

	if(name.size()>1){// si existeix alguna cosa ....
		for(; it_nom != name.end()-1; it_nom++){ //-1 erase last input 0
			cout << "Nom = " << *it_nom << endl;
			cout << "edat = " << *it_age << endl;
			it_age++;
		}
	}
	else{
		cout << endl << "No hi ha res a mostrar" << endl;
	}
}


void Name_Pairs::sort()
{
	for (int i = 0; i < name.size()-1; i++)
	{
		for (int j = 0; j < name.size()-1; j++)
		{
			if (i != j)
			{
				string t0 = name[i];
				string t1 = name[j];
				if (t0 < t1)
				{
					string t = name[i];
					name[i] = name[j];
					name[j] = t;

					double a = age[i];
					age[i] = age[j];
					age[j] = a;
				}
			}
		}
	}
}


int main () {
	Name_Pairs np;

	cout << endl << endl << "NAME-PAIRS_NOU" << endl << endl;

	cout << "Llegeix dades, primer es llegeixen els noms, després es llegeixen les edats, per finalitzar els nom, escriu 0, es llegiran el mateix nombre d'edats" << endl;	
	np.read_names();
	np.read_ages();
	
	cout << endl << "Dades introduides sense ordenar " << endl;
	np.print();
//	cout << endl << "Ordena" << endl;
	np.sort();

	cout << endl << "Dades introuides irdenades alfabéticament" << endl;
	np.print();

  return (0);

}
 
