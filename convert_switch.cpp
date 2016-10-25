#include<iostream>
#include<cstring>
using namespace std;
int main()
{
double valor_final=0;
cout << "\nConverteixo yen, dolers a euro \n";
//double n;
int dolar =1;
float euro = 0.910445;
int yen =112;
double valor=0;
char lletra=' ';
cout << "Entra un valor de moneda \t";
cin >> valor ;
cout << "Entra la moneda " ;
cin >> lletra;
//if(lletra=='$'){
switch(lletra){
 case '$':	cout << "1 Dolar 0,911 €";
	valor_final = valor*0.911;
	cout << valor << " Dolars són " << valor_final << "\n";
	break;
case '&':
	valor_final = valor*0.00941570;
	cout << "Yen 1 & = 0,00941570 $";
	cout << valor << "Yen dón " << valor_final << "\n";
	break;
default :
	cout << "No hi ha cap moneda amb aquest valor\n";
	break;
}
return (0);
}
