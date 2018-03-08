#include <iostream>

using namespace std;

#include "t9ex14.h"

Money Money::operator + (const Money& m2) const{
Money m;
m.valor_total=this->valor_total+m2.valor_total;
return (m);
}

int main(){
Money m1,m2,m3;
cout << "14. Design and implement a Money class for calculations involving dollars and cents where"
	<< " arithmetic has to be accurate to the last cent using the 4/5 rounding rule (.5of a cent"
	<<" rounds up; anything less than .5rounds down). Represent a monetary amount as a number of"
	<< " cents in a long int, but input and output as dollars and cents, e.g., $123.45. Do not "
	<< " worry about amounts thatdon’t fit into a long int" << endl;
	cout << endl << "###################################################" << endl;
	cout << endl << "valor_total = " << m1.getValor_total() << endl ; //", part entera = " << m1.part_entera << ", part decimal = " << m1.part_decimal << "." << endl;
	cout << endl << "###################################################" << endl;
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	m1.setValor();
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl << "###################################################" << endl;
	cout << m1.getValor_total() << endl;
	cout << endl << "###################################################" << endl;
	m2.setValor();
	cout << m2.getValor_total();
 
	
	cout << endl << "Ha entrat algu a m3?" << endl;
	m3=m1+m2;
	cout << m3.getValor_total();
/*	cout << endl << "entra i " << endl;
	cin >> i;
	m1.getValor_total()*i;
	cout << "despres de multipliciar " << endl;
	cout << m1.getValor_total() << endl;*/
	cout << endl;
return(0);
}
