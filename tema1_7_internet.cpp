#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string[], int);

int main ()
{
  int y = 0;
  string myarray[3] =  { "Steinbeck", "Hemingway", "Fitzgerald"};//{ "orange", "apple", "mango", "lemon", "guava", "strawberry" };

  bubbleSort(myarray, 3);
  
  for (int i=0; i<3; i++)
    cout << myarray[i] << endl;

  return 0;
}

void bubbleSort(string arr[], int n)
{
   bool swapped = true;
   int j = 0;
   string tmp;

   while (swapped)
   {
      swapped = false;
      j++;
  //    cout << "j " << j;	
      for (int i = 0; i < n - j; i++)
      {
//	cout << "arr[" << i << "] = " << arr[i];
         if ( arr[i].compare(arr[i + 1]) )
         {

            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            swapped = true;
         }
      }
   }
}
