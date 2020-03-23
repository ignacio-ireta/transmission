#include <stdio.h>
#include <stdlib.h>
#include "people.h"
#include "population.h"

int main(int argn, char **argv){

  People a1,a2,a3,a4,a5;
  Population p;

  
  /*age, 
    gender [0=man,1=woman], 
    status [0=healty, 1=sick, 2=immune, -1=dead],
    time_recovery [hours]
    position [x,y]
    direction [x,y]
  */
  
  a1 = new_People(18, 1, 0, 0.0, 0.0, 0.0, 1.0, 0.0);
  a2 = new_People(28, 0, 0, 0.0, 1.0, 3.0, 1.0, 1.0);
  a3 = new_People(38, 1, 0, 0.0, 2.0, 5.0, 2.0, 4.0);
  a4 = new_People(48, 0, 0, 0.0, 4.0, 6.0, 3.0, 1.0);
  a5 = new_People(60, 1, 0, 0.0, 6.0, 8.0, 2.0, 4.0);

  p = new_Population("Mexico");
  
  add_people_to_population(p,a1);
  add_people_to_population(p,a2);
  add_people_to_population(p,a3);
  add_people_to_population(p,a4);
  add_people_to_population(p,a5);

  
  return 0;
}
