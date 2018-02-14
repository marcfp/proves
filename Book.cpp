#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
//#include <functional>


#include "Book.h"
//#include "Date.h"
using namespace std;

void introdueix_llibre(Book& book){

                cout << endl << "Introdueix llibre (per sortir introdueix algun valor igual a dins l'isdn, per exemple :'1 1 -1 a' " << endl;
                book.setIsdn();
                cout << endl << "book.getsIsdn =" << book.getsIsdn() << endl;
                string isdn=book.getsIsdn();
                string surt="-1";

                if(isdn.find(surt) != string::npos) {
                        cout << endl << "s'ha escollit sortir, fora!!" << endl;
                        exit; //
                 }
                 else{
			 book.setGenere();
			
                         book.setAutor();
                         
                         book.setTitle();
        
			 book.setChecked();
                 
                         book.date.setYear();
			book.p.setNomUser();
			book.p.set_tarjeta();
//			cout << endl << "Printa data" << endl;
//			book.date.printDate();
			cout << endl << "####################################################################"<< endl;
			cout << endl << "\t\t\t Dades del llibre entrat : \n" << endl;
			cout << endl << "Printa titol" << endl;
			cout << book.getTitle();
			cout << endl << "Printa Autor " << endl; //\n book.autor(book.cpp)== " << book.autor << endl;
			cout << book.getAutor();
			cout << endl << "printa Genere" << endl;
			book.getGenere();
			cout << endl << "printa deixat" << endl;
                        cout << book.getChecked();
			cout << endl<< "date.getDate()  " << endl;
			book.date.getDate();
			book.date.printDate();
//			book.p.setNomUser();
			book.p.getNomUser();
//			book.p.set_tarjeta();
			book.p.get_tarjeta();
			cout << endl << "última pregunta, ... " << endl;
			if(book.p.si_no_gastos_admin())	{ 
						book.p.set_gastos_admin();
						book.p.get_gastos_admin();
			}
			else cout << endl << "No té gastos d'administració " << endl;
                }
//      }


}

int main () {
	//vector<Book> book;
	Book book,book1;

	cout << endl << endl << "Books" << endl << endl;
	cout << endl << "book" << endl;
	introdueix_llibre(book);
	cout << endl << "book1" << endl;
	introdueix_llibre(book1);
	string isdn=book.getsIsdn();
	cout << endl << "book.getsIsdn() =" << book.getsIsdn() << endl;
	if(isdn.find("-1")==string::npos )cout << book ;
	else cout << endl << "No entro if(isdn)" << endl;
	cout << endl;
	isdn=book1.getsIsdn();	
	if(isdn.find("-1")==string::npos) {
		cout << book1 ;
		book==book1;
		book!=book1;
	}
	else{
		cout << endl << "No  entro if(isdn)2" << endl;
	}
//	cout << "Gastos administratius general = ";
//	cout << p.get_gastos_admin(); 
  return (0);

}
