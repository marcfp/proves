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

	void setValor(int &argc, char *argv[]){ //, char argv){
		string usd="USD";
		string dkk="DKK";
		for(int i=1; i<argc; i++){
			try{
				string val = argv[i];
				int operacio;
				if(val=="+") operacio=1;
				else if(val=="-") operacio=2;	
					else operacio=3;
				cout << endl << "val = " << val << " i= " << i << endl;
				float valor=atoi(argv[i]);		
				size_t found_usd=val.find(usd);	
				size_t found_dkk=val.find(dkk);
				if(found_usd!= string::npos) {
					cout << "Moneda USD trobada " << endl; 
					valor=ceilf((atoi(argv[i])*0.812352)*100)/100;
					if(valor==0) {
							found_usd=found_usd+3;
							string str_usd=val.substr(found_usd);
							//cout << endl << "str_usd = " << str_usd << endl;
							valor=ceilf((stoi(str_usd)*0.812352)*100)/100;
					}
					cout << "valor(usd) = " << valor << endl;
				}
				else if(found_dkk != string::npos){
			//		cout << "Moneda DKK trobada" << endl;
					valor=ceilf((atoi(argv[i])*0.855178)*100)/100;
					if(valor==0){
							found_dkk=found_dkk+3;
							string str_dkk= val.substr(found_dkk);
							//cout << endl << "str_dkk= " << str_dkk << endl;
							valor=ceilf((stoi(str_dkk)*0.855178)*100)/100;
					}
					cout << "valor(dkk) = " << valor << endl;
				}
					else{
						cout <<  "Moneda no reconeguda, valor 0" << endl;
						valor=0;
					}
				valor_total=valor_total+valor;//buscar operació en linea de comandes
				switch(operacio){
					case 1: cout << "operacio = " << operacio << endl; valor_total=valor_total+valor;break;
					case 2: cout << "operacio = " << operacio << endl; valor_total=valor_total-valor;break;
					default : cout << "OPERACIÓ NO VÀLIDA operacio ="<< operacio << endl; break;
				}
			}
			catch(exception& e){
					cout  << "error : " << e.what() << endl;
			}
		}
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
