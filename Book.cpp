#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#include "Book.h"


using namespace std;

int main(){
	Library lib;

	int num;

        cout << endl << endl << "BOOK'S Library " << endl << endl;

        do{
         do{
                cout << endl << " Escull una opció de les següents : " << endl;
                cout << endl << " 3 -> todo check_user_book_library <no fet>" << endl;
                cout << endl << " 2 -> llibres" << endl;
                cout << endl << " 1 -> usuaris<no fet>" << endl;
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
 //               case 3 : lib.check_user_book_library();break;
                case 2 : lib.add_Books();lib.list_Books();break;
                case 1 : lib.add_Patrons();break;
                case 0 : break;
                default : break;
         }

        }while(num!=0);


return(0);
}
