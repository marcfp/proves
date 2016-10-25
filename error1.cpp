#include<iostream>
#include<stdlib.h>
#include <vector>
#include <string.h>
#include <limits>

using namespace std;

int main()
{
//detectar errors ; 
/*
EX 5
vector<int>::iterator it;

int res = 7; 
vector<int> v(10);
it=v.begin();
it=it+4; 
it=v.insert(it,7); 
cout << "Success!\n";
*/
//ex6
vector<int> v(10);
v(5)=7;
if(v(5)!=7) cout << "success!\n";

return(0);
}
