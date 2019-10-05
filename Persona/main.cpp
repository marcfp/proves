
#include <iostream>
#include <string>
#include <limits>

/*
 Classe persona, i tots els seus derivats familiars
 * */
using namespace std;
class Persona{
    string nom;
    float edat;
    //int germans;
    //string noms_germans[200];
    int fills;
    string noms_fills[200];
    int pares;
    string noms_pares[200];
    int avies;
    string noms_avies[4];
    int cosines;
    string noms_cosines[10000];
public:
    Persona(){
        
        edat=0;
        cout << endl << "Persona amb nom nul i edat 0 inicialitzada " << endl;
    }
    friend class Germa;
    /*void set_numero_Germans(){
        cin.clear();
        cin.ignore();
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Entra el nombre de germans  : ";
            cin>> germans;
            
        }while(cin.fail());
        
        
    }
    void get_noms_Germans(/*int numero_Germans*//*){
        
        cout << " El número de germans que has d'introduir el nom és  " << germans << endl;
        while(germans>=1){
            cout << endl << "El nom del germà "<< germans <<  " és " << noms_germans[germans];
            germans--;
            
        }
        cout << endl;
        
    }
    int get_numero_Germans(){
        return germans;
    }
            
    void set_noms_Germans(int numero_germans){
        
        cin.ignore();
        
        cout << endl << " numero de germans = " << numero_germans << endl << "Entra el nom del germà : ";
        cin >>noms_germans[numero_germans];
        
    }*/
    int get_numero_Fills(){
        return fills;
    }
    void set_numero_Fills(){
        cin.clear();
        cin.ignore();
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Entra el nombre de fills  : ";
            cin>> fills;
            
        }while(cin.fail());
        
        
    }
    
    void set_noms_Fills(){
        //while(fills >=1){
            cout << endl << "Entra el nom del fill : ";
            cin >> noms_fills[fills];
        //    fills--;
        //}
    }
    void get_noms_Fills(/*int numero_Germans*/){
        if(fills>=1){
            cout << " El número de fills que has d'introduir el nom és  " << fills << endl;
            while(fills>=1){
                cout << endl << "El nom del fill "<< fills <<  " és " << noms_fills[fills];
                fills--;            
            }
            cout << endl;
        }        
    }
    void set_noms_Pares(){
        
        cout << endl << "Entra el nom del fill : ";
        getline(cin,noms_pares[0]);
    }
    void set_noms_Avies(){
        
        cout << endl << "Entra el nom del fill : ";
        getline(cin,noms_avies[0]);
    }
    void set_noms_Cosines(){
        
        cout << endl << "Entra el nom del fill : ";
        getline(cin,noms_cosines[0]);
    }
    void set_nom(){
        
        cout << endl << "Entra el nom de la persona : ";
        getline(cin,nom);
    }
    string get_nom(){
        return this->nom;
    }
    void set_edat(){
        
        cout << endl << "Entra l'edat de la persona : ";
        cin >> edat;
    }
    float get_edat(){
        return this->edat;
    }
};
class Germa{
    int germans;
    string noms_germans[200];
public:
    void set_numero_Germans(){
        cin.clear();
        cin.ignore();
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Entra el nombre de germans  : ";
            cin>> germans;
            
        }while(cin.fail());
        
        
    }
    void get_noms_Germans(/*int numero_Germans*/){
        
        cout << " El número de germans que has d'introduir el nom és  " << germans << endl;
        while(germans>=1){
            cout << endl << "El nom del germà "<< germans <<  " és " << noms_germans[germans];
            germans--;
            
        }
        cout << endl;
        
    }
    int get_numero_Germans(){
        return germans;
    }
            
    void set_noms_Germans(int numero_germans){
        
        cin.ignore();
        
        cout << endl << " numero de germans = " << numero_germans << endl << "Entra el nom del germà : ";
        cin >>noms_germans[numero_germans];
        
    }
};

int main(int argc, char **argv) {
    Persona p1;
    Germa g1;
    int conta=0;
    
    std::cout << "Entra la persona " << std::endl;
    p1.set_nom();
    p1.set_edat();
    std::cout << "La persona introduida és : " << std::endl;
    cout << p1.get_nom() << " amb l'edat de " <<    p1.get_edat() << endl;
    /*germans*/
    g1.set_numero_Germans();
    conta=g1.get_numero_Germans();
    while(conta>=1){
        g1.set_noms_Germans(conta);
        conta--;
    }
    g1.get_noms_Germans();
    /*fills*/
    p1.set_numero_Fills();
    conta=p1.get_numero_Fills();
    while(conta>=1){
         p1.set_noms_Fills();
         conta--;
    }
    p1.get_noms_Fills();
    return 0;
}
