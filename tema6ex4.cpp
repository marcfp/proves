#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int debug=0;

class Name_value {
public:
	string nom;
	int edat;
};
int main(){
	vector<Name_value> nv;
	vector<string> names;
	vector<int> scores;
	vector<int>::iterator it;
//	vector<string> noname;
	int zero=1;
	string nom;
//	int trobat=0;

//        noname.push_back("NoName");

	cout << "Entra nom edat així : Joe 17, acabaràs quan introdueixis NoName 0" << endl;
        cout << endl << "\nllegeixo\n" << endl;
	while(cin >> nom >> zero  /*&& trobat==0*/){
				Name_value nvdins; 
				nvdins.nom=nom;
				nvdins.edat=zero;
				nv.push_back(nvdins);
				if(nom=="NoName" && zero==0) break; //trobat=1; //forço trencament de bucle
	}

	cout << endl << "imprimeixo tots els valors (1 parella per linea)" << endl;
	for(int i=0; i<nv.size(); i++)
		cout << "i=" << i  << " " << nv[i].nom << " " << nv[i].edat << "\n";
		
return(0);
}
