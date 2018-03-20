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

/*Money Money::getMoneda()const {
  
    //return(moneda);
}*/
//sobreescriture d'operadors
Money Money::operator>(  Money& m2) const{
		long double value;
		string moneda_entrada="";
		cout << endl << "sobrecarrega de l'operador \">\""<< endl;
		cout << endl << "Entra valor_total :" << endl;
		cin >> value;
		cout << endl << "Entra la moneda que és (USD ó DKK)" << endl;
		while(moneda_entrada.compare("USD")!=0 && moneda_entrada.compare("DKK")!=0){
		  cout << endl << "Entra la moneda que és (USD ó DKK)" << endl;
		  cin >> moneda_entrada;
		}
		m2.valor_total=value;
		m2.moneda=moneda_entrada;
		
		cout << " moneda = " << m2.getValor_total() << m2.moneda << endl;
		//val=this->valor_total;
	//	return(this->valor_total); 
		//return(Money(val));
//https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
//https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm
//https://www.tutorialspoint.com/cplusplus/binary_operators_overloading.htm
}
/*Money Money::operator <()const {
    cout << "El valor de la moneda és " << this.getValor_total() << " i la moneda és " << this.getMoneda() << endl;
}*/

int main(int argc, char* argv[]){
	Money m1, m2, mresultat;	
	Money m3;

	cout << "16. Define an input operator (>>) that reads monetary amounts with currency denominations, such " << endl;
	cout << "as USD1.23 and DKK5.00, into a Money variable. Also define a corresponding output operator " << endl;
cout << "(>>). " << endl;
	
	m1.operator>(m1);

	cout << "El valor de la moneda entrada és " << m1.getValor_total() << " i és " << m1.getMoneda() << endl ;
/*	
	m3.setValorargs(argc, argv);
	cout << " = " << fixed << setprecision(2) << m3.getValor_total() << " € " << endl;
*/
return(0);
}
