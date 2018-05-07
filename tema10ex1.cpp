#include <iostream>
#include <fstream> 

#include <string>


#include <sstream>
/*
 1. Write a program that produces the sum of all the numbers in a file of whitespace-separated
integers.
*/
using namespace std;

  

int main(int argc, char **argv) {

  int valor;
  int total=0;
  fstream myfile ("numeros.txt");//a,std::ios_base::in);
  if (myfile.is_open())
  {
    cout << "fitxer obert" << endl;
    //float a;
    try{
        while (myfile >> valor)
        {
                cout << "valor = " << valor << endl ;
                total=total+valor;
        }
        cout << "valor total = " << total << endl;
        myfile.close();
    }
    catch(exception& e){
        cout << "error de tipus ?" << e.what();
    }
  }

  else cout << "Unable to open file numeros.txt for work. create this file first with numbers seperated by spaces" << endl; 
  
    
}
