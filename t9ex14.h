class Money{
	float valor_total;
	int part_entera;
	int part_decimal;
public:
	Money(){
		valor_total=0;
		part_entera=0;
		part_decimal=0;
		//this->valor_total=0;
	}
	void setValor(){
		float valor_total1;
		cout << endl << "Entra un valor " << endl;
		cin >> valor_total1;
		valor_total=valor_total1;
	}
	float getValor_total(){
//		cout << endl << "El valor entrat és " << valor_total << endl;
		return(valor_total);
	}
	 
	~Money(){}

	Money operator + (const Money& m2) const;
/*	{
		Money m;
		m.valor_total=this->valor_total+m2.valor_total;
		return (m);
		Money resultat;
		resultat.valor_total=m1.valor_total+m2.valor_total;
		return resultat;

		return(m1.valor_total+m2.valor_total);
	}
	Money& operator * (const float& i){
		Money m;
		m.valor_total=i*(this->valor_total);
		return(m);
	}*/
};
 
