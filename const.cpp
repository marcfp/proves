#include <iostream>
using namespace std;

class MyClass {
  public:
    int x;
    MyClass(int val) : x(val) {}
    int get() {return x;}
};

int main() {
  const MyClass foo(50);
// foo.x = 20;            // not valid: x cannot be modified
  cout << foo.x << '\n';  // ok: data member x can be read
//  cout << "foo(x)= " << foo << endl;
 cout << endl << "http://www.cplusplus.com/doc/tutorial/templates/" << endl;
  return 0;
}
