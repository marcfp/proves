#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>
 

using namespace std;
class Money{
	long double valor_total;
public:
	int debug=0;
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
if(debug==0)	cout << "parametres = "<< parametres ; 
						string::size_type indexUSD1fi;
						string sub1ll;
						string::size_type indexUSD1 = parametres.find("USD");
//						cout << endl << "indexUSD1 =" << indexUSD1 << endl << " parametres.find(\"USD\")= " << parametres.find("USD") << endl;
						if(parametres.find("USD")>5) {
							indexUSD1 = parametres.find("DKK");
							indexUSD1fi = indexUSD1+3;
//						cout << "\n indexUSD1 (DKK)= " << indexUSD1 << endl;
							sub1ll =parametres.substr(indexUSD1,indexUSD1fi);
						}
						else{
							indexUSD1 = parametres.find("USD");
							indexUSD1fi = indexUSD1+3;
//                                                cout << "\n indexUSD1 = (USD)" << indexUSD1 << endl;
                                                        sub1ll =parametres.substr(indexUSD1,indexUSD1fi);
						}
//	cout << endl << "sub1ll = " << sub1ll << endl;
						const char * usd="USD";
						const char * dkk="DKK";
						const char * entrat="KKK";
						char * sortida;
						int n;
//	cout << "usd = " << usd << "\n dkk =" << dkk << "\n entrat = " << entrat << endl;
						entrat=sub1ll.c_str();
if(debug==0)						cout << "entrat fi = " << entrat << endl;
//	cout << "entrat = " << entrat << endl;
						string::size_type index_mes= parametres.find("+");
//	cout << endl << "indexUSD1fi = " << indexUSD1fi << " index_mes = " << index_mes << endl;
						string::size_type index_fi=index_mes-indexUSD1fi;
//	cout << "index_fi = " << index_fi << endl;
						string sub1n = parametres.substr(indexUSD1fi,index_fi);
//	cout << endl << "sub1n = " << sub1n << endl;
						float num1;
						if(strcmp(entrat,usd)==0){
if(debug==0)                                                        cout << endl << "Valor a convertir Usd sub1n = "<< sub1n << endl;
							//sub1n=to_string(atof(sub1n.c_str())*0.81);
							//https://ubuntuforums.org/showthread.php?t=800110
							float ve=stof(sub1n)*0.81;
							num1=stof(sub1n)*0.81;
if(debug==0)							cout << endl << "stof(sub1n)*0.81 =" << stof(sub1n)*0.81 << endl;
if(debug==0)							cout << endl << "calcul fet (sub1n usd) = " << sub1n << endl;
                                                }
                                                if(strcmp(entrat,dkk)==0){
if(debug==0)                                                        cout << endl << "Dkk és el valor a convertir sub1n = "<< sub1n << endl;
							//sub1n=to_string(atof(sub1n.c_str())*0.13);
							//https://ubuntuforums.org/showthread.php?t=800110
if(debug==0)							cout << endl << "sub1n=to_string(atof(sub1n)*0.13); = " << stof(sub1n)*0.13 << endl;
							num1=stof(sub1n)*0.13;
if(debug==0)                                                        cout << endl << "calcul fet (sub1n dkk)= " << sub1n << endl;	
                                                }

	
						string::size_type indexUSD2 = parametres.find("USD");
                                                string::size_type indexUSD2fi = indexUSD2+3;
//	  cout << "\n indexUSD2 = " << indexUSD2 << endl;
						string::size_type index_mes2= parametres.find("+");
						string::size_type index_total= parametres.length()-index_mes2;
if(debug==0)						        cout << "index_mes2 = " << index_mes2 << "\n index_total = " << index_total << endl;
                                                string sub2ll=parametres.substr(index_total, parametres.size());//parametres.substr(index_mes2+1,indexUSD2fi);
if(debug==0)							cout << endl << "sub2ll = " << sub2ll << endl;
						entrat=sub2ll.c_str();
if(debug==0)							cout << "entrat fi = " << entrat << endl;
//        cout << endl << "indexUSD2fi = " << indexUSD2fi << " index_mes2 = " << index_mes2 << endl;
                                               // string::size_type index_fi2=index_mes2-indexUSD2fi;
//        cout << "index_fi2 = " << index_fi2 << endl;
						//index_total=(parametres.length()-index_total)+4;
                                                string sub2n = parametres.substr(index_total+3,parametres.length());
if(debug==0)							cout << endl << "sub2n (LINEA 120) = " << sub2n << " entrat = " << entrat << " usd = " << usd << " dkk = " << dkk  << endl;
						
						
if(debug==0)							cout << endl << "(strcmp(entrat,usd)==0)=" << strcmp(entrat,usd) << endl;
						float num2;
						if(strcmp(entrat,usd)>0){
if(debug==0)                                                    cout << endl << "Valor a convertir Usd sub2n = "<< sub2n << endl;
							//sub2n=to_string(stof(sub2n.c_str())*0.81);
							//https://ubuntuforums.org/showthread.php?t=800110
if(debug==0)							cout << endl << "stof(sub2n.c_str())*0.81 =" << stof(sub2n)*0.81 << endl;
							num2=stof(sub2n)*0.81;
if(debug==0)                                                    cout << endl << "calcul fet(sub2n usd) = " << sub2n << endl;
                                                }   
                                                if(strcmp(entrat,dkk)>0){
if(debug==0)                                                    cout << endl << "Dkk és el valor a convertir sub2n = "<< sub2n << endl;
							//sub2n=to_string(stof(sub2n.c_str())*0.13);
							//https://ubuntuforums.org/showthread.php?t=800110
if(debug==0)							cout << "sub2n=to_string(stof(sub2n.c_str())*0.13)=" << stof(sub2n)*0.13 << endl;
							num2=stof(sub2n)*0.13;
if(debug==0)                                                    cout << endl << "calcul fet(sub2n dkk) = " << sub2n << endl;
                                                }
if(debug==0)							cout << "linea 119 stof(sub2n) = " << stof(sub2n) << " stof(sub1n) = " << stof(sub1n) << endl;
						float resultat_suma = num1+num2;//stof(sub2n)+stof(sub1n); //suma

