#include <iostream>
#include <iomanip>
#include <math.h>
#include <string> //vector>
#include <cstdlib> 


using namespace std;

#include "t9ex15.h"

Money Money::operator/ (const Money& m2) const{
        Money m;
        //m.valor_total = this->valor_total / m2.valor_total;
	//cout << "Operació il·legal, les monedes no es divideixen, ja ho fa el govern" << m.valor_total << endl;
	m.valor_total=0;
        return(m);
}

Money Money::operatorX (const Money& m2) const{
        Money m;
        //m.valor_total = this->valor_total * m2.valor_total;
	//cout << "Operació il·legal, no sé multiplicar monedes ... me'n ensenyes ?" << m.valor_total << endl;
	m.valor_total=0;
        return(m);
}

Money Money::operator- (const Money& m2) const{
        Money m;
        m.valor_total=this->valor_total - m2.valor_total;
        return(m);
}

Money Money::operator+ (const Money& m2) const{
        Money m;
        m.valor_total=this->valor_total + m2.valor_total;

        return (m);
}
string to_string(double arg1){
  cout << "arg1 = " << arg1 << endl;
}


int main(int argc, char* argv[]){
	Money m1, m2;	
	Money m3;

	cout << "15. Refine the Money class by adding a currency (given as a constructor argument). Accept a " << endl;
	cout << "floating-point initializer as long as it can be exactly represented as a long int. Don’t accept " << endl;
	cout << "illegal operations. For example, Money*Money doesn’t make sense, and USD1.23+DKK5.00 " << endl;
	cout << "makes sense only if you provide a conversion table defining the conversion factor between U.S. " << endl;
	cout << "dollars (USD) and Danish kroner (DKK)." << endl;

	
	m3.setValorargs(argc, argv);
	cout << " = " << fixed << setprecision(2) << m3.getValor_total() << " € " << endl;
return(0);
}
