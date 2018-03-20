#include <iostream>
#include <iomanip>
#include <math.h>
#include <string> //vector>
#include <cstdlib> 


using namespace std;

#include "t9ex16.h"

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
	Money m1, m2, mresultat;	
	Money m3;

	cout << "16. Define an input operator (>>) that reads monetary amounts with currency denominations, such " << endl;
	cout << "as USD1.23 and DKK5.00, into a Money variable. Also define a corresponding output operator " << endl;
cout << "(>>). " << endl;
	
	
	m3.setValorargs(argc, argv);
	cout << " = " << fixed << setprecision(2) << m3.getValor_total() << " € " << endl;
return(0);
}
