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
	try{
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
	cout << "parametres = "<< parametres ; 
						string::size_type indexUSD1 = parametres.find("USD");
						string::size_type indexUSD1fi = indexUSD1+3;
	cout << "\n indexUSD1 = " << indexUSD1 << endl;
						string sub2ll =parametres.substr(indexUSD1,indexUSD1fi);
	cout << endl << "sub2ll = " << sub2ll << endl;
						string::size_type index_mes= parametres.find("+");
	cout << endl << "indexUSD1fi = " << indexUSD1fi << " index_mes = " << index_mes << endl;
						string::size_type index_fi=index_mes-indexUSD1fi;
	cout << "index_fi = " << index_fi << endl;
						string sub2n = parametres.substr(indexUSD1fi,index_fi);
	cout << endl << "sub2n = " << sub2n << endl;
						string::size_type indexUSD2 = parametres.find("USD");
                                                string::size_type indexUSD2fi = indexUSD2+3;
	cout << "\n indexUSD2 = " << indexUSD2 << endl;
						string::size_type index_mes2= parametres.find("+");
						string::size_type index_total= parametres.length()-index_mes2;
	cout << "index_mes2 = " << index_mes2 << "\n index_total = " << index_total << endl;
                                                string sub1ll=parametres.substr(index_mes2+1,indexUSD2fi);
        cout << endl << "sub1ll = " << sub1ll << endl;
//                                                string::size_type index_mes2= parametres.find("+");
        cout << endl << "indexUSD2fi = " << indexUSD2fi << " index_mes2 = " << index_mes2 << endl;
                                                string::size_type index_fi2=index_mes2-indexUSD2fi;
        cout << "index_fi2 = " << index_fi2 << endl;
						index_total=(parametres.length()-index_total)+4;
                                                string sub1n = parametres.substr(index_total,parametres.length());
        cout << endl << "sub1n = " << sub1n << endl;
						float resultat_suma = stof(sub1n)+stof(sub2n); //suma
//						string res_final_suma = to_string(resultat_suma)+ " " + sub1ll;
//						cout << "Resultat de la suma = " << res_final_suma << "Falta fer conversió del valor monetari!!" << endl;
						this->valor_total=resultat_suma;
						
	
				}
				if(parametres.find("-") < parametres.size()){
	cout << "parametres = "<< parametres ;
                                                string::size_type indexUSD1 = parametres.find("USD");
                                                string::size_type indexUSD1fi = indexUSD1+3;
        cout << "\n indexUSD1 = " << indexUSD1 << endl;
                                                string sub2ll =parametres.substr(indexUSD1,indexUSD1fi);
        cout << endl << "sub2ll = " << sub2ll << endl;
                                                string::size_type index_mes= parametres.find("-");
        cout << endl << "indexUSD1fi = " << indexUSD1fi << " index_mes = " << index_mes << endl;
                                                string::size_type index_fi=index_mes-indexUSD1fi;
        cout << "index_fi = " << index_fi << endl;
                                                string sub2n = parametres.substr(indexUSD1fi,index_fi);
        cout << endl << "sub2n = " << sub2n << endl;
                                                string::size_type indexUSD2 = parametres.find("USD");
                                                string::size_type indexUSD2fi = indexUSD2+3;
        cout << "\n indexUSD2 = " << indexUSD2 << endl;
                                                string::size_type index_mes2= parametres.find("-");
                                                string::size_type index_total= parametres.length()-index_mes2;
        cout << "index_mes2 = " << index_mes2 << "\n index_total = " << index_total << endl;
                                                string sub1ll=parametres.substr(index_mes2+1,indexUSD2fi);
        cout << endl << "sub1ll = " << sub1ll << endl;
//                                                string::size_type index_mes2= parametres.find("+");
        cout << endl << "indexUSD2fi = " << indexUSD2fi << " index_mes2 = " << index_mes2 << endl;
                                                string::size_type index_fi2=index_mes2-indexUSD2fi;
        cout << "index_fi2 = " << index_fi2 << endl;
                                                index_total=(parametres.length()-index_total)+4;
                                                string sub1n = parametres.substr(index_total,parametres.length());
        cout << endl << "sub1n = " << sub1n << endl;
                                                float resultat_suma = stof(sub1n)-stof(sub2n); //resta
//                                              string res_final_suma = to_string(resultat_suma)+ " " + sub1ll;
//                                              cout << "Resultat de la suma = " << res_final_suma << "Falta fer conversió del valor monetari!!" << endl;
                                                this->valor_total=resultat_suma;

				}
						
				cout << endl << "contingut del vector :(falta canvi de moneda i càlcul entre elles)" << endl;
				vector<string>::reverse_iterator rit = params.rbegin();
				for (; rit!=params.rend(); ++rit)     std::cout << endl << *rit << endl;
				//size_t params_suma=rit;
		}
		else{
			cout << endl << "Executem així per què funcioni : \"./t9ex15 1USD+2USD\"" << endl;
			
		}
	}
	catch(exception& e){
		cout << endl << "No funciona així el programa .... USD3+USD3 Ó USD3+DKK3 Ó DKK4.1+USD5.2" << endl;
		e.what();
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
