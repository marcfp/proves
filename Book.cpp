#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
//#include <functional>


#include "Book.h"
//#include "Date.h"
using namespace std;



int main () {
	Book book;

	cout << endl << endl << "Books" << endl << endl;
	book.isdn=123412341;
	cout << endl << "ISDN book = " << book.isdn << endl ;
	cout << endl << "Book.date =" << book.date.printDate() << endl;
	cout << endl << "book.ttile = " << book.title << endl;
	cout << endl << "book.autor = " << book.autor << endl;
	//book.
  return (0);

}
 
