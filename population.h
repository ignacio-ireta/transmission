#ifndef POPULATION_H
#define POPULATION_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "people.h"
  
typedef struct{
  char name[128];
  People people[8];
}Population;

  Population new_Population(char name[]);
  int add_people_to_population(Population p, People a);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* POPULATION_H */
