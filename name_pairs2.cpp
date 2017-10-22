#include <iostream>
#include <vector>
using namespace std;

class Name_Pairs {
  public:
      string name;
      double age;
  
    void set_values (string, double);
  //  void get_values(Name_pairs);
};

void Name_Pairs::set_values (string nom, double edat) {
  name = nom;
  age = edat;
}

int main () {
  vector<Name_Pairs> namepairs;

  string nom="";
  double edat=1;
cout << "\nPer acabar el programa entra \" 0\" i surtiràs de l'introducció de dades i et mostraré tot el que has introduit\n" ;
while ( edat!=0){
  Name_Pairs tem;
 cout << "Entra el nom \t : "; 
cin >> nom;
 cout << "Entra l'edat \t : ";
cin >> edat;
//  tem.name="Hola Mundo";
//  tem.age = 10;
  tem.name=nom;//"hola";
  tem.age =edat;// 10;

namepairs.push_back(tem);

}
for(int i=0;i<namepairs.size();i++) cout << namepairs[i].name << ", " << namepairs[i].age << endl;

  return 0;
}


