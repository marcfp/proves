#include <iostream>
#include <ctype.h>
using namespace std;
//Falta revisar i acabar de comprobar
// constexpr function for product of two numbers. 
// By specifying constexpr, we suggest compiler to  
// to evaluate value at compiler time 
constexpr int to_int(const char lletra)
    {
        return (lletra == 'M') ? 1000
        : (lletra == 'D') ? 500
        : (lletra == 'C') ? 100
        : (lletra == 'L') ? 50
        : (lletra == 'X') ? 10
        : (lletra == 'V') ? 5
        : (lletra == 'I') ? 1
        : 0;
    }
    
class Roma{

  int valor;
  char lletra;
  string num;
  public:
    int canvi_lletra_a_valor(){
      return(to_int(lletra));
    }
    
    void set_num(){
      cout << "Entra el numero en xifres romanes " << endl;
      cin >> num;
      for(int i=0; i<num.size();++i) num[i]=toupper(num[i]);
    }
    
    string get_num(){
      return num;
    }
    
    void set_lletra(){
      cout << "Entra la lletra " << endl;
      cin >> lletra;
      if(islower(lletra)) lletra=toupper(lletra);
    }
    
    char get_lletra(){
      return lletra;
    }
    
    int get_valor(){ 
      int val=0;
      int anterior=0;
      int conta=0;
      int suma;
      cout << "valor abans for val  = " << val << endl;
      val=to_int(num[0]);
      cout << "valor val  = " << val << endl;
      conta++;
      for(int i=1;i<num.size();++i){
        if(conta<=3 && conta<=num.size()){ 
	  cout  << " val = " << val << " to_int(num[i]) = " << to_int(num[i]) << "\n anterior = " << anterior << " i = " << i << " conta = " <<  conta <<  endl;
	  if(conta==1){ 
	      anterior=to_int(num[i]);
	     // val=val+to_int(num[i]);
	  }
	  else anterior=to_int(num[i-1]);
	  if(val<to_int(num[i]))  val=to_int(num[i])-val; 
	  else if(conta<=3 || anterior==to_int(num[i])) {
		    val=to_int(num[i])+val;
		    anterior=to_int(num[i]);
		    if(conta==2 &&  ((to_int(num[i])==5 && to_int(num[i-1])==5) || (to_int(num[i])==50 && to_int(num[i-1])==50)|| (to_int(num[i])==500 && to_int(num[i-1])==500))){
                      cout << "Número erroni, no es pot repetir!!" << endl;
                      return (-15);
                      
                    }

		}
		else {
		  if(to_int(num[i])!=to_int(num[i-1])) conta=0;
		  else{
		   cout << "error reiniciant conta ?" << endl;
		   return (0);
		  }
		  
		}
		conta++;
		if(conta>3 && to_int(num[i])==to_int(num[i-1]) && to_int(num[i])==to_int(num[i-2])&& to_int(num[i])==to_int(num[i-3])) {
                    cout << " conta final = " << conta << " números repetits" << endl;
		    conta=0;
                    return (0);
		  
                }
	}
	else {
	  /*problema del 128 es aqui ?*/
	  cout << endl<< endl<< endl<< "passa aqui el 128 ?" << endl<< endl<< endl<< endl;
	  if(to_int(num[i])==anterior && conta<=3){	    
	    if(to_int(num[i-1])<to_int(num[i]) )  val=val-to_int(num[i]); 
	    else val=val+to_int(num[i]);
	    anterior=to_int(num[i]);
	    //if(to_int(num[i])>val){     
	    //  return (0);
	    //}
	  }
	  else {
	    cout << " to_int(num[i]) = " << to_int(num[i]) << " to_int(num[i-1]) = " << to_int(num[i-1]) << " i = " <<  i << " num.size() = " << num.size() << " val = " << val << endl;
	    if(to_int(num[i])<=to_int(num[i-1]) && i<num.size()){ // per provar ....
	      val=val+to_int(num[i]);	       //per provar a veure si sumo ...
	      }	      
	      else {
		cout << endl << "número mal format dins else" << endl;
		conta=0;
		return (0);
	      }
	  }
	
	}
        //mirar si s'ha de sumar o restar, a part d'això, també s'ha de mirar si el número entrat és correcte.
        cout << "i = " << i << "num[" << i <<"] = " << num[i] << " =" << to_int(num[i]) << "  val = " << val << " conta = " << conta << endl;
      }
      valor=val;
      cout << " get_valor -> valor  = " << valor << endl;
      
      return (valor);
    }	
};
    
  
int main() 
{ 
    int y, z;
 
    Roma roma;
       
    
    //roma.set_lletra();
    //int val=roma.canvi_lletra_a_valor();
    //cout << "el valor entrat de la lletra " << roma.get_lletra() << " és " << val << endl;
    
    
    roma.set_num();
    if(roma.get_valor()!=-15) cout << " string = " << roma.get_num() << "roma.get_valor = " << roma.get_valor() << endl;
    else cout << " número mal format!!! main" << endl;
    /*
    const int x1 = to_int('D');
    cout << " el valor resultat és " << x1 << endl;
    
    const int x = to_int('X'); 
    cout << "Escriu el valor de x : " << x <<endl; 
    
    */
    return (0); 
}
