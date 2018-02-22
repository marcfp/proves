#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#include "Book.h"


using namespace std;

void introdueix_llibre(Book& book){

                cout << endl << "Introdueix llibre (per sortir introdueix algun valor igual a dins l'isdn, per exemple :'1 1 -1 a' " << endl;
                book.setIsdn();
                cout << endl << "book.getsIsdn =" << book.getsIsdn() << endl;
                string isdn=book.getsIsdn();
                string surt="-1";

                if(isdn.find(surt) != string::npos) {
                        cout << endl << "s'ha escollit sortir, fora!!" << endl;
                        exit; 
                 }
                 else{
			 book.setGenere();
			
                         book.setAutor();
                         
                         book.setTitle();
        
			 book.setChecked();
                
			 if(book.getChecked()==1 ){
                         	book.date.setYear();
				book.p.setNomUser();
				book.p.set_tarjeta();
		  	 }
			 else{
				cout << endl << "El llibre no esta en prestec" << endl;
			 }
			cout << endl << "####################################################################"<< endl;
			cout << endl << "\t\t\t Dades del llibre entrat : \n" << endl;
			cout << endl << "ISDN = " << book.getsIsdn() << endl;
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


}



int main () {
	//vector<Book> book;
	Book book,book1;
	Library lib;

	int num;
	cout << endl << endl << "Library books" << endl << endl;

	do{
	 do{
	       	cout << endl << " Escull una opció de les següents : " << endl;
		cout << endl << " 3 -> todo check_user_book_library " << endl;
	       	cout << endl << " 2 -> llibres" << endl;
		cout << endl << " 1 -> usuaris" << endl;
	       	cout << endl << " 0 -> sortir" << endl;
	       while (!(cin >> num))
	            {
	                    cin.clear();
        	            cin.ignore(80, '\n');
                	    cout << "Valor no vàlid, introdueix un valor del 0 al 2";
	            }
        	    cin.ignore(80, '\n');
	   }while(num<0 &&  num>4);
 	 switch(num){
                case 3 : lib.check_user_book_library();break;
                case 2 : lib.add_Books();break;
                case 1 : lib.add_Patrons();break;
		case 0 : break;
                default : break;
         }

	}while(num!=0);

/*	lib.add_Patrons();
	lib.push_back();
	lib.add_Books();
*/
  return (0);

}
