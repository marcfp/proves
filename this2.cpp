#include <iostream>
using namespace std;

class Dummy {
  public:
    bool isitme (Dummy& param);
};

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}

int main () {
  Dummy a;
  Dummy* b = &a;
  Dummy *c;
  if ( c->isitme(a) )
    cout << "yes, &a is c\n";
  else cout << "&a != c" << endl;
  if(b->isitme(a)) cout << "yes, &a is the same as b" << endl;
  else cout << "&a !=b " << endl;
  return 0;
}
