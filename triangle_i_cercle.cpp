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
class Cercle {
		double radi;
	public:
		Cercle(double r) { radi = r; }
		double area_circumferencia() { return 2 * radi * 3.14159265;}
};
int main(){

//###Cercle
Cercle foo (10.); //forma funcional
Cercle bar = 20.0; //assignació inicial
Cercle baz {30.0}; // inicialització uniforme
Cercle qux = {40.0}; // Orientació a objecte

cout << "la circumenferencia de foo val " << foo.area_circumferencia() << endl;
cout << "la circumenferència de bar val " << bar.area_circumferencia() << endl;
cout << "la circumenferència de baz val " << baz.area_circumferencia() << endl;
cout << "la circumenferpencia de qux val " << qux.area_circumferencia() << endl;
//###fi Cercle


Triangle trian(3,4);
Triangle trian2;//(5,6);
//trian.establir_valors(3,5);
//trian2.establir_valors(5,6);
cout << "area trian : " << trian.area() << endl;
cout << "Area trian2 : " << trian2.area() << endl;
return (0);
}
