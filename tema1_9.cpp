#include<iostream>
#include<cstring>
#include<string>
#include<ctype.h>
using namespace std;
int main()
{
	string numero ="u" ;
	string zero = "zero";
	string u = "u";
	string dos = "dos";
	string tres = "tres";
	string quatre= "quatre";
	string surt = "-1";
//	cin >> numero;
        cout << "Entra un nombre del 0 al 4 amb lletres i t'ho retornaré amb número (\"-1\" per sortir),p.ex : u";
		
	while (numero.compare(surt)){ //strcmp(numero,surt)!=0){
//	 cout << "estic dins ?";
//		cout << "Entra un nombre del 0 al 4 amb lletres i t'ho retornaré amb número ";
		if(numero.compare(zero)==0) cout << "\n" << 0 << "\t zero \n";
		else if(numero.compare(u)==0) cout << "\n" << 1 << "\tu \n";
			else if(numero.compare(dos)==0) cout << "\n" << 2 << "\t dos \n";
				else if(numero.compare(tres)==0) cout << "\n" << 3 << "\t tres \n";
					else if(numero.compare(quatre)==0)cout << "\n" << 4 << "\t quatre \n" ;
						else cout << "\n" << "OIE PAYO!!! QUE NO TE ENTENDOOOOO !!!\n" ;
		cin >> numero;
/*		switch(numero){
		case (strcmp(numero, zero)==0): cout << "nombre " << 0 << " introduit " ; break;
		case (strcmp(numero, u)==0): cout << "nombre " << 1 << " introduit " ; break;
		case (strcmp(numero, dos)==0): cout << "nombre " << 2 << " introduit " ; break;
		case (strcmp(numero, tres)==0): cout << "nombre " << 3 << " introduit " ; break;
		case (strcmp(numero, quatre)==0): cout << "nombre " << 4 << " introduit " ; break;
		default : cout << "no el conec!! estúpid!!" ;
		}*/
	/*	if (strcmp(numero,zero)==0) cout << "numero " << 0 ;
		if (strcmp(numero,u)==0) cout << 1;
		if (strcmp(numero,dos)==0) cout << 2;
		if (strcmp(numero,tres)==0) cout << 3;
		if (strcmp(numero,quatre)==0) cout << 4;
*/
	}

	return (0);
}
