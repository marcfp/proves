class Money{
public:
	float valor_total;
	int part_entera;
	int part_decimal;

	Money(){
		valor_total=0;
		part_entera=0;
		part_decimal=0;
	}
	void setValor(){
		cout << endl << "Entra un valor " << endl;
		cin >> valor_total;
	}
	void getValor(){
		cout << endl << "El valor entrat és " << valor_total << endl;
	}
	~Money(){}
};
