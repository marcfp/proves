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
//		cout << endl << "Dins de la funció amb arguments" << endl;
//		cout << endl << "argc = " << argc << endl;
		for(int i=1; i<argc; i++){
//			cout << endl << argv[i] << endl;
			try{
				string val = argv[i];
				float valor=atoi(argv[i]);			
				if(val.find("USD")!= string::npos) {
					cout << "Moneda USD trobada" << endl;
					valor=atoi(argv[i]);
					cout << "valor = " << valor << endl;
				}
				else if(val.find("DKK") != string::npos){
					cout << "Moneda DKK trobada" << endl;
					valor=atoi(argv[i]);
					cout << "valor = " << valor << endl;
				}
					else{
						cout <<  "Moneda no reconeguda, valor 0" << endl;
						valor=0;
					}
				valor_total=valor_total+valor;
			}
			catch(exception& e){
			}
		}
//		cout << endl << "argv = " << argv << endl;
//		valor_total=argc;
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
