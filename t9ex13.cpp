#include <iostream>


#include "t9ex13.h"

using namespace std;

int main(){
Rational r;

cout << endl << r.divisor1 << "/" << r.dominador1 << endl;
cout << endl << r.divisor2 << "/" << r.dominador2 << endl;
cout << " Entra dominador 1 " ; 
r.setDominador1();
cout << "\n\n\n Entra divisor 1 ";
r.setDivisor1();

cout << " Entra dominador 2 " ; 
r.setDominador2();
cout << "\n\n\n Entra divisor 2 ";
r.setDivisor2();

cout << r.getDominador1() << endl;
cout <<  "--" << endl;
cout << r.getDivisor1() << endl << endl << endl;

cout << r.getDominador2() << endl;
cout << "--" << endl ;
cout << r.getDivisor2() << endl << endl << endl;
cout << "la suma és " << endl ;
cout << r.sumadominador() << endl;
cout << "--" << endl;
cout << r.sumadivisor() << endl;
cout << "la resta és " << endl ;
cout << r.restadominador() << endl;
cout << "--" << endl;
cout << r.restadivisor() << endl;
cout << "la multiplicació és " << endl;
cout << r.multiplicadominador() << endl;
cout << "--" << endl;
cout << r.multiplicadivisor() << endl;
cout << "la divisió és " << endl;
cout << r.divisiodominador() << endl;
cout << "--" << endl;
cout << r.divisiodivisor() << endl;
return(0);
}
