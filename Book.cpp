#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#include "Book.h"


/*

9. Create a Library class. Include vectors of Books and Patrons. Include a struct called
Transaction. Have it include a Book, a Patron, and a Date from the chapter. Make a vector of
Transactions. Create functions to add books to the library, add patrons to the library, and check
out books. Whenever a user checks out a book, have the library make sure that both the user and
the book are in the library. If they aren’t, report an error. Then check to make sure that the user
owes no fees. If the user does, report an error. If not, create a Transaction, and place it in the
vector of Transactions. Also write a function that will return a vector that contains the names
of all Patrons who owe fees.

*/



using namespace std;

int main(){
	Library lib;

	int num;

        cout << endl << endl << "BOOK'S Library " << endl << endl;

        do{
         do{
                cout << endl << " Escull una opció de les següents : " << endl;
                cout << endl << " 3 -> todo check_out_books_patrons <no fet>" << endl;
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
                case 3 : lib.check_out_books_patrons();break;
                case 2 : lib.list_Books();lib.add_Books();break;
                case 1 : lib.list_Patrons();lib.add_Patrons();break;
                case 0 : break;
                default : break;
         }

        }while(num!=0);


return(0);
}
