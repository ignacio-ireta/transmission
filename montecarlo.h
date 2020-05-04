#ifndef MONTECARLO_H
#define MONTECARLO_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "population.h"
  
typedef struct{
  char name[128];
  Population population;
  int steps;
  int prints;
  float A; //wide
  float B; //high
}MonteCarlo;

  MonteCarlo new_MonteCarlo(char name[], Population population, float A, float B);
  int run_MonteCarlo(MonteCarlo mc, int steps, int prints, float radii, float dt, float rt);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* MONTECARLO_H */
