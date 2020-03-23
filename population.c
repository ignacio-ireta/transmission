#include <stdio.h>
#include "population.h"
#include "people.h"
  

Population new_Population(char name[], int size){
  Population p;
  sprintf(p.name,"%s",name);
  p.size = size;
  p.iterator = 0;
  return p;
}


int add_people_to_population(Population p, People a){
  if (p.iterator < p.size){
    p.people[p.iterator] = a;
    p.iterator++;
    return 1;
  }else{
    return 0;
  }
  

}

