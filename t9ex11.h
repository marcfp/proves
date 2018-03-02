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


	void next_workday(){
		int dia;
		int mes;
		int any;
		int result1, result2, result3, result4, result5, resultatfinal;
		int regular[]= {0,3,3,6,1,4,6,2,5,0,3,5};
		int bisiesto[]={0,3,4,0,2,5,0,3,6,1,4,6};

		any=this->getAny();//date.getAny();
	        mes=this->getMes();//date.getMes();
        	dia=this->getDia();//date.getDia();
	        if((any%4==0) && !(any%100==0)){
        	        mes=bisiesto[mes-1];
	        }
        	else if(any%400==0)
	                {
        	        mes=bisiesto[mes-1];
	                }
                	else{
                        	mes=regular[mes-1];
        	               }
	        result1=(any-1)%7;
        	result2=(any-1)/4;
	        result3=(3*(((any-1)/100)+1))/4;
	        result4=(result2-result3)%7;
	        result5=dia%7;
	        resultatfinal=(result1+result4+mes+result5)%7;
		cout << endl << endl << "El dia " << dia << " del mes = " << mes << " de l'any = " << any << " cau en : " << endl;
	        switch(resultatfinal){
	                case 0: cout << "Diumenge" << endl; break;
	                case 1: cout << "Dilluns" << endl; break;
	                case 2: cout << "Dimarts" << endl; break;
	                case 3: cout << "Dimecres" << endl; break;
	                case 4: cout << "Dijous" << endl; break;
	                case 5: cout << "Divendres" << endl; break;
        	        case 6: cout << "Dissabte" << endl; break;
	                default : cout << "error!!!!!!" << endl; break;
	        }
	        if(resultatfinal==0){
	                cout << endl << "Cau en Diumenge i no és laboral, el proxim dia laboral sera demà, Dilluns" << endl;
	        }
        	else{
	                if(resultatfinal==6){
                	        cout << endl << "Cau en Dissabte i no és laboral, el próxim dia laboral serà demà passat, Dilluns" << endl;
        	        }
	                else {
                        	if(resultatfinal==5){
                	                cout << endl << "Cau en divendres, el seguent dia laborable serà dilluns" << endl;
        	                }
                        	else{
	                                cout << endl << " Aquest dia és laborable, i el seguent també ho és" << endl;
                                	}
                	}
        	}
		getWeek(dia, mes, any);

	}

    int getWeek(int dia, int mes, int any) {  // where a = day, b=month, c=year
                    // a = 1, b = 1, c = 2009 (01/01/2009)

//=INT
//(
//([Fecha]-DATE
//(YEAR([Fecha]-WEEKDAY([Fecha]-1)+4);1;3)
//+WEEKDAY
//(DATE
//(YEAR([Fecha]-WEEKDAY([Fecha]-1)+4);1;3)
//)
//+5)
//)
    	struct tm tm; // do not user a pointer here!
    	memset(&tm, 0, sizeof(struct tm)); // set everything to 0s
    	tm.tm_year = any - 1900;
    	tm.tm_mon = mes-1; 
    	tm.tm_mday = dia;
    	time_t t = mktime(&tm); 
    	cout << "número de la setmana (no funciona)= " << tm.tm_yday << endl;  // should output - 1  but it outputs todays day number - 279
	return (0);
    }


	// Destructor
        ~Date() {}


};
