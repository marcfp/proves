#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	double a;
	string b;
	int trobat=1;
	double conversio; //1m = 100cm, 1in = 2,54cm, 1ft = 12in;
	double valor_total=0.0;
	int sumants=0.0;
	double petit=0.0;
	double gran=0.0;
	double pe_ant;	
	cout << "\n Estic al punt 7 de la pàgina 127 \n";
	cout << "\n Entra 1 número amb les unitats corresponents ( cm, m, in, ft)\n Per sortir escriu \"2|\"";
	int valor ;
	while(trobat ==1 ){
	//	getline(cin, a);
		cin.clear();
		do{
		cout << "\nEntra numero i unitats\t:\t" ;
		cin >> a >> b;
		}while(isdigit(a) && isalpha(b[0]) );
	//	if(debug ==1 )cout << " a = " << a << " b = " << b; 
//		int a1=atoi(a);
		pe_ant=a;
		if(b.find("cm") != string::npos && b.size()==2){ 
				//cout<< "\nM'has escrit cm!!!???";	 
				conversio=(float)a/100.0;
				pe_ant=conversio;
				cout << "\n la conversio a metres és " << conversio << " m \n"; 
				valor_total=valor_total+conversio;
				sumants++;
				if(conversio < pe_ant ) petit=conversio;
//				printf ("\nminim petit cm= %f, conversio = %f", petit,conversio);
                                if(conversio > gran) gran = conversio;
				}
		else if(b.find("m") != string::npos && b.size()==1){ 
				//cout << "\nM'has escrit m!!!???";
				conversio = (float)a;
				pe_ant=conversio;
				cout << "\n laconversio és el mateix!!, mira : " << conversio << " metres\n";
				valor_total=valor_total+conversio;
				sumants++;
				if(conversio < pe_ant ) petit = conversio;
//				printf ("\nminim metres= %f", petit);
                                if(conversio > gran) gran = conversio;
				}
		else if(b.find("in") != string::npos && b.size()==2){
//				cout <<"\nM'has escrit in!!???"; 
				conversio = (float)a*2.54*100;
				pe_ant=conversio;
				cout << "\n la conversió a metres és " << conversio << " m \n";
				valor_total=valor_total+conversio;
				sumants++;
				if(conversio < pe_ant ) petit = conversio;
//				printf ("\nminim inches= %f", petit);
                                if(conversio > gran) gran = conversio;
				}
		else if(b.find("ft") != string::npos && b.size()==2){ 
//				cout << "\nM'has escrit ft!!!???"; 
				conversio = (float)a*2.54*100/12; 
				pe_ant=conversio;
				cout << "\n la conversió a ft és " << conversio << " m \n";
				valor_total=valor_total+conversio;
				sumants++;
				if(conversio < pe_ant ) petit = conversio;
//				printf ("\nminim ft= %f", petit);
                                if(conversio > gran) gran = conversio;

				}
		else if(b.find("|") != string::npos ) cout <<"Adèu! ";
		else cout << "\nAquesta mesura : '"<< b <<"' no està suportada \n I'm so sorry! \n"; 
	if(b.find("|") != string::npos ) trobat =0;	
	else trobat =1;
	}
	cout << "total = " << valor_total << " número d'operacions fetes = " << sumants << ", el més petit és " << petit << ", el valor més gran és " << gran << "\n";
//	printf ("\nminim = %f", petit);*/
return(0);
}

