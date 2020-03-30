#include <stdio.h>
#include "montecarlo.h"
#include "population.h"
#include "people.h"

int integrate(People *people, float dt){
  //v = d/dt  ->  d = v*dt
  float d,v;
  //update in X
  v = people->velocity[0];
  d = v*dt;
  people->position[0] += d;
  //update in Y
  v = people->velocity[1];
  d = v*dt;
  people->position[1] += d;
  return 1;
}


MonteCarlo new_MonteCarlo(char name[], Population population){
  MonteCarlo mc;
  sprintf(mc.name,"%s",name);
  mc.population = population;
  mc.steps=0;
  mc.prints=0;
  return mc;
}

int run_MonteCarlo(MonteCarlo mc, int steps, int prints){
  int i=0;
  int j;
  int k;
  float dt;

  dt=1.0;
  
  j=0;

  //printing step 0
  //printf("iteration %i\n",i);
  //for(k=0;k< mc.population.iterator;k++){
  //  print_People(mc.population.people[k]);
  //}
  
  for(i=0;i<steps;i++){
    //Montecarlo integration
    for(k=0;k< mc.population.iterator;k++){
      //update the position of the people
      integrate( &mc.population.people[k],dt );
    }
    j++;
    if (j == prints){
      printf("#iteration %i\n",i);
      for(k=0;k< mc.population.iterator;k++){
	print_People(mc.population.people[k]);
      }
      j=0;
    }    
  }

  
  return 1;
}

