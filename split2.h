#ifndef get24_h
#define get24_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get24(char a[], long long int i, char c[]) {
  long o = 0;

  while (o < strlen(a)) {
    c[o] = a[o];

    o++;
  }
  c[9999] = '\0';
}

#endif

#ifndef split24_h
#define split24_h

int split24(char chaine[], char *delim, char *a[]) {
  // Initialise les variables


  char *chain = chaine;
  int i = 0;
  char buf[9999];
  int o = 0;
  char saucisse[9999];

  while (*chain) {
    char s = *chain;
    if (s == *delim) {

      get24(buf, o, saucisse);

      a[i] = strdup(saucisse);
      o = -1;
      i++;

    } else {
      buf[o] = *chain;
    }


    chain++;
    o++;

  }
;
  get24(buf, o, saucisse);

  a[i] = strdup(saucisse);
  return i;

}

#endif
