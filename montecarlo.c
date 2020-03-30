#include <stdio.h>
#include "montecarlo.h"
#include "population.h"
#include "people.h"

int integrate(People *people, float dt){
  //v = d/t  ->  d = v*t
  float x;
  float y;

  people->position[]
    people->velocity[]

  

    


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
  printf("iteration %i\n",i);
  for(k=0;k< mc.population.iterator;k++){
    print_People(mc.population.people[k]);
  }
  
  for(i=0;i<=steps;i++){
    //Montecarlo integration

      for(k=0;k< mc.population.iterator;k++){
	//update the position of the people
	integrate( &mc.population.people[k],dt );
      }


    
    
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

