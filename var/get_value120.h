#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef get_name2_h
#define get_name2_h

char* get_name2(char a[]){
  int i = 0;
  char* b = (char*)malloc(999 * sizeof(char));

  while (*a){
    if (i == 1){
      strcat(b, a);
    }
    if (strchr(a, '"') && i == 1){
      //nothing yet

    }

    if (strchr(a, '\'') && i == 1){
      i = 1;
    }else if (strchr(a, '"') && i == 0){
      return b;
    }
    a++;
  }
  return b;
}

#endif