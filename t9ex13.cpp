#include <iostream>


#include "t9ex13.h"

using namespace std;

int main(){
Rational r;
cout << endl << "falta simplificar les funcions resultants" << endl;
cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << endl << "#############################################" << endl;
cout << endl << "\tINICIALITZACIÓ DE LA CLASE\t" << endl;
cout << endl << r.divisor1 << "/" << r.dominador1 << endl;
cout << endl << r.divisor2 << "/" << r.dominador2 << endl;
cout << endl << "#############################################" << endl;
cout << " Entra dominador 1 " ; 
r.setDominador1();
cout << "\n\n\n Entra divisor 1 ";
r.setDivisor1();
cout << endl << "#############################################" << endl;
cout << " Entra dominador 2 " ; 
r.setDominador2();
cout << "\n\n\n Entra divisor 2 ";
r.setDivisor2();
cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << r.getDominador1() << endl;
cout <<  "--" << endl;
cout << r.getDivisor1() << endl << endl << endl;
cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << r.getDominador2() << endl;
cout << "--" << endl ;
cout << r.getDivisor2() << endl << endl << endl;
cout << "#############################################" << endl;
cout << "la suma és " << endl ;
cout << r.sumadominador() << endl;
cout << "--" << endl;
cout << r.sumadivisor() << endl;
cout << "#############################################" << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "la resta és " << endl ;
cout << r.restadominador() << endl;
cout << "--" << endl;
cout << r.restadivisor() << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "#############################################" << endl;
cout << "la multiplicació és " << endl;
cout << r.multiplicadominador() << endl;
cout << "--" << endl;
cout << r.multiplicadivisor() << endl;
cout << "#############################################" << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
cout << "la divisió és " << endl;
cout << r.divisiodominador() << endl;
cout << "--" << endl;
cout << r.divisiodivisor() << endl;
cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
if( r.igualtatdivisor() == r.igualtatdominador()){
	cout << "#############################################" << endl;
	cout << "fraccions iguals" << endl;
	cout << r.getDominador1() << "  " << r.getDominador2() << endl;
	cout <<  "--" <<  "=" << "--" <<  endl;
	cout << r.getDivisor1() << "  " << r.getDivisor2() <<endl << endl << endl;
	cout << "#############################################" << endl;
}
else{
	cout << "#############################################" << endl;
	cout << "fraccions diferents" << endl;
	cout << r.getDominador1() << "   " << r.getDominador2() << endl;
        cout <<  "--" <<  "!=" << "--" <<  endl;
        cout << r.getDivisor1() << "   " << r.getDivisor2() <<endl << endl << endl;
	cout << "#############################################" << endl;
}
r.igualfraccio();
r.valor();
return(0);
}
