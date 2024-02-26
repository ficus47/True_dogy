#ifndef extraire_h
#define extraire_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *extraire(char *a, char *b, char *c, char *between, char between2[]) {
  int first = 0;
  int between_len = strlen(between);

  while (*a) {
    if (*a == *c) {
      strncpy(between, between2, between_len);
      between[between_len] = '\0';
      return between2;
    }

    if (first == 1) {
      between2[between_len++] = *a;
      between2[between_len] ='\0'; // Assurez-vous que la chaîne est null-terminée
    }

    if (*a == *b && first != 1) {
      first = 1;
    }

    a++;
  }

  return NULL;
}

#endif