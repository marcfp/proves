#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

class Date{
// Private Members
//    private:
        //ha de ser public per accedir des del pare ?
        public:
        string month;
        string day;
        int diat;
        int anyt;
        int mest;
        int febrer;
    // Public Members
  //  public:
        // Default Constructor
        Date() {
                const int BASE_YEAR = 1900;
                time_t timer;
                tm * time;
                std::time(&timer);
                time = localtime(&timer);
                diat = time->tm_mday;

        }

        int setDay(int i, int j){
                int dia=0;
                if(j==31) {
                        while(dia<1 || dia > 31) {
                                cout << endl << "Mes de gener, març, maig, juliol,agost, octubre" << endl;
                                cout << endl << "Entra el número de dia que es va deixar el llibre " << endl;
                                while(!(cin >> dia)){
                                        if(cin.fail()){
                                                cin.clear();
                                                cin.ignore();
                                                cout << endl << "Error d'introducció.... El dia h " << endl;
                                        }
                                        else{
                                                diat=dia;
                                        }
                                }
                        }
                        diat=dia;
                }
                else if(j==30){
                        while(dia<1 || dia > 31) {
                                cout << endl << "Mes d'abril, juny, setembre, novembre " << endl;
                                cout << endl << "Entra el número de dia que es va deixar el llibr " << endl;
                                while(!(cin >> dia)){
                                        if(cin.fail()){
                                                cin.clear();
                                                cin.ignore();
                                                cout << endl << "Error d'introducció.... El dia h " << endl;
                                        }
                                        else{
                                                diat=dia;
                                        }
                                }
                        }
                        diat=dia;
                }
                else {
                        while(dia<1 || dia > febrer) {
                                cout << endl << "més de febrer ?"<< endl;
                                cout << endl << "Entra el número de dia que es va deixar el llibr " << endl;
                                while(!(cin >> dia)){
                                        if(cin.fail()){
                                                cin.clear();
                                                cin.ignore();
                                                cout << endl << "Error d'introducicó... el dia ha " << endl;
                                        }
                                        else{
                                                diat=dia;
                                        }
                                }
                        }
                        diat=dia;
                }
                return(dia);

        }

        int setMonth1(int traspas){
                int mes;
                cout << endl << "traspas = " << traspas << endl;
                do {
                        cout << endl << "Entra el mes de l'any que demanes aquest llibre " << endl ;
                        while(!(cin >> mes)){
                                if(cin.fail()){
                                        cin.clear();
                                        cin.ignore();
                                        cout << endl << "Error d'introducció... El més ha de ser " << endl; 
                                }
                                else{
                                        mest=mes;
                                }
                        }
                }while(mes<1 || mes >12);
                cout << "Número de mes k has escollit " << mes << endl;
                mest=mes;
                switch (mes)
                {
                        case 1:case 3: case 5: case 7 : case 8:  case 10 : case 12 :
                                setDay(1,31);
                                break;
                        case 4: case 6: case 11:
                                setDay(1,30);
                                break;
                        case 2:
                                setDay(1,febrer);
                                break;
                        default: cout << endl << "mes erroni " << endl;
                                break;
                }
        }

        int setYear(){
                int any;

                cout << endl << "Entra l'any que demanes aquest llibre" << endl;
                while(!(cin >> any)){
                        if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout << endl << "Error d'introducció... L'any ha de ser un nombre " << endl;
                        }
                        else {
                                anyt=any;
                        }
                }
                anyt=any;
                if(any%4==0 && any%100!=0){
                                cout << endl << " any de traspàs" << endl;
                                febrer=29;
                                setMonth1(febrer);
                }
                else {
                        if(any%400==0 ){
                                        cout << endl << " any de traspàs" << endl;
                                        febrer=29;
                                        setMonth1(febrer);
                        }

                        else {
                                cout << endl << "NORMAL" << endl;
                                febrer=28;
                                setMonth1(febrer);
                        }
                }
        }

/*        int printDate(){
                cout << endl << "dia =" << this->day << "this->diat =" << this->diat << "this->mo
                return (0);
        }
*/
/*        void getDate(){
                cout << "diat = " << diat << ", mest = " << mest << ", year =" << anyt << endl;
        }
*/
        int getDia(){
                return(diat);
        }

        int getMes(){
                return(mest);
        }
        string getMesString(){
                switch(mest){
                        case 1: return("Gener");break;
                        case 2: return("Febrer");break;
                        case 3: return("Març");break;
                        case 4: return("Abril");break;
                        case 5: return("Maig"); break;
                        case 6: return("Juny");break;
                        case 7: return("Juliol");break;
                        case 8: return("Agost"); break;
                        case 9: return("Setembre"); break;
                        case 10: return("Octubre"); break;
                        case 11: return("Novembre"); break;
                        case 12: return ("Desembre"); break;
                        default : return("error!!!!"); break;
                }
                return("error!!!!");
        }
        int getAny(){
                return(anyt);
        }
        // Destructor
        ~Date() {}

};

