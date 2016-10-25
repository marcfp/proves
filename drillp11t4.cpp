#include<iostream>
#include<stdlib.h>
#include <stdio.h>

#include <string.h>
using namespace std;
int main()
{
	int debug =0;
	char lletra='a';
	int i=1;
	/*while (lletra <='z'){*/
	for(lletra='a';lletra<='z';++lletra){
		cout << " lletra = "<< lletra << " numero =" << int(lletra) << endl;
	//	lletra=lletra+i;
	//	++i;
	}	
return(0);
}

