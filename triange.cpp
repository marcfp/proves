#include <iostream>
using namespace std;
class Triangle{
		float base, altura;
	public:
		void establir_valors(float, float);
		float area(){ return base*altura; }
};
void Triangle::establir_valors(float base1, float altura1){
	base = base1;
	altura=altura1;
}

int main(){
Triangle trian, trian2;
trian.establir_valors(3,5);
trian2.establir_valors(5,6);
cout << "area trian : " << trian.area() << endl;
cout << "Area trian2 : " << trian2.area() << endl;
return (0);
}
