#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

int main ()
{

  // Create a sieve of ints, initially set to 1.
  int sievesize=0;
  cout << "Des de quin número vols buscar primers ?" ;
  cin >> sievesize;
// ++sievesize;
  vector<int, allocator<int> > sieve ((size_t)sievesize, 1);

  // At positions that are multiples of i, set value to zero.
  for (int i = 2; i * i <= sievesize; ++i)
    if (sieve[i])
	{
//	cout << sieve[i];
      for (int j = i + i; j <= sievesize; j = j + i)
        sieve[j] = 0;
	}

  // Now output all the values that are still set.
  for (int j = 2; j < sievesize; ++j)
    if (sieve[j]) 
      cout << j << " ";
    
  return 0;
}
