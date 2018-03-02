#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctime>


#include "t9ex11.h"

using namespace std;
//https://www.codeproject.com/questions/592534/helpplustoplusfindoutplusweekplusnumberplusofplusy

int GetWeek	(          // Valid values:  
	int day,   // 1 to 31
	int month, // 1 to 12.  1 = Jan.
	int year   // 1970 to 3000
	)
{
	tm date = { 0 };
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	// We set time to sometime during the day (midday seems to make sense)
	// so that we don't get problems with daylight saving time.
	date.tm_hour = 12;
//	return GetWeek(&date);
	return (&date);
}


int main(){
Date date;
int dia;
int mes;
int mesb;
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
		mesb=bisiesto[mes-1];
	}
	else if(any%400==0)
		{
		mesb=bisiesto[mes-1];
		}
		else{
			mesb=regular[mes-1];
			}
	result1=(any-1)%7;
	result2=(any-1)/4;
	result3=(3*(((any-1)/100)+1))/4;
	result4=(result2-result3)%7;
	result5=dia%7;
	resultatfinal=(result1+result4+mesb+result5)%7;
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
	//setmana 

	int week = GetWeek(dia, mes, any);
	cout << "dia " << dia << " de " << date.getMesString() << mes << " de l'any " << any << " és la setmana " << week  << endl;
return(0);
}
