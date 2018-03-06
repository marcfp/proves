#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctime>


#include "t9ex11.h"

using namespace std;
//https://www.codeproject.com/questions/592534/helpplustoplusfindoutplusweekplusnumberplusofplusy

/*int GetWeek	(          // Valid values:  
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
//	return (&date);
}
*/

int numSetmana(Date date, int resultat1)
{
int modulo_mes;
float numero_setmanes=0;
struct tm tm;
char timebuf[64];

memset(&tm, 0, sizeof tm);
//http://www.cplusplus.com/reference/ctime/tm/
tm.tm_sec=0;
tm.tm_min=0;
tm.tm_hour=0;
tm.tm_mday=date.getDia()-1;
tm.tm_mon=date.getMes()-1;
tm.tm_year=date.getAny();
tm.tm_isdst = -1;
mktime(&tm);
if (strftime(timebuf, sizeof timebuf, "%W", &tm) != 0) {
	numero_setmanes=atoi(timebuf)+1;
    cout << endl << "El número de setmana és " << numero_setmanes << endl;
  }

}

void calcula_dia(Date date)
{
int dia;
int mes;
int mesb;
int any;
int result1, result2, result3, result4, result5, resultatfinal;
int regular[]= {0,3,3,6,1,4,6,2,5,0,3,5};
int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};

	any=date.getAny();
        mes=date.getMes();
        dia=date.getDia()-1;
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
        cout << "mesb = " << mesb << " any = " << any << " dia = "  << dia << endl;
        result1=(any)%7;
        result2=(any)/4;
        result3=(3*(((any)/100)))/4;
        result4=(result2-result3)%7;
        result5=dia%7;
        resultatfinal=(result1+result4+mesb+result5)%7;

        switch(resultatfinal){
                case 0: cout << "Diumenge, el seguent dia laboral és dilluns, demà" << endl; break;
                case 1: cout << "Dilluns" << endl; break;
                case 2: cout << "Dimarts" << endl; break;
                case 3: cout << "Dimecres" << endl; break;
                case 4: cout << "Dijous" << endl; break;
                case 5: cout << "Divendres" << endl; break;
                case 6: cout << "Dissabte, el següent dia laboral és dilluns" << endl; break;
                default : cout << "error!!!!!!" << endl; break;
        }
}
int main(){
Date date;
int result1, any;
/*int dia;
int mes;
int mesb;
int any;
int result1, result2, result3, result4, result5, resultatfinal;
int regular[]= {0,3,3,6,1,4,6,2,5,0,3,5};
int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};*/
cout << endl << "T9EX11" << endl;
//duckduckgo ->  calcular el dia de la semana partir de la fecha  -> https://programador-apli.blogspot.com/2012/04/calcular-el-dia-de-la-semana-partir-de.html
//https://programador-apli.blogspot.com.es/2012/04/calcular-el-dia-de-la-semana-partir-de.html
//https://prograador-apli.blogspot.com.es/2012/04/calcular-el-dia-de-la-semana-partir-de.html

	date.setYear();
	calcula_dia(date);
	any=date.getAny();
	result1=(any)%7;
/*	mes=date.getMes();
	dia=date.getDia()-1;
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
	cout << "mesb = " << mesb << " any = " << any << " dia = "  << dia<< endl;
	result1=(any)%7;
	result2=(any)/4;
	result3=(3*(((any)/100)))/4;
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
*/
	//setmana 

	//int week = GetWeek(dia, mes, any);
	int week = numSetmana(date, result1);
	//cout << "dia " << dia << " de " << date.getMesString() << mes << " de l'any " << any << " és la setmana " << week  << endl;
return(0);
}

