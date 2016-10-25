#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int area (int length, int width)
// calculate are a of a re ctangle
{
	if(length <0 || width < 0) return(0);
	else return length*width;
	return(0);
}
int framed_area (int x, int y)
// calculate are a within frame
{
	if(x-2<0 || y-2<0) cout << "Area no negativa" << endl ;
	x=x-2;
	y=y-2;
	if(x>0 && y>0) return (area(x,y));
	else return(0);
	return(0);
}
int main()
{
int x = 3;
int y = 3;
int z = 4;
        int s1 = area (7,7);
int s2 = area (7,7);
int s3 = area (7,7);
int s4 = area (7,7);


/*if (x<=0) cout << "non-positive x" << endl;
 if (y<=0) cout << "non-positive y" << endl;*/
int area1;
if (x<=0 || y<=0) cout << "non-positive area() argument" << endl;
else{
	area1 = area (x,y);
}
if(z<=2) cout << "non-positive 2nd area() argument called by frame_area()" << endl;
int area2 = framed_area (7,z);
int area3 = framed_area (y,z);
double ratio = double(area1)/area3;
// convert to double to get
// floating-point division
	cout << "s2 = " << s2 << endl << "s3 = " << s3 << endl << "s4 = " << s4 << endl << "area1 = " << area1 << endl << "area2 = " << area2 << endl << "area3 = " << area3 << endl;
return (0);
}
/*5.5.1*/
