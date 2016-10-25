#include <iostream>
using namespace std;

main()
{
   unsigned int a = 60;	  // 60 = 0011 1100  
   unsigned int b = 13;	  // 13 = 0000 1101
   unsigned int c = 5;	
   int d = 0;           

   d = a & b;             // 12 = 0000 1100
   cout << "Line 1 - Value of c is : " << d << endl ;

   d = a | b;             // 61 = 0011 1101
   cout << "Line 2 - Value of c is: " << d << endl ;

   d = a ^ b;             // 49 = 0011 0001
   cout << "Line 3 - Value of c is: " << d << endl ;

   d = ~a;                // -61 = 1100 0011
   cout << "Line 4 - Value of c is: " << d << endl ;

   d = a << 2;            // 240 = 1111 0000
   cout << "Line 5 - Value of c is: " << d << endl ;

   d = a >> 2;            // 15 = 0000 1111
   cout << "Line 6 - Value of c is: " << d << endl ;
   d = a | b ^ c;
   cout << "Line 7 - Value of a | b ^ c is: " << d << endl;
   d = a | (b^c);
   cout << "Line 8 - Value of a | (b^c) is : " << d << endl;
   d = (a | b) ^ c;
   cout << "Line 9 - Value of (a | b) ^ c is : " << d << endl;
   d = a ^ b & c ;
   cout << "Line 10 - Value of a ^ b & c is: " << d << endl ; 
   d= a ^ (b & c);
   cout << "Line 11 - Value of a ^(b & c) is : " << d << endl;
   d = (a^b) & c; 
   cout << "Line 12 - Value of (a^b) & c is : " << d << endl;
   return (0);
}
