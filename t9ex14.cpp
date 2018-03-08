#include <iostream>

using namespace std;

#include "t9ex14.h"

int main(){
Money m;
cout << "14. Design and implement a Money class for calculations involving dollars and cents where"
	<< " arithmetic has to be accurate to the last cent using the 4/5 rounding rule (.5of a cent"
	<<" rounds up; anything less than .5rounds down). Represent a monetary amount as a number of"
	<< " cents in a long int, but input and output as dollars and cents, e.g., $123.45. Do not "
	<< " worry about amounts thatdon’t fit into a long int" << endl;
	cout << endl << "###################################################" << endl;
	cout << endl << "valor_total = " << m.valor_total << ", part entera = " << m.part_entera << ", part decimal = " << m.part_decimal << "." << endl;
	cout << endl << "###################################################" << endl;
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	m.setValor();
	cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl << "###################################################" << endl;
	m.getValor();
	cout << endl << "###################################################" << endl;
		
return(0);
}
