#include <iostream>
using namespace std;

class Dummy {
  public:
    //bool isitme (Dummy& param);
    static int n;
    Dummy(){ n++;};
};

/*bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}*/
int Dummy::n=0;

int main () {
  Dummy a;
  /*Dummy* b = &a;
  if ( b->isitme(a) )
    cout << "yes, &a is b\n";
*/
  Dummy b[5];

  cout << "a =" <<  a.n << endl;
  for(int i=0; i<5; i++){
  Dummy *c = new Dummy;

  cout << " i = " << i << endl << "Dummy::n =" <<  Dummy::n << endl;

  delete c;
   }
  return 0;
}
