#include <string.h>
#include <string>
#include <stdio.h>
#include <vector>
 

using namespace std;
class Money{
	long double valor_total;
	string moneda;
	int debug=1;
	
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

	/*float calcula_valors(string parametres){
		char * pch;
		char operacions[]="+-";
		vector<char> valors;
		char caracters;
		return(2);
	}*/
	void setValorargs(int &argc, char *argv[]){ //, char argv){
		string caracter;
//		cout << endl << argc << endl;//2 ok, sino falla
		vector<string> params;
		string parametres;
		if(debug==0)cout << endl << "http://www.cplusplus.com/reference/string/string/compare/" << endl;
	try{
		if(argc==2){ 	
			for(int i=1; i< argc; i++){
					//cout << endl << "argument " << i << " = " << argv[i] << endl;
			
					params.push_back(argv[i]);//carrego l'array al vector params
				}
				parametres=params[0];
				size_t pos_suma = parametres.find("+");//trobo el primer
				size_t pos_resta = parametres.find("-");
				
				if(debug==0)cout << "pos_suma = " << pos_suma << " pos_resta = " << pos_resta << endl;
/*
http://en.cppreference.com/w/cpp/string/basic_string/substr
http://en.cppreference.com/w/cpp/string/basic_string/erase
*/				
				float resultat_suma;
				if(pos_suma < parametres.size() ) {
				    if(debug==0)	cout << "parametres = "<< parametres << " parametres.length() = " << parametres.length() << "pos_suma = " << pos_suma << " pos_resta = " << pos_resta << " parametres.size() = " << parametres.size() << " parametres[7]= " << parametres[7]<< " parametres.compare1(\"USD\")=" <<  parametres.compare("USD")<< " parametres.compare2(\"USD\")=" <<  parametres.compare("USD")<< "pos_inici = " << parametres.substr(0,pos_suma) << "pos_fi =" << parametres.substr(pos_suma+1, parametres.length()) <<  endl;

	    /*crear 2 substring a partir del +*/
				    string cad_inici ="";
				
				    string cad_fi = ""; 
				    int pos_USD1=-2, pos_DKK1=-2, pos_USDfi=-2, pos_DKKfi=-2;
				    float float_USD1=0, float_DKK1=0, float_DKKfi=0, float_USDfi=0;
				    cad_inici=parametres.substr(0,pos_suma);
				    cad_fi=parametres.substr(pos_suma+1, parametres.length());
				     if(debug==0)cout << endl << endl << endl << "cad_inici = " << cad_inici << "\ncad_fi =" << cad_fi <<  endl << " cad_inici.find(\"USD\")="<< cad_inici.find("USD") << endl << "cad_fi.find(\"USD\")="<< cad_fi.find("USD") << endl;
				
				    /* buscar la moneda de cada substring*/
				      /*aquí*/
				    if(cad_inici.find("USD")>parametres.length()){ 
					pos_DKK1=cad_inici.find("DKK");
					//if(pos_DKK1==-1) cout << endl << "ERROR!! ABORT!!! DKK1 FAILS"<< endl;
					if(pos_DKK1<parametres.length()){
						 if(debug==0)cout << "calculo valor dkk" << endl;
						 if(debug==0)cout << endl << "dkk1 parametres.substr(3,4) = " << parametres.substr(3,4) << endl;
						string val_dkk1=parametres.substr(3,4);
						 if(debug==0)cout << endl << "val_dkk1 = " << val_dkk1<< endl;
						float_DKK1=stof(val_dkk1)*0.13426;
						 if(debug==0)cout << endl << "float_dkk1 =" << fixed << setprecision(2) << float_DKK1 << endl;
						
					}
				    }
				    else {
					    pos_USD1=cad_inici.find("USD");
					    //if(pos_USD1==-1) cout << endl << "ERROR!! ABORT!!! USD1 FAILS"<< endl;
					    if(pos_USD1<parametres.length()){
						 if(debug==0)cout << "calculo valor usd" << endl;
						 if(debug==0)cout << endl << "usd1 parametres.substr(3,4) = " << parametres.substr(3,4) << endl;
						string val_usd1=parametres.substr(3,4);
						 if(debug==0)cout << "val_usd1 = " << val_usd1;
						float_USD1 = stof(val_usd1)*0.853776;
						 if(debug==0)cout << endl << "float_usd1 = " << fixed << setprecision(2) << float_USD1 << endl;
					    }
				    }
				    
				    if(cad_fi.find("USD")>parametres.length()){ 
					pos_DKKfi=cad_fi.find("DKK");
					//if(pos_DKKfi==-1) cout << endl << "ERROR!! ABORT!!! DKKfi FAILS"<< endl;
					if(pos_DKKfi<parametres.length()){
						 if(debug==0)cout << "calculo valor dkk fi" << endl;
						 if(debug==0)cout << endl << "dkkfi parametres.substr(11,13) = " << parametres.substr(11,13) << endl;
						string val_dkkfi=parametres.substr(11,13);
						 if(debug==0)cout << "val_dkkfi = " << val_dkkfi;
						float_DKKfi=stof(val_dkkfi)*0.13426;						
						 if(debug==0)cout << endl << "float_dkkfi =" << fixed << setprecision(2) << float_DKKfi << endl;
					}
				    }
				    else {
					    pos_USDfi=cad_fi.find("USD");
					    //if(pos_USD1==-1) cout << endl << "ERROR!! ABORT!!! USD1 FAILS"<< endl;
					    if(pos_USDfi<parametres.length()){
						 if(debug==0)cout << "calculo valor usd fi" << endl;
						 if(debug==0)cout << endl << "usd parametres.substr(11,13) = " << parametres.substr(11,13) << endl;
						string val_usdfi=parametres.substr(11,13);
						 if(debug==0)cout << "val_usdfi = " << val_usdfi;
						float_USDfi = stof(val_usdfi)*0.853776;
						 if(debug==0)cout << endl << "float_USDfi = " << fixed << setprecision(2) << float_USDfi << endl;
					    }
				    }
				    (this)->valor_total= float_DKK1+ float_DKKfi+float_USD1 +float_USDfi;
				    
				    if(debug==0) {
					cout << endl << "pos_DKK1 = " << pos_DKK1 << " pos_USD1 = " << pos_USD1 << endl;
					cout << endl << "pos_DKKfi = " << pos_DKKfi << " pos_USDfi = " << pos_USDfi << endl;
					cout << endl << "float_DKK1 = " << float_DKK1 << " float_USD1 = " << float_USD1 << endl;
					cout << endl << "float_DKKfi = " << float_DKKfi << " float_USDfi = " << float_USDfi << endl;
				    }
				    	  
				}
				    
				float resultat_resta;    
				if( pos_resta < parametres.size() ) {
				  
				    if(debug==0)	cout << "parametres = "<< parametres << " parametres.length() = " << parametres.length() << "pos_suma = " << pos_suma << " pos_resta = " << pos_resta << " parametres.size() = " << parametres.size() << " parametres[7]= " << parametres[7]<< " parametres.compare1(\"USD\")=" <<  parametres.compare("USD")<< " parametres.compare2(\"USD\")=" <<  parametres.compare("USD")<< "pos_inici = " << parametres.substr(0,pos_suma) << "pos_fi =" << parametres.substr(pos_suma+1, parametres.length()) <<  endl;

	    /*crear 2 substring a partir del +*/
				    string cad_inici ="";
				
				    string cad_fi = ""; 
				    int pos_USD1=-2, pos_DKK1=-2, pos_USDfi=-2, pos_DKKfi=-2;
				    float float_USD1=0, float_DKK1=0, float_DKKfi=0, float_USDfi=0;
				    cad_inici=parametres.substr(0,pos_resta);
				    cad_fi=parametres.substr(pos_resta+1, parametres.length());
				     if(debug==0)cout << endl << endl << endl << "cad_inici = " << cad_inici << "\ncad_fi =" << cad_fi <<  endl << " cad_inici.find(\"USD\")="<< cad_inici.find("USD") << endl << "cad_fi.find(\"USD\")="<< cad_fi.find("USD") << endl;
				
				    /* buscar la moneda de cada substring*/
				      /*aquí*/
				    if(cad_inici.find("USD")>parametres.length() ){ 
					pos_DKK1=cad_inici.find("DKK");
					//if(pos_DKK1==-1) cout << endl << "ERROR!! ABORT!!! DKK1 FAILS"<< endl;
					if(pos_DKK1<parametres.length()){
						 if(debug==0)cout << "calculo valor dkk" << endl;
						 if(debug==0)cout << endl << "dkk1 parametres.substr(3,3) = " << parametres.substr(3,4) << endl;
						string val_dkk1=parametres.substr(3,4);
						 if(debug==0)cout << endl << "val_dkk1 = " << val_dkk1<< endl;
						float_DKK1=stof(val_dkk1)*0.13426;
						 if(debug==0)cout << endl << "float_dkk1 =" << fixed << setprecision(2) << float_DKK1 << endl;
						
					}
				    }
				    else {
					    pos_USD1=cad_inici.find("USD");
					    //if(pos_USD1==-1) cout << endl << "ERROR!! ABORT!!! USD1 FAILS"<< endl;
					    if(pos_USD1<parametres.length()){
						 if(debug==0)cout << "calculo valor usd" << endl;
						 if(debug==0)cout << endl << "usd1 parametres.substr(3,4) = " << parametres.substr(3,4) << endl;
						string val_usd1=parametres.substr(3,4);
						 if(debug==0)cout << "val_usd1 = " << val_usd1;
						float_USD1 = stof(val_usd1)*0.853776;
						 if(debug==0)cout << endl << "float_usd1 = " << fixed << setprecision(2) << float_USD1 << endl;
					    }
				    }
				    
				    if(cad_fi.find("USD")>parametres.length()){ 
					pos_DKKfi=cad_fi.find("DKK");
					//if(pos_DKKfi==-1) cout << endl << "ERROR!! ABORT!!! DKKfi FAILS"<< endl;
					if(pos_DKKfi<parametres.length()){
						 if(debug==0)cout << "calculo valor dkk fi" << endl;
						 if(debug==0)cout << endl << "dkkfi parametres.substr(11,13) = " << parametres.substr(11,13) << endl;
						string val_dkkfi=parametres.substr(11,13);
						 if(debug==0)cout << "val_dkkfi = " << val_dkkfi;
						float_DKKfi=-stof(val_dkkfi)*0.13426;						
						 if(debug==0)cout << endl << "float_dkkfi =" << fixed << setprecision(2) << float_DKKfi << endl;
					}
				    }
				    else {
					    pos_USDfi=cad_fi.find("USD");
					    //if(pos_USD1==-1) cout << endl << "ERROR!! ABORT!!! USD1 FAILS"<< endl;
					    if(pos_USDfi<parametres.length()){
						 if(debug==0)cout << "calculo valor usd fi" << endl;
						 if(debug==0)cout << endl << "usd parametres.substr(11,13) = " << parametres.substr(11,13) << endl;
						 string val_usdfi=parametres.substr(11,13);
						 if(debug==0)cout << "val_usdfi = " << val_usdfi;
						float_USDfi = -stof(val_usdfi)*0.853776;
						 if(debug==0)cout << endl << "float_USDfi = " << fixed << setprecision(2) << float_USDfi << endl;
					    }
				    }
				    (this)->valor_total=float_DKK1+float_DKKfi+float_USD1+float_USDfi;
				    
				    if(debug==0){
				      cout << endl << "pos_DKK1 = " << pos_DKK1 << " pos_USD1 = " << pos_USD1 << endl;
				      cout << endl << "pos_DKKfi = " << pos_DKKfi << " pos_USDfi = " << pos_USDfi << endl;
				      cout << endl << "float_DKK1 = " << float_DKK1 << " float_USD1 = " << float_USD1 << endl;
				      cout << endl << "float_DKKfi = " << float_DKKfi << " float_USDfi = " << float_USDfi << endl;
				    }
				  
				}
						
				if(debug==0)cout << endl << "contingut del vector :(canvi de moneda i càlcul entre elles fet)" << endl;
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

	string getMoneda(){
		return(moneda);
	}

	
	~Money(){}

	Money operator+ (const Money& m2) const;
	Money operator- (const Money& m2) const;
	Money operatorX (const Money& m2) const;
	Money operator/ (const Money& m2) const;
	string to_string(double arg1);
	
	Money operator> ( Money& m2) const;
	//Money getMoneda();
}; 
