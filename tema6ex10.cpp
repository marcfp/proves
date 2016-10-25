#include<iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
int main()
{
cout << " 10. A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to a vault. There are 60 possible numbers, and you need three different numbers for the combination. There are P(60,3) permutations for the combination, where P is defined by the formula where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1. Combinations are similar to permutations, except that the order of the objects doesn’t matter. For example, if you were making a “banana split” sundae and wished to use three different flavors of ice cream out of five that you had, you wouldn’t care if you used a scoop of vanilla at the beginning or the end; you would still have used vanilla. The formula for combinations is Design a program that asks users for two numbers, asks them whether they want to calculate permutations or combinations, and prints out the result. This will have several parts. Do an analysis of the above requirements. Write exactly what the program will have to do. Then, go into the design phase. Write pseudo code for the program, and break it into sub-components. This program should have error checking. Make sure that all erroneous inputs will generate good error messages.\n\n\n\t  Permutació = importa l'ordre dels elements \n permutació amb repetició = n^r \n Permutació sense repetició = n! / (n -r) ! \n\n\n\t Combinació = no importa l'ordre dels elements \n combinació amb repetició = (n + r -1) / ( r! * (n-1)! \n combinació sense repetició = (n!) / ( r ! ( n - r )!)" << endl ;



return (0);
}
