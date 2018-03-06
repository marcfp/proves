#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctime>

#include <iomanip>


#include "t9ex12.h"

using namespace std;

int numSetmana(Date date, int resultat1)
{
int modulo_mes;
float numero_setmanes=0;
struct tm tm;
struct tm tm_resta;
char timebuf[64];

memset(&tm, 0, sizeof tm);
memset(&tm_resta, 0, sizeof tm_resta);
//http://www.cplusplus.com/reference/ctime/tm/
tm.tm_sec=0;
tm.tm_min=0;
tm.tm_hour=0;
tm.tm_mday=date.getDia();
tm.tm_mon=date.getMes()-1;
tm.tm_year=date.getAny();
tm.tm_isdst = -1;
mktime(&tm);

tm_resta.tm_sec=1;
tm_resta.tm_min=0;
tm_resta.tm_hour=0;
tm_resta.tm_mday=1;
tm_resta.tm_mon=1;
tm_resta.tm_year=1970;
mktime(&tm_resta);

cout << "tm_resta.tm_mday = " << tm_resta.tm_mday << "tm_resta.tm_mon = " << tm_resta.tm_mon << "tm_resta.tm_year =" << tm_resta.tm_year << endl;
if (strftime(timebuf, sizeof timebuf, "%W", &tm) != 0) {
	numero_setmanes=atoi(timebuf)+1;
    cout << endl << "El número de setmana és " << numero_setmanes << endl;
  }
cout << "difftime = " << fixed << setprecision (60) << fixed <<  difftime(mktime(&tm),mktime(&tm_resta));
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
cout << endl << "T9EX12" << endl;
cout << endl << "es parteix de l'any 1970?" << endl;
	date.setYear();
	calcula_dia(date);
	any=date.getAny();
	result1=(any)%7;
	//setmana 

	int week = numSetmana(date, result1);
return(0);
}

