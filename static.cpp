#include <iostream>
using namespace std;

class Dummy {
  public:
    static int n;
    Dummy () { n++; };
};

int Dummy::n=0;

int main () {
  Dummy a;
  Dummy b[5];
  cout <<  "a = " << a.n << endl;
for(int i=1; i<2; ++i){
	 Dummy * c = new Dummy;
	 cout << Dummy::n << endl;
	 delete c;
}
  return 0;
}
