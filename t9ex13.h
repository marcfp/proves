#include <iostream>
using namespace std;
class Rational { //fraccions
//https://numerosracionales.com/operaciones-de-numeros-racionales
public:
int dominador1;
int divisor1;
int dominador2;
int divisor2;
int dominadorsuma;
int divisorsuma;
int dominadorresta;
int divisorresta;
int dominadormult;
int divisormult;
int dominadordiv;
int divisordiv;

	Rational(){
		dominador1=0;
		divisor1=0;
		dominador2=0;
		divisor2=0;
	}
	void setDominador1(){
		int dominador1;
		cin >> dominador1;
		this->dominador1=dominador1;
	}
	int getDominador1(){
		return (this->dominador1);
	}
	void setDominador2(){
		int dominador2;
		cin >> dominador2;
		this->dominador2=dominador2;
	}
	int getDominador2(){
		return (this->dominador2);
	}
	void setDivisor1(){
		int divisor1;
		cin >> divisor1;
		this->divisor1= divisor1;
	}
	int getDivisor1(){
		return(this->divisor1); 
	}
	void setDivisor2(){
		int divisor2;
		cin >> divisor2;
		this->divisor2=divisor2;
	}

	int getDivisor2(){
		return(this->divisor2);
	}
	float sumadominador(){
		//3+1=0.95 
		//__ __
		//4+5
		//cout << "dominador1 =" << this->dominador1*(this->divisor2) << endl;
		//cout << "dominador2 =" << this->dominador2*(this->divisor1) << endl;
		
		return ((this->dominador1*(this->divisor2))+(this->dominador2*(this->divisor1)));
	} 
	float sumadivisor(){
//		cout << "divisor1 = " << this->divisor1 << "divisor2 =" << this->divisor2 << endl;
		//dominadorsuma=this->divisor1*this->divisor2;
		return(this->divisor1*this->divisor2);
	}
	float restadominador(){
		return ((this->dominador1*(this->divisor2))-(this->dominador2*(this->divisor1)));
	}
	float restadivisor(){
		return(this->divisor1*this->divisor2);
	}
	float multiplicadominador(){
		return(this->dominador1* this->dominador2);
	}
	float multiplicadivisor(){
		return(this->divisor1 * this->divisor2);
	}
	float divisiodivisor(){
		return(this->divisor1*this->dominador2);
	}
	float divisiodominador(){
		return(this->dominador1*this->divisor2);
	}
	float igualtatdivisor(){
		return(this->divisor2/this->divisor1);
	}
	float igualtatdominador(){
		return(this->dominador2/this->dominador1);
	}
	float igualfraccio(){
		cout << "Són iguals les fraccions ?" << endl;
		if(igualtatdivisor() == igualtatdominador() ) {
			cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << endl << "fraccions proporcionals amb una raó de " << igualtatdivisor() << endl;
			cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			//rao = igualtatdivisor();
		}
		else {
			cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
			cout << endl << "\tNo són equivalents les fraccions" << endl;
			cout << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
		}
	}
	float valor(){
		cout << endl << "#############################################" << endl;
		cout << endl << "valor de la suma de les fraccions és " << endl; 
		cout << sumadominador() << endl;
		cout << "--"<<" = " << sumadominador()/sumadivisor() << endl;
		cout << sumadivisor() << endl;
		cout << endl << "valor de la resta de les fraccions és " << endl; 
                cout << restadominador() << endl;
                cout << "--"<<" = " << restadominador()/restadivisor() << endl;
                cout << restadivisor() << endl;
		cout << endl << "valor de la multiplicacció de les fraccions és " << endl; 
                cout << multiplicadominador() << endl;
                cout << "--"<<" = " << multiplicadominador()/multiplicadivisor() << endl;
                cout << multiplicadivisor() << endl;	
		cout << endl << "valor de la divisió de les fraccions és " << endl;
                cout << divisiodominador() << endl;
                cout << "--"<<" = " << divisiodominador()/divisiodivisor() << endl;
                cout << divisiodivisor() << endl;
		cout << endl << "#############################################" << endl;
		
	}
	~Rational(){}
};
