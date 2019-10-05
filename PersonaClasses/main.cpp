
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
    //int fills;
    //string noms_fills[200];
    //int pares;
    //string noms_pares[200];
    //int avies;
    //string noms_avies[4];
    //int cosines;
    //string noms_cosines[10000];
public:
    Persona(){
        
        edat=0;
        cout << endl << "Persona amb nom nul i edat 0 inicialitzada " << endl;
    }
    ~Persona(){                
        cout << endl << "Destructor Persona amb nom nul i edat 0 inicialitzada " << endl;
    }
    friend class Germa;
    
    friend class Fills;
    
    friend class Pares;
    
    friend class Avies; 
    
    friend class Cosines;
    
    
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
    Germa(){
        cout << endl << "constructor germa " << endl;   
    }
    ~Germa(){
        cout << endl << "destructor germa " << endl;   
    }
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
        
        cout << " El número de germans que has introduit el nom és  " << germans << endl;
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
class Fills{
    int fills;
    string noms_fills[200];
public:
    Fills(){
        cout << endl << "constructor Fills " << endl;   
    }
    ~Fills(){
        cout << endl << "destructor Fills " << endl;   
    }
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
    
    void set_noms_Fills(int numero_Fills){
        cin.ignore();        
        cout << endl << "Entra el nom del fill " << numero_Fills << " : " ;
        cin >> noms_fills[numero_Fills];        
    }
    
    void get_noms_Fills(/*int numero_Germans*/){
        cout << " El número de fills que has d'introduir el nom és  " << fills << endl;
        while(fills>=1){
            cout << endl << "El nom del fill "<< fills <<  " és " << noms_fills[fills];
            fills--;
            
        }
        cout << endl;        
    }   
};

class Pares{
    int pares;
    string noms_pares[200];
public:
    Pares(){
        cout << endl << "constructor Pares " << endl;   
    }
    ~Pares(){
        cout << endl << "destructor Pares " << endl;   
    }
    int get_numero_Pares(){
        return pares;
    }
    
    void set_numero_Pares(){
        cin.clear();
        cin.ignore();
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Entra el nombre de Pare/Mare  : ";
            cin>> pares;
            
        }while(cin.fail());                
    }
    
    void set_noms_Pares(int numero_Pares){
        cin.ignore();        
        cout << endl << "Entra el nom del Pare/Mare " << numero_Pares << " : " ;
        cin >> noms_pares[numero_Pares];        
    }
    
    void get_noms_Pares(/*int numero_Germans*/){
        cout << " El número de pares que has d'introduir el nom és  " << pares << endl;
        while(pares>=1){
            cout << endl << "El nom del pare "<< pares <<  " és " << noms_pares[pares];
            pares--;
            
        }
        cout << endl;        
    }   
    
};
class Avies{
    int avies;
    string noms_avies[4];
public:
    Avies(){
        cout << endl << "constructor Avies " << endl;   
    }
    ~Avies(){
        cout << endl << "destructor Avies " << endl;   
    }
    int get_numero_Avies(){
        return avies;
    }
    
    void set_numero_Avies(){
        cin.clear();
        cin.ignore();
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Entra el nombre d'Avies  : ";
            cin>> avies;
            
        }while(cin.fail());                
    }
    
    void set_noms_Avies(int numero_Avis){
        cin.ignore();        
        cout << endl << "Entra el nom de l'Avi/a " << numero_Avis << " : " ;
        cin >> noms_avies[numero_Avis];        
    }
    
    void get_noms_Avies(/*int numero_Germans*/){
        cout << " El número d'avis que has d'introduir el nom és  " << avies << endl;
        while(avies>=1){
            cout << endl << "El nom de l'avi "<< avies <<  " és " << noms_avies[avies];
            avies--;
            
        }
        cout << endl;        
    }    
};
class Cosines{
    int cosines;
    string noms_cosines[4];
public:
    Cosines(){
        cout << endl << "constructor Cosines " << endl;   
    }
    ~Cosines(){
        cout << endl << "destructor Cosines " << endl;   
    }
    
    
    int get_numero_Cosines(){
        return cosines;
    }
    
    void set_numero_Cosines(){
        cin.clear();
        cin.ignore();
        do{
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl << "Entra el nombre de Cosines  : ";
            cin>> cosines;
            
        }while(cin.fail());                
    }
    
    void set_noms_Cosines(int numero_Cosines){
        cin.ignore();        
        cout << endl << "Entra el nom del/de la Cosí/na " << numero_Cosines << " : " ;
        cin >> noms_cosines[numero_Cosines];        
    }
    
    void get_noms_Cosines(/*int numero_Germans*/){
        cout << " El número de cosins que has d'introduir el nom és  " << cosines << endl;
        while(cosines>=1){
            cout << endl << "El nom del cosi/cosina "<< cosines <<  " és " << noms_cosines[cosines];
            cosines--;
            
        }
        cout << endl;        
    }    
};
int main(int argc, char **argv) {
    Persona per1;
    Germa g1;
    Fills f1;
    Pares p1;
    Avies a1;
    Cosines c1;
    int conta=0;
    
    std::cout << "Entra la persona " << std::endl;
    per1.set_nom();
    per1.set_edat();
    std::cout << "La persona introduida és : " << std::endl;
    cout << per1.get_nom() << " amb l'edat de " <<    per1.get_edat() << endl;
    /*germans*/
    g1.set_numero_Germans();
    conta=g1.get_numero_Germans();
    while(conta>=1){
        g1.set_noms_Germans(conta);
        conta--;
    }
    g1.get_noms_Germans();
    /*fills*/
    f1.set_numero_Fills();
    conta=f1.get_numero_Fills();
    while(conta>=1){
         f1.set_noms_Fills(conta);
         conta--;
    }
    f1.get_noms_Fills();
    /*pares*/
    p1.set_numero_Pares();
    conta=p1.get_numero_Pares();
    while(conta>=1){
        p1.set_noms_Pares(conta);
        conta--;
    }
    a1.get_noms_Avies();
    /*avies*/
    a1.set_numero_Avies();
    conta=a1.get_numero_Avies();
    while(conta>=1){
        a1.set_noms_Avies(conta);
        conta--;
    }
    a1.get_noms_Avies();
    /*cosines*/
    c1.set_numero_Cosines();
    conta=c1.get_numero_Cosines();
    while(conta>=1){
        c1.set_noms_Cosines(conta);
        conta--;
    }
    c1.get_noms_Cosines();
    return 0;
}