						this->valor_total=resultat_suma;
						
	
				}
				
				
				if(parametres.find("-") < parametres.size() ) {
if(debug==0)	cout << "parametres = "<< parametres ; 
						string::size_type indexUSD1fi;
						string sub1ll;
						string::size_type indexUSD1 = parametres.find("USD");
//						cout << endl << "indexUSD1 =" << indexUSD1 << endl << " parametres.find(\"USD\")= " << parametres.find("USD") << endl;
						if(parametres.find("USD")>5) {
							indexUSD1 = parametres.find("DKK");
							indexUSD1fi = indexUSD1+3;
//						cout << "\n indexUSD1 (DKK)= " << indexUSD1 << endl;
							sub1ll =parametres.substr(indexUSD1,indexUSD1fi);
						}
						else{
							indexUSD1 = parametres.find("USD");
							indexUSD1fi = indexUSD1+3;
//                                                cout << "\n indexUSD1 = (USD)" << indexUSD1 << endl;
                                                        sub1ll =parametres.substr(indexUSD1,indexUSD1fi);
						}
//	cout << endl << "sub1ll = " << sub1ll << endl;
						const char * usd="USD";
						const char * dkk="DKK";
						const char * entrat="KKK";
						char * sortida;
						int n;
//	cout << "usd = " << usd << "\n dkk =" << dkk << "\n entrat = " << entrat << endl;
						entrat=sub1ll.c_str();
if(debug==0)						cout << "entrat fi = " << entrat << endl;
//	cout << "entrat = " << entrat << endl;
						string::size_type index_mes= parametres.find("+");
//	cout << endl << "indexUSD1fi = " << indexUSD1fi << " index_mes = " << index_mes << endl;
						string::size_type index_fi=index_mes-indexUSD1fi;
//	cout << "index_fi = " << index_fi << endl;
						string sub1n = parametres.substr(indexUSD1fi,index_fi);
//	cout << endl << "sub1n = " << sub1n << endl;
						float num1;
						if(strcmp(entrat,usd)==0){
if(debug==0)                                                        cout << endl << "Valor a convertir Usd sub1n = "<< sub1n << endl;
							//sub1n=to_string(atof(sub1n.c_str())*0.81);
							//https://ubuntuforums.org/showthread.php?t=800110
							float ve=stof(sub1n)*0.81;
							num1=stof(sub1n)*0.81;
if(debug==0)							cout << endl << "stof(sub1n)*0.81 =" << stof(sub1n)*0.81 << endl;
if(debug==0)							cout << endl << "calcul fet (sub1n usd) = " << sub1n << endl;
                                                }
                                                if(strcmp(entrat,dkk)==0){
if(debug==0)                                                        cout << endl << "Dkk és el valor a convertir sub1n = "<< sub1n << endl;
							//sub1n=to_string(atof(sub1n.c_str())*0.13);
							//https://ubuntuforums.org/showthread.php?t=800110
if(debug==0)							cout << endl << "sub1n=to_string(atof(sub1n)*0.13); = " << stof(sub1n)*0.13 << endl;
							num1=stof(sub1n)*0.13;
if(debug==0)                                                        cout << endl << "calcul fet (sub1n dkk)= " << sub1n << endl;	
                                                }

	
						string::size_type indexUSD2 = parametres.find("USD");
                                                string::size_type indexUSD2fi = indexUSD2+3;
//	  cout << "\n indexUSD2 = " << indexUSD2 << endl;
						string::size_type index_mes2= parametres.find("+");
						string::size_type index_total= parametres.length()-index_mes2;
if(debug==0)						        cout << "index_mes2 = " << index_mes2 << "\n index_total = " << index_total << endl;
                                                string sub2ll=parametres.substr(index_total, parametres.size());//parametres.substr(index_mes2+1,indexUSD2fi);
if(debug==0)							cout << endl << "sub2ll = " << sub2ll << endl;
						entrat=sub2ll.c_str();
if(debug==0)							cout << "entrat fi = " << entrat << endl;
//        cout << endl << "indexUSD2fi = " << indexUSD2fi << " index_mes2 = " << index_mes2 << endl;
                                               // string::size_type index_fi2=index_mes2-indexUSD2fi;
//        cout << "index_fi2 = " << index_fi2 << endl;
						//index_total=(parametres.length()-index_total)+4;
                                                string sub2n = parametres.substr(index_total+3,parametres.length());
if(debug==0)							cout << endl << "sub2n (LINEA 120) = " << sub2n << " entrat = " << entrat << " usd = " << usd << " dkk = " << dkk  << endl;
						
						
if(debug==0)							cout << endl << "(strcmp(entrat,usd)==0)=" << strcmp(entrat,usd) << endl;
						float num2;
						if(strcmp(entrat,usd)>0){
if(debug==0)                                                    cout << endl << "Valor a convertir Usd sub2n = "<< sub2n << endl;
							//sub2n=to_string(stof(sub2n.c_str())*0.81);
							//https://ubuntuforums.org/showthread.php?t=800110
if(debug==0)							cout << endl << "stof(sub2n.c_str())*0.81 =" << stof(sub2n)*0.81 << endl;
							num2=stof(sub2n)*0.81;
if(debug==0)                                                    cout << endl << "calcul fet(sub2n usd) = " << sub2n << endl;
                                                }   
                                                if(strcmp(entrat,dkk)>0){
if(debug==0)                                                    cout << endl << "Dkk és el valor a convertir sub2n = "<< sub2n << endl;
							//sub2n=to_string(stof(sub2n.c_str())*0.13);
							//https://ubuntuforums.org/showthread.php?t=800110
if(debug==0)							cout << "sub2n=to_string(stof(sub2n.c_str())*0.13)=" << stof(sub2n)*0.13 << endl;
							num2=stof(sub2n)*0.13;
if(debug==0)                                                    cout << endl << "calcul fet(sub2n dkk) = " << sub2n << endl;
                                                }
if(debug==0)							cout << "linea 119 stof(sub2n) = " << stof(sub2n) << " stof(sub1n) = " << stof(sub1n) << endl;
						float resultat_suma = num1-num2;//stof(sub2n)+stof(sub1n); //suma

						this->valor_total=resultat_suma;
						
	
				}

			/*	if(parametres.find("-") < parametres.size()){
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

				}*/
						
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
	string to_string(double arg1);
}; 
