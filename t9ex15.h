#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>
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

	float calcula_valors(string parametres){
		char * pch;
		char operacions[]="+-";
		vector<char> valors;
		char caracters;
		return(2);
	}
	void setValorargs(int &argc, char *argv[]){ //, char argv){
		string caracter;
//		cout << endl << argc << endl;//2 ok, sino falla
		vector<string> params;
		string parametres;
	
		if(argc==2){ 	for(int i=1; i< argc; i++){
					//cout << endl << "argument " << i << " = " << argv[i] << endl;
			
					params.push_back(argv[i]);//carrego l'array al vector params
				}
				parametres=params[0];
				size_t pos_suma = parametres.find("+");//trobo el primer
				size_t pos_resta = parametres.find("-");
/*
http://en.cppreference.com/w/cpp/string/basic_string/substr
http://en.cppreference.com/w/cpp/string/basic_string/erase
*/
				if(parametres.find("+") < parametres.size() ) {
						while(pos_suma<=parametres.length()){
							parametres.substr(pos_suma);
							cout << "parametres.length() =" << parametres.length() << " == parametrs.size()=" << parametres.size() << endl;
							cout << " pos_suma = " << pos_suma << endl;
							string cad1=parametres.substr(parametres.size()-pos_suma);
							cout << "cad1 = " << cad1;
							params.push_back(cad1);
							cout << "params[1]= "<< params[1] ;
							pos_suma=pos_suma+5;
						}
				}
				if(parametres.find("-") < parametres.size()){
						while(pos_resta<=parametres.length()){
							parametres.substr(pos_resta);
                                                        cout << "parametres.length() =" << parametres.length() << " == parametrs.size()=" << parametres.size() << endl;
                                                        cout << " pos_suma = " << pos_suma << endl;
                                                        string cad1=parametres.substr(parametres.size()-pos_resta);
                                                        cout << "cad1 = " << cad1;
                                                        params.push_back(cad1);
                                                        cout << "params[1]= "<< params[1] ;
                                                        pos_resta=pos_resta+5;
						}
				}
						
				cout << endl << "contingut del vector :" << endl;
				vector<string>::reverse_iterator rit = params.rbegin();
				for (; rit!=params.rend(); ++rit)     std::cout << endl << *rit << endl;
				//size_t params_suma=rit;
		}
		else{
			cout << endl << "Executem així per què funcioni : \"./t9ex15 1+2+3-4-5-6\"" << endl;
			
		}
/*	
		string usd="USD";
		string dkk="DKK";
		string suma="+";
		string resta="-";
		
		for(int i=1; i<argc; i++){
			string valor_passat;
			valor_passat=valor_passat+argv[i];
			try{
				string val = argv[i];
				int operacio;
				//cout << endl << "val = " << val << " i= " << i << endl;
				int j=0;
				double valor;
				while(j<=argc){
					valor=0;//atoi(argv[i]);		
					size_t found_usd=val.find(usd);	
					size_t found_dkk=val.find(dkk);
					size_t found_mes=val.find(suma);
					size_t found_resta=val.find(resta);
					valor=0;
					cout << endl << "found_usd = " << found_usd << "\nfound_dkk = "<< found_dkk << "\nfound_mes = " << found_mes << "\n found_resta = " << found_resta << endl;
					cout << endl << " argv[i] = " << argv[i] << endl;
					if(found_usd!= string::npos) {
				//		cout << "Moneda USD trobada " << endl; 
						if(argv[i]=="U" && argv[i+1]=="S" && argv[i+2]=="D") {
								valor=ceil(((stoi(argv[i]))*0.812352)*100)/100;
								i=i+2;
								}
						if(valor==0) {
							found_usd=found_usd+3;
							string str_usd=val.substr(found_usd);
							cout << endl << "str_usd =" << str_usd  << endl;
							valor=ceil(((stoi(str_usd))*0.812352)*100)/100;
						}
						cout << "valor(usd) = " << valor << endl;
						this->valor_total=this->valor_total+valor;
					}
					if(found_dkk != string::npos){
				//		cout << "Moneda DKK trobada" << endl;
						if(argv[i]=="D" && argv[i+1]=="K" && argv[i+2]=="K"){
								valor=ceil((stoi(argv[i])*0.855178)*100)/100;
								i=i+2;
								}
						if(valor==0){
							found_dkk=found_dkk+3;
							string str_dkk= val.substr(found_dkk);
							cout << endl << "str_dkk =" << str_dkk << endl;
							valor=ceil(((stoi(str_dkk))*0.855178)*100)/100;
						}
						cout << "valor(dkk) = " << valor << endl;
					//	if(argv[i]!="D" && argv[i]!="K" )//valor_total=valor_total+valor;
						this->valor_total=this->valor_total+valor;
					}
					if(found_mes !=string::npos){
							cout << endl << "AIXÒ ÉS SUMA" << endl;
							if(argv[i]!="U" && argv[i+1]!="S" && argv[i+2]!="D" ){
                                                                valor=ceil((stoi(argv[i])*0.812352)*100)/100;
                                                                i=i+2;
                                                                this->valor_total=this->valor_total+valor;
							}
							if(argv[i]!="D" && argv[i+1]!="K" && argv[i+2]!="K"){
                                                                valor=ceil((stoi(argv[i])*0.855178)*100)/100;
                                                                i=i+2;
								this->valor_total=this->valor_total+valor;
                                                        } 	
					}else	if(found_resta!=string::npos){
								cout << endl << "ARA TOCA RESTA" << endl;
									
							if(argv[i]!="U" && argv[i+1]!="S" && argv[i+2]!="D" ) {
								valor=-ceil((stoi(argv[i])*0.812352)*100)/100;
	                                                        i=i+2;
								this->valor_total=this->valor_total+valor;
							}
							if(argv[i]!="D" && argv[i+1]!="K" && argv[i+2]!="K"){
                                                                valor=-ceil((stoi(argv[i])*0.855178)*100)/100;
                                                                i=i+2;
                                                                this->valor_total=this->valor_total+valor;
                                                        }  
						}
						//else {// valor_total=valor_total;
						//}
					
					j++;
				}
				this->valor_total=valor;
			}
			catch(exception& e){
					cout  << "error : " << e.what() << endl;
			}
		}
*/
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
