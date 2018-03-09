class Money{
	long double valor_total;
public:
	Money(){
		valor_total=0;
	}
	void setValor(){
		float valor_total1;
		cout << endl << "Entra un valor " << endl;
		cin >> valor_total1;
		valor_total= valor_total1;
	}
	float getValor_total(){
		return(valor_total);
	}
	 
	~Money(){}

	Money operator+ (const Money& m2) const;
	Money operator- (const Money& m2) const;
	Money operator* (const Money& m2) const;
	Money operator/ (const Money& m2) const;
}; 
