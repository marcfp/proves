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
/*string s = "ape"; 
if (s!="fool") cout << "Success!\n";
*/
//ex11
/*string s = "ape"; 
if (s!="fool") cout << "Success!\n";*/
//ex12
/*string s = "ape"; 
if (s+"fool"=="apefool") cout < "Success!\n";
*/
//ex13
//vector<char> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success!\n";
//ex14
//vector<char> v(5); for (int i=0; i<v.size(); ++i) ; cout << "Success!\n";
//ex15
//string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];
//ex16
//if (true) /*then*/ cout << "Success!\n"; else cout << "Fail!\n";
//ex17
//int x = 2000; char c = x; if (c==char(x)) cout << "Success!\n";
//ex18
//string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];
//ex19
//vector<int> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
//ex20
int i=0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success!\n";
return(0);
}
