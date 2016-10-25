#include<iostream>
#include<stdlib.h>
#include <vector>
#include <string.h>
#include <limits>

using namespace std;

int main()
{
    // Maximo valor permitido para el tipo de dato double.
    double min = std::numeric_limits<double>::max();
	double gran = std::numeric_limits<double>::min() ;
	// int debug =0;
	double a;
	string b;
	int trobat=1;
	double conversio; //1m = 100cm, 1in = 2,54cm, 1ft = 12in;
	double valor_total=0;
	int sumants=0;

	vector<double> minim;	
	
    cout << "Ejercicio 9, pagina 126" << endl;
	cout << "Introduce el numero y sus unidades en ( cm, m, in, ft)" << endl;

	while(trobat ==1 )
    {
		cin.clear();
		do{
		    cout << "Introduce un valor y sus unidades\t:\t";
		    cin >> a >> b;
		}while(isdigit(a) && isalpha(b[0]) );
		
        //if(debug == 1 )
        //    cout << " a = " << a << " b = " << b; 
		
        if(b.find("cm") != string::npos && b.size()==2)
        { 
				conversio = a/(double)100.0; 
				cout << "la conversion es: " << conversio << " cm" << endl; 
        
				minim.push_back(conversio);
        }
        else if(b.find("m") != string::npos && b.size()==1)
        { 
				conversio = a;
				cout << "la conversion es: " << conversio << endl;
                
                valor_total += conversio;

				minim.push_back(conversio);
		}
		else if(b.find("in") != string::npos && b.size()==2)
        {
				conversio = a*2.54*100;
				cout << "la conversion es " << conversio << " in" << endl;

				minim.push_back(conversio);
		}
		else if(b.find("ft") != string::npos && b.size()==2)
        { 
				conversio = a*2.54*100/12; 
				cout << "\n la conversion es " << conversio << " ft" << endl;

				minim.push_back(conversio);
		}
		else  
        {
            cout << "Esta medida : '" << b << "' no esta soportada" << endl << "Lo siento" << endl; 
        }
        
	    if(b.find("|") != string::npos ) 
        {
            trobat =0;	
        } 
        else 
        {
            if(conversio<min)
                min = conversio;

            if(conversio>gran)
                gran = conversio;

            sumants++;
	    }
    }

    cout << "el menor valor de todos: " << min << endl;
    cout << "el mayor valor de todos: " << gran << endl;
    cout << "numero de valores introducidos: " << sumants << endl;
	cout << "suma total= " << valor_total << endl;
return(0);
}
