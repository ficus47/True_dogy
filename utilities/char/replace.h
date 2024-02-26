#ifndef replace_h
#define replace_h

#include <string.h>

void replace(char *a, char b, char c){
  while (*a){
    if (*a == b){
      *a = c;
    }
    a++;
  }
}

#endif