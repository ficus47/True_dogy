#ifndef extract_h
#define extract_h

#include <string.h>


void extract(char a[], char *b, char *c, char between[]){
  int i = 0;
  
  while (*a){
    if (*a == *b){
      i = 1;
    }
    if (i == 1){
      strcpy(between, a);
    }
    if (*a == *c && i == 1){
      break;
    }
    a++;
  }
}

#endif

#ifndef extract2_h
#define extract2_h

char *extract2(char a[], char *b, char *c, char *between, char between2[]) {
  int first = 1;
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
