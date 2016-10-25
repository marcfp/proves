#include<iostream>
#include <string.h>
#include <vector>
using namespace std;
void write_vector(const vector<int>& V)
{
/*   cout << "The numbers in the vector are: " << endl;
  for(int i=0; i < V.size(); i++)
    cout << V[i] << " ";
*/
}

int main()
{
  int input;
  vector<int> V;
  cout << "Enter your numbers to be evaluated: " << endl;
  while(cin >> input){
  	V.push_back(input);
  }
 // write_vector(V);
  for(int i=0; i < V.size(); i++)
    cout << V[i] << " ";
  return 0;
}
