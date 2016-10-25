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
/*vector<int> v(10);
vector<int>::iterator it;
it=v.begin();
it=it+4;
it=v.insert(it, 7);
//v(5)=7;
if(v.at(5)!=7) cout << "success!\n";
else cout << "Failed ?\n";
for(int i=0; i<v.size();++i)
cout << v[i] << " \n";
*/
//ex7
/*int cond =1;
if (cond) cout << "Success!\n"; else cout << "Fail!\n";*/
//ex8
/*bool c = true; 
if (c) cout << "Success!\n"; 
else cout << "Fail!\n";
*/
//ex9
/*string s = "ape"; 
bool c = "fool"<s; 
cout << "c = " <<c;
if (!c) cout << "Success!\n";
else cout << "False!\n";
*/
//ex10
string s = "ape"; 
if (s!="fool") cout << "Success!\n";
return(0);
}
