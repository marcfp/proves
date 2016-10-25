/* difftime example */
//#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
/*stdfacilities */

#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>

using namespace std;

/*fi stdfacilities*/

int main ()
{
/*
time_t rawtime;
  struct tm * timeinfo;
  int year, month ,day;
  const char * weekday[] = { "Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

  /* prompt user for date */
 /* printf ("Enter year: "); fflush(stdout); scanf ("%d",&year);
  printf ("Enter month: "); fflush(stdout); scanf ("%d",&month);
  printf ("Enter day: "); fflush(stdout); scanf ("%d",&day);

  /* get current timeinfo and modify it to the user's choice */
 /* time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;

  /* call mktime: timeinfo->tm_wday will be set */
 /* mktime ( timeinfo );

  printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);

  return 0;
*/
  time_t now;
  struct tm newyear;
  double seconds;
  double hora, minuts, segons;

  time(&now);  /* get current time; same as: now = time(NULL)  */
  
  newyear = *localtime(&now);

//  printf("\nnewyear = %f \n",newyear);
  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;
  
  printf("\n Prova de rellotge\n");
  printf("\n\tA quina hora vols fer sonar l'alarma ? ");
  cin >> hora;
//  newyear.tm_houre=hora;
  printf("\n\tEntra els minuts");
  cin >> minuts;
  printf("\n\tEntra els segons");
  cin >> segons;  
  

  seconds = difftime(now,now);//mktime(&newyear));

  cout << seconds << " seconds since new year in the current timezone.\n";

  return(0);
}
