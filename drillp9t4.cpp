#include<iostream>
#include<stdlib.h>
#include <stdio.h>

#include <string.h>
using namespace std;
int main()
{
	int debug =0;
	double valor;
	char moneda;
/*onst char y="y";
	const char k="k";
	const char p="p";
*/
	int val_moneda=0;
	int trobat=1;
	double conversio; //1m = 100cm, 1in = 2,54cm, 1ft = 12in;
	cout << "\n Estic ala  pàgina 107 \n";
	do{
	cout << "\n Converteix yen (123.12y), kroner (123.12k) o pound (123.12p) a dollars."; 
	cout << endl << "Entra el valor de la moneda seguit de la moneda (com l'exemple de la línea de sobre) ";
	cin >> valor >> moneda;	
	/*if (moneda =="y") val_moneda=1;
	else if(moneda =="k") val_moneda=2;
	else if(moneda =="p") val_moneda=3;
		else val_moneda=0;*/
	switch(moneda){
	case 'y': conversio=valor*0.01;cout << valor <<" yens convertits a dolars = " << conversio << endl; break;
	case 'k':conversio=valor*8.5;
                cout << valor <<" kroners convertits a dolars = " << conversio << endl;break;
	case 'p': conversio=valor*1.31;
                cout << valor << " pounds convertits a dolars = " << conversio << endl;break;
	
	default :  cout << "valor no reconegut " << endl;break;
	}
	if(debug==1)cout << "val_moneda = " << val_moneda;
	}while(valor<0 );
	if(debug==1)cout << endl << "Moneda entrada = " << valor << " amb moneda = " << moneda << " val_moneda = " << val_moneda << endl;
return(0);
}

