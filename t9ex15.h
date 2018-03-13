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
						string sub2 = parametres.substr(5,9);
						cout << sub2 << '\n';
    
						string sub2ll =sub2.substr(1,3);
						string sub2n = sub2.substr(0,1);
//						cout << "sub2ll = " << sub2ll << "\n";
//						cout << "sub2n = " << sub2n << "\n";  
						string sub1 = parametres.substr(0, 4);
						cout << sub1 << "\n";
						string sub1ll = parametres.substr(1,3);//unitat
						string sub1n = parametres.substr(0,1);//valor
//						cout << "sub1ll = " << sub1ll << "\n";
//						cout << "sub1n = " << sub1n << "\n";
						int resultat = stoi(sub1n)+stoi(sub2n);
						string res_final=to_string(resultat)+" "+sub1ll;
						cout << "resultat total (suma+ unitats) = " << res_final << endl;
						cout << "Falta fer la conversió a eurosi afegir més monedes, ara hi ha feta USD, falta fer FKK i que ho retorni tot amb € (euros)" << endl;
	
				}
				if(parametres.find("-") < parametres.size()){
						string sub2 = parametres.substr(5,9);
                                                cout << sub2 << '\n';
 
                                                string sub2ll =sub2.substr(1,3); 
                                                string sub2n = sub2.substr(0,1);
//                                              cout << "sub2ll = " << sub2ll << "\n";
//                                              cout << "sub2n = " << sub2n << "\n";  
                                                string sub1 = parametres.substr(0, 4);
                                                cout << sub1 << "\n";
                                                string sub1ll = parametres.substr(1,3);//unitat
                                                string sub1n = parametres.substr(0,1);//valor
//                                              cout << "sub1ll = " << sub1ll << "\n";
//                                              cout << "sub1n = " << sub1n << "\n";
                                                int resultat = stoi(sub1n)-stoi(sub2n);
                                                string res_final=to_string(resultat)+" "+sub1ll;
                                                cout << "resultat total (resta+ unitats) = " << res_final << endl;
						cout << "Falta fer la conversió a eurosi afegir més monedes, ara hi ha feta USD, falta fer FKK(fer amb switch?) i que ho retorni tot amb € (euros)multiplicar guardar a valor_total i ja estara)" << endl;

				}
						
				cout << endl << "contingut del vector :" << endl;
				vector<string>::reverse_iterator rit = params.rbegin();
				for (; rit!=params.rend(); ++rit)     std::cout << endl << *rit << endl;
				//size_t params_suma=rit;
		}
		else{
			cout << endl << "Executem així per què funcioni : \"./t9ex15 1+2+3-4-5-6\"" << endl;
			
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
