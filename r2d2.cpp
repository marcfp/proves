// Ejemplo de uso en C++
#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    cout<<"Buscando astromech droids R2..."<<endl;
    for( int n=0 ; n<3; n++ ) {
        if ( strncmp ( str[n], "R2xx", 2) == 0 )
        {
            cout<<"Encontrado: "<<str[n]<<endl;
        }
    }
    return 0;
}
