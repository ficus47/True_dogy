#ifndef get2_h
#define get2_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get2(char a[], long long int i, char c[]) {
  long o = 0;

  while (o < strlen(a)) {
    c[o] = a[o];

    o++;
  }
  c[9999] = '\0';
}

int split2(char chaine[], char *delim, char *a[]) {
  // Initialise les variables


  char *chain = chaine;
  int i = 0;
  char buf[9999];
  int o = 0;
  char saucisse[9999];

  do {
    char s = *chain;
    if (s == *delim) {

      get2(buf, o, saucisse);

      a[i] = strdup(saucisse);
      o = -1;
      i++;

    } else {
      buf[o] = *chain;
    }


    chain++;
    o++;

  }while (*chain);
;
  get2(buf, o, saucisse);
  
  a[i] = strdup(saucisse);
  return i;

}


#endif