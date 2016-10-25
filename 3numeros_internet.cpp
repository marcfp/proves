#include<iostream>
using namespace std;
int main()
{
 int a,b,c,x,y,o,p,q;   /* declaracion variables */

// clrscr();                  /*************************/
 cout<<"\na : ";        /*                                       */
 cin>>a;                  /*                                        */
 cout<<"\nb : ";       /*   Ingreso de valores          */
 cin>>b;                  /*                                        */
 cout<<"\nc : ";        /*                                       */
 cin>>c;                  /*************************/
// getch();
 o=a; p=b;q=c;          /* "Backup" de valores ingresados para impresion final */
 if(c<b)
   {
    x=c;
    y=b;                /* comparacion entre el 3er y 2do valor */
    b=x;
    c=y;
   }
 if(b<a)
   {
    x=b;
    y=a;                /* comparacion entre el 2do y 1er valor */
    a=x;
    b=y;
   }
 if(c<b)
   {
    x=c;
    y=b;                /* comparacion entre el 3er y 2do valor */
    b=x;
    c=y;
   }
// getch();
 cout<<"Los numeros son: "<<o<<" "<<p<<" "<<q<<"\n";  /* Impresion valores originales */
 cout<<"Y ordenados son: "<<a<<" "<<b<<" "<<c<<"\n";  /* Impresion valores ordenados */
// getch();
return (0);
}
