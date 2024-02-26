#ifndef name_variable_h
#define name_variable_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* name_variable(char a[]){
  char *b = (char *)malloc(999 * sizeof(char));
  int sep = 0;
  char *d = (char *)malloc(999 * sizeof(char));
  strcpy(d, a);
  
  while (*a){

    if (*a == '"' && sep == 1){
      return b;
    }

    if (sep == 1){
      strncat(b, a, 1);
    }

    if (*a == '"' && sep == 0){
      sep = 1;

    }
    
    a++;
    
  }

  return d;
  
}

#endif