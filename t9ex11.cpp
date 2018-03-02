#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#include "t9ex11.h"

using namespace std;

int main(){
Date date;
int dia;
int mes;
int any;
int result1, result2, result3, result4, result5, resultatfinal;
int regular[]= {0,3,3,6,1,4,6,2,5,0,3,5};
int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
cout << endl << "T9EX11" << endl;
//duckduckgo ->  calcular el dia de la semana partir de la fecha  -> https://programador-apli.blogspot.com/2012/04/calcular-el-dia-de-la-semana-partir-de.html
//https://programador-apli.blogspot.com.es/2012/04/calcular-el-dia-de-la-semana-partir-de.html
//https://prograador-apli.blogspot.com.es/2012/04/calcular-el-dia-de-la-semana-partir-de.html

	date.setYear();
	any=date.getAny();
	mes=date.getMes();
	dia=date.getDia();
	if((any%4==0) && !(any%100==0)){
		mes=bisiesto[mes-1];
	}
	else if(any%400==0)
		{
		mes=bisiesto[mes-1];
		}
		else{
			mes=regular[mes-1];
			}
	result1=(any-1)%7;
	result2=(any-1)/4;
	result3=(3*(((any-1)/100)+1))/4;
	result4=(result2-result3)%7;
	result5=dia%7;
	resultatfinal=(result1+result4+result5)%7;
	switch(resultatfinal){
		case 0: cout << "Diumenge" << endl; break;
		case 1: cout << "Dilluns" << endl; break;
		case 2: cout << "Dimarts" << endl; break;
		case 3: cout << "Dimecres" << endl; break;
		case 4: cout << "Dijous" << endl; break;
		case 5: cout << "Divendres" << endl; break;
		case 6: cout << "Dissabte" << endl; break;
		default : cout << "error!!!!!!" << endl; break;
	}
cout << "dia = " << dia << ", mes = " << mes << ", any = " << any << endl;
return(0);
}
