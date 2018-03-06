#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctime>
#include <stdlib.h>

#include "t9ex11.h"

using namespace std;

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
int diarestat=0;
int mes;
int mesrestat=0;
int mesb;
int any;
int anyrestat=1700;
int result1, result2, result3, result4, result5, resultatfinal;
int regular[]= {0,3,3,6,1,4,6,2,5,0,3,5};
int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};
long int segons_totals;
long int segons_calculats;
segons_calculats = 60*60*24*365.25;//segons any
time_t now = time(0);
	cout << "time_now = " << now << "anyrestat =" << anyrestat << "diarestat" << diarestat << endl;
	any=date.getAny();
	anyrestat=abs(anyrestat-any)*segons_calculats;
        mes=date.getMes();
	cout << "Falta contar dies fins 1 de gener de cada mes";
	switch(mes){
	case 1: cout << endl << "Gener" << endl;break;
	case 2: cout << endl << "Febrer" << endl; break; //31dies
	case 3: cout << endl << "Març" << endl; break; //31+28dies o 31+29dies
	case 4: cout << endl << "Abril" << endl; break; //31+28+31dies
	case 5: cout << endl << "Maig" << endl; break; //31+28+31+30
	case 6: cout << endl << "Juny" << endl; break; //31+28+31+30+31
	case 7: cout << endl << "Juliol" << endl; break;//31+28+31+30+31+30
	case 8: cout << endl << "Agost" << endl; break;//31+28+31+30+31+30+31
	case 9: cout << endl << "Setembre" << endl; break;//31+28+31+30+31+30+31+30
	case 10: cout << endl << "Octubre" << endl; break;//31+28+31+30+31+30+31+30+30
	case 11: cout << endl << "Novembre" << endl; break;//31+28+31+30+31+30+31+30+30+31
	case 12: cout << endl << "Desembre" << endl; break;//31+28+31+30+31+30+31+30+30+31+30
	default : cout << "mes no introduit" << endl; break;
	}
	mesrestat=abs(mesrestat-mes);
	dia=date.getDia();
	diarestat=abs(diarestat-dia)*60*60*24;
	cout << "any restat(segons) = " << anyrestat << " mes restat (canviar a segons ?)" << mesrestat << " diarestat(en segons) = " << diarestat << endl;
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
cout << endl << "T9EX12 (not finished)" << endl;

	date.setYear();
	calcula_dia(date);
	any=date.getAny();
	result1=(any)%7;
	int week = numSetmana(date, result1);
return(0);
}

