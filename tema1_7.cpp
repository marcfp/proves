#include<iostream>
using namespace std;
int main()
{

double a,b,c,aux;

cout << " Entra 3 nombres que te'ls ordeno " ;
cin >> a >> b >> c ;
if(a>b) {
	aux=a;
	a=b;
	b=aux;
}
cout << " a = " << a << " b = " << b << "\n";
if(b>c){
	aux=b;
	b=c;
	c=aux;
}
cout << " b = " << b << " c = " << c << "\n";

if(a>c) {
	aux=a;
	a=c;
	c=aux;
	if(a>b) {
        	aux=a;
	        a=b;
	        b=aux;
	}
	if(b>c){
	        aux=b;
	        b=c;
	        c=aux;
	}
	
}
if (a>b){
	aux=a;
        a=b;
        b=aux;

}
cout << "Els nombres ordenats són aquests : " << a << b << c << "\n.";
	return (0);
}
