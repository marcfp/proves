#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	/*double primer;
	double segon;
	double resultat;
	string operacio;*/
	int i;
	vector<string> lletra_num;
	vector<string> lletra_2_num;
	string zero="zero";
	string u="u";
	string dos="dos";
	string tres="tres";
	string quatre="quatre";
	string cinc="cinc";
	string sis="sis";
	string set="set";
	string vuit="vuit";
	string nou="nou";
	string nu="1";
	string nd="2";
	string nt="3";
	string nq="4";
	string nc="5";
	string nss="6";
	string nst="7";
	string nv="8";
	string nn="9";
	string nz="0";
	int numero;
	string lletres;



	lletra_num.push_back(zero); //zero
	lletra_num.push_back(u);  // ...
	lletra_num.push_back(dos);
	lletra_num.push_back(tres);
	lletra_num.push_back(quatre);
	lletra_num.push_back(cinc);
	lletra_num.push_back(sis);
	lletra_num.push_back(set);
	lletra_num.push_back(vuit);
	lletra_num.push_back(nou); // ... nou

	lletra_2_num.push_back(nz); //0
        lletra_2_num.push_back(nu); // ...
        lletra_2_num.push_back(nd); // ...
        lletra_2_num.push_back(nt); // ...
        lletra_2_num.push_back(nq); 
        lletra_2_num.push_back(nc);
        lletra_2_num.push_back(nss);
        lletra_2_num.push_back(nst);
        lletra_2_num.push_back(nv);
        lletra_2_num.push_back(nn); //9

	for (i=0; i<=lletra_num.size()-1; ++i)	{
		cout << "numero " << i << " és = a " << lletra_num[i] << endl;
	}
	do{
		cout << "Entra'm 1 número i et donaré l'equivalència amb lletres i viceversa: ";
		cin  >> numero;
	}while(isdigit(numero));
	cout << endl << " número = " << numero << endl;
	switch(numero)
	{
	case 0 : cout << "0 = " << lletra_num[numero] << endl;break;
	case 1 : cout << "1 = " << lletra_num[numero] << endl;break;
	case 2 : cout << "2 = " << lletra_num[numero] << endl;break;
	case 3 : cout << "3 = " << lletra_num[numero] << endl;break;
	case 4 : cout << "4 = " << lletra_num[numero] << endl;break;
	case 5 : cout << "5 = " << lletra_num[numero] << endl;break;
	case 6 : cout << "6 = " << lletra_num[numero] << endl;break;
	case 7 : cout << "7 = " << lletra_num[numero] << endl;break;
	case 8 : cout << "8 = " << lletra_num[numero] << endl;break;
	case 9 : cout << "9 = " << lletra_num[numero] << endl;break;
	default : cout << "no reconegut "<< endl; break;
	}

/*	for (i=0; i<=lletra_2_num.size()-1; ++i)  {
                cout << "numero " << i << " és = a " << lletra_num[i] << endl;
        }
*/	

	switch(numero)
        {
        case 0 : cout << "zero = " << lletra_2_num[numero] << endl;break;
        case 1 : cout << "u = " << lletra_2_num[numero] << endl;break;
        case 2 : cout << "dos = " << lletra_2_num[numero] << endl;break;
        case 3 : cout << "tres = " << lletra_2_num[numero] << endl;break;
        case 4 : cout << "quatre = " << lletra_2_num[numero] << endl;break;
        case 5 : cout << "cinc = " << lletra_2_num[numero] << endl;break;
        case 6 : cout << "sis = " << lletra_2_num[numero] << endl;break;
        case 7 : cout << "set = " << lletra_num[numero] << endl;break;
        case 8 : cout << "vuit = " << lletra_num[numero] << endl;break;
        case 9 : cout << "nou = " << lletra_num[numero] << endl;break;
        default : cout << "no reconegut "<< endl; break;
        }

return(0);
}
