#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h> 
#include "montecarlo.h"
#include "population.h"
#include "people.h"

int updateTrajectory(People *k, People *m){
  float a,b,c,d,m1,m2,momentum,theta,W,Z,randomNumber;
  a = k->velocity[0];
  b = k->velocity[1];
  c = m->velocity[0];
  d = m->velocity[1];
  m1 = sqrt(a*a + b*b);
   m2 = sqrt(c*c + d*d);
  momentum = m1 + m2;
  //srand(time(0));
  randomNumber= (float)rand() / (float)RAND_MAX ;
  m1 = randomNumber*momentum;
  m2 = momentum - m1;
  //srand(time(0));
  theta = ((float)rand() / (float)RAND_MAX)*3.1416*2.0 ;
  W = cos(theta)*m1;
  Z = sin(theta)*m1;
  k->velocity[0] = W;
  k->velocity[1] = Z;
  //srand(time(0));
  theta = ((float)rand() / (float)RAND_MAX)*3.1416*2.0 ;
  W = cos(theta)*m2;
  Z = sin(theta)*m2;
  m->velocity[0] = W;
  m->velocity[1] = Z; 
  return 1;  
}


boolean intersection(People *k, People *m,float radii){
  float a,b,c,d,distance;
  a = k->position[0];
  b = k->position[1];
  c = m->position[0];
  d = m->position[1];
  distance = sqrt(pow(c-a,2) + pow(d-b,2));
  if (distance <= radii){
    if(  (k->status==1) && (m->status==0)){
      m->status=1;
    }else if((k->status==0) && (m->status==1)) {
      k->status=1;
    }

    
    return true;
  }else{
    return false;
  }
}


int interaction(Population *population, float radii){
  int k,m;
  for(k=0;k< population->iterator;k++){
    //update the position of the people
    for(m=k+1;m < population->iterator;m++){
      //update the position of the people
      if (intersection(&population->people[k],&population->people[m],radii)){
	//printf("interseciontion! %i,%i\n",k,m);

	updateTrajectory(&population->people[k],&population->people[m]);
      }
    }
  }
  return 1;
}

int integrate(People *people, float dt, float x_A, float x_B, float y_A, float y_B){
  //v = d/dt  ->  d = v*dt
  float d,v;
  //update in X
  v = people->velocity[0];
  d = v*dt;
  people->position[0] += d;

  //element exit to left side.
  if (people->position[0] < x_A){  
    people->position[0] = x_B + (people->position[0] - x_A);
  }else if ( x_B < people->position[0]){   //element exit to right side.
    people->position[0] = x_A +  (people->position[0] - x_B);
  }
  
  //update in Y
  v = people->velocity[1];
  d = v*dt;
  people->position[1] += d;

    //element exit to top.
  if (people->position[1] > y_A){  
    people->position[1] = y_B + (people->position[1] - y_A);
  } else if ( people->position[1] < y_B ){   //element exit to right side.
    people->position[1] = y_A +  (people->position[1] - y_B);
  }

  return 1;
}


MonteCarlo new_MonteCarlo(char name[], Population population, float A, float B){
  MonteCarlo mc;
  sprintf(mc.name,"%s",name);
  mc.population = population;
  mc.steps=0;
  mc.prints=0;
  mc.A = A;
  mc.B = B;
  return mc;
}

int run_MonteCarlo(MonteCarlo mc, int steps, int prints, float radii,float dt){
  int i=0;
  int j;
  int k;
  //float dt;
  float x_A,x_B,y_A,y_B;

  x_A = -mc.A/2;
  x_B = mc.A/2;
  y_A = mc.B/2;
  y_B = -mc.B/2;

  
  //dt=1.0;
  
  j=0;

  //printing step 0
  //printf("iteration %i\n",i);
  //for(k=0;k< mc.population.iterator;k++){
  //  print_People(mc.population.people[k]);
  //}

      printf("#iteration %i\n",i);
      for(k=0;k< mc.population.iterator;k++){
	print_People(mc.population.people[k]);
      }

  
  for(i=0;i<steps;i++){
    //Montecarlo integration

    for(k=0;k< mc.population.iterator;k++){
      //update the position of the people
      integrate( &mc.population.people[k],dt,x_A,x_B,y_A,y_B);
    }

    //for(k=0;k< mc.population.iterator;k++){
      //update the position of the people
      interaction( &mc.population, radii);
      //}
    
    j++;
    if (j == prints){
      printf("#iteration %i\n",i+1);
      for(k=0;k< mc.population.iterator;k++){
	print_People(mc.population.people[k]);
      }
      j=0;
    }    
  }

  
  return 1;
}

