#ifndef copy_h
#define copy_h

#include <stdlib.h>

void copy(char a[], char b[]){
  int i = 0;
  while (b[i] != '\0'){
    a[i] = b[i];
    i++;
  }
  a[i] = '\0';

  for (int o = sizeof(a); o < 999; o++){
    if (o > i){
      a[o] = '\0';
    }
  }
}

#endif 