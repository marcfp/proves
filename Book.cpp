#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
//#include <functional>


#include "Book.h"
//#include "Date.h"
using namespace std;

void introdueix_llibre(Book& book){

//      while(book.getsIsdn()!= "-1-1-1" ){ 
                cout << endl << "Introdueix llibre (per sortir introdueix algun valor igual a dins l'isdn, per exemple :'1 1 -1 a' " << endl;
//              book.g
                book.setIsdn();
//              if(book.getsIsdn()=="0") break;
                cout << endl << "book.getsIsdn =" << book.getsIsdn() << endl;
//              cout << endl << "book.getsIsdn () ==" << book.getsIsdn() << endl;
                string isdn=book.getsIsdn();
                string surt="-1";

//              cout  << endl << "string isdn = " << isdn << endl;
                if(isdn.find(surt) != string::npos) {
                        cout << endl << "s'ha escollit sortir, fora!!" << endl;
//                      break; //loop
                        exit; //
                 }
                 else{
                         book.setAutor();
                         book.getAutor();
                         book.setTitle();
                         book.getTitle();
                         book.date.setYear();
                         book.setChecked();
                         book.getChecked();
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
/*
//	while(book.getsIsdn()!= "-1-1-1" ){ 
		cout << endl << "Introdueix llibre (per sortir introdueix algun valor igual a dins l'isdn, per exemple :'1 1 -1 a' " << endl;
//		book.g
		book.setIsdn();
//		if(book.getsIsdn()=="0") break;
		cout << endl << "book.getsIsdn =" << book.getsIsdn() << endl;
//		cout << endl << "book.getsIsdn () ==" << book.getsIsdn() << endl;
		string isdn=book.getsIsdn();
		string surt="-1";
		
//		cout  << endl << "string isdn = " << isdn << endl;
		if(isdn.find(surt) != string::npos) {
			cout << endl << "s'ha escollit sortir, fora!!" << endl;
//			break; //loop
			exit; //
		}
		else{
		        book.setAutor();
		        book.getAutor();
	       		book.setTitle();
		        book.getTitle();
			book.date.setYear();
			book.setChecked();
			book.getChecked();
		}
//	}
*/
//	cout << endl << "Primer llibre " << book << endl;
//	cout << endl << "Segon llibre" << book1 << endl;
	cout << book;	
	cout << book1;
	book==book1;
	book!=book1;
  return (0);

}
 
