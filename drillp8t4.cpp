#include<iostream>
#include<stdlib.h>
#include <stdio.h>

#include <string.h>
using namespace std;
int main()
{
	int debug =0;
	double valor;
	string moneda;
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
	if (moneda =="y") val_moneda=1;
	else if(moneda =="k") val_moneda=2;
	else if(moneda =="p") val_moneda=3;
		else val_moneda=0;
	if(debug==1)cout << "val_moneda = " << val_moneda;
	}while(valor<0 || val_moneda==0 );
	if(debug==1)cout << endl << "Moneda entrada = " << valor << " amb moneda = " << moneda << " val_moneda = " << val_moneda << endl;
	if(val_moneda ==1 ){
		conversio=valor*0.01;
		cout << valor <<" yens convertits a dolars = " << conversio << endl;	
	}	
	else if(val_moneda==2){ 
		conversio=valor*8.5;
                cout << valor <<" kroners convertits a dolars = " << conversio << endl;
	}
	else if(val_moneda==3){ 
		conversio=valor*1.31;
		cout << valor << " pounds convertits a dolars = " << conversio << endl;	
	}
	else {
	cout << "valor no reconegut " << endl;
	}
return(0);
}

