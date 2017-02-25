#include <iostream>
using namespace std;
class Triangle{
		float base, altura;
	public:
		//void establir_valors(float, float);
		Triangle ();
		Triangle (float, float);
		float area(){ return base*altura; }
};
/*void Triangle::establir_valors(float base1, float altura1){
	base = base1;
	altura=altura1;
}
*/
Triangle::Triangle(){
base = 5;
altura=5;
}
Triangle::Triangle(float a, float b){
base = a; 
altura = b;
}
int main(){
Triangle trian(3,4);
Triangle trian2;//(5,6);
//trian.establir_valors(3,5);
//trian2.establir_valors(5,6);
cout << "area trian : " << trian.area() << endl;
cout << "Area trian2 : " << trian2.area() << endl;
return (0);
}
