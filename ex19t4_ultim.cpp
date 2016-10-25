#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int debug=0;

class Name_value {
	vector<string> nom;
	vector<int> edat;
};
int main(){
	vector<string> names;
	vector<int> scores;
	vector<int>::iterator it;
	vector<string> noname;
	string zero="0";
	string nom;

        noname.push_back("NoName");

	cout << "Entra nom edat així : Joe 17, acabaràs quan introdueixis NoName 0" << endl;
        cout << endl << "\nllegeixo\n" << endl;
	while(cin >> nom) names.push_back(nom);
//	cout << "nom entrat = " << names[0];

	cout << endl << "imprimeixo tots els valors (1 parella per linea)" << endl;
	for(int i=0;i<names.size(); ++i) if(i %2 ==0) cout << "name ["<< i << "] = " << names[i];
	else cout << ", edat = (name[" << i << "]=)" << names[i] << "\n" ;
return(0);
}
