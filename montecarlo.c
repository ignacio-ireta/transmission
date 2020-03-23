#include <stdio.h>
#include "montecarlo.h"
#include "population.h"
#include "people.h"
  

MonteCarlo new_MonteCarlo(char name[], Population population){
  MonteCarlo mc;
  sprintf(mc.name,"%s",name);
  mc.population = population;
  mc.steps=0;
  mc.prints=0;
  return mc;
}

int run_MonteCarlo(MonteCarlo mc, int steps, int prints){
  int i;
  int j;
  int k;
  j=0;
  for(i=0;i<steps;i++){
    if (j == prints){
      printf("iteration %i\n",i);
      for(k=0;k< mc.population.iterator;k++){
	print_People(mc.population.people[k]);
      }
      j=0;
    }
    j++;
  }

  
  return 1;
}

