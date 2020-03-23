#include <stdio.h>
#include "people.h"

People new_People(float age, int gender, int status, float time_recovery, float p_x, float p_y, float r_x, float r_y){
  People people;
  people.age = age;
  people.gender = gender;
  people.status = status;
  people.time_recovery = time_recovery;
  people.position[0] = p_x;
  people.position[1] = p_y;
  people.direction[0] = r_x;
  people.direction[1] = r_y;
  return people;

}

void print_People(People people){
  printf("%f\t%i\t%i\t%f\t[%f,%f]\t[%f,%f]\n",people.age, people.gender, people.status,people.time_recovery, people.position[0],people.position[1],people.direction[0],people.direction[1]);

}
