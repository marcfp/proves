#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
//#include <functional>


#include "Book.h"
//#include "Date.h"
using namespace std;



int main () {
	//vector<Book> book;
	Book book;

	cout << endl << endl << "Books" << endl << endl;
	/*
	book.isdn="123412341";
	cout << endl << "ISDN book = " << book.isdn << endl ;
	cout << endl << "book.ttile = " << book.title << endl;
	cout << endl << "book.autor = " << book.autor << endl;
	cout << endl << "Book.date.day = " << book.date.day << endl;
	cout << endl << "book.date.date = " << book.date.date << endl;
	cout << endl << "book.date.month = " << book.date.month << endl;
	cout << endl << "book.date.year = " << book.date.year << endl;
	
	book.setIsdn();
	book.getIsdn();
	book.setAutor();
	book.getAutor();
	book.setTitle();
	book.getTitle();
	book.date.setYear();
	cout << endl << "fora" << endl;
	*/
	do{
		cout << endl << "Introdueix llibres (per sortir introduir Isdn '-1'" << endl;
	//	book.
		book.setIsdn();
		if(book.getsIsdn()=="0") break;
		cout << endl << "book.getsIsdn () ==" << book.getsIsdn() << endl;
	        book.setAutor();
	        book.getAutor();
	        book.setTitle();
	        book.getTitle();
		book.date.setYear();
		book.setChecked();
		book.getChecked();
	}while(book.getsIsdn() !="0");
  return (0);

}
 
