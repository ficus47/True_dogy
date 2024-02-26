#ifndef new_line_h
#define new_line_h

#include <string.h>
#include <stdlib.h>


void new_line(char a[], char b){
  for (int i = 0;a[i] != '\0';i++){
    if (a[i] == b){
    a[i] = '\0';
    }
  }
}

#endif

#ifndef strip_h
#define strip_h


void strip(char *chaine) {
    // Vérifier si la chaîne est vide
    if (chaine == NULL || *chaine == '\0') {
        return;
    }

    // Trouver la première position non vide
    char *ptr = chaine;
    while (*ptr != '\0' && *ptr == ' ') {
        ptr++;
    }

    // Décaler les caractères vers l'avant pour supprimer les espaces au début
    memmove(chaine, ptr, strlen(ptr) + 1);
}


#endif

#ifndef split_text_h
#define split_text_h

char **splitline(char *line, char *delim) {
  char **tokens = NULL;
  char *token;
  int i = 0;

  // Découper la ligne en jetons en fonction du séparateur
  token = strtok(line, delim);
  while (token != NULL) {
    // Augmenter la taille du tableau de jetons et cast the return value of realloc to char **
    tokens = (char **)realloc(tokens, sizeof(char *) * (i + 1));
    // Stocker le jeton dans le tableau
    tokens[i++] = token;
    // Obtenir le prochain jeton
    token = strtok(NULL, delim);
  }

  // Ajouter un pointeur null à la fin du tableau
  tokens[i] = NULL;

  return tokens;
}


#endif

#ifndef split_text2_h
#define split_text2_h

int splitline2(char *line, char *delim, char *tokens[]) {
  char *token;
  int i = 0;

  // Découper la ligne en jetons en fonction du séparateur
  token = strtok(line, delim);
  while (token != NULL) {
    // Augmenter la taille du tableau de jetons et cast the return value of realloc to char **
    tokens = (char **)realloc(tokens, sizeof(char *) * (i + 1));
    // Stocker le jeton dans le tableau
    tokens[i++] = token;
    // Obtenir le prochain jeton
    token = strtok(NULL, delim);
  }

  // Ajouter un pointeur null à la fin du tableau
  tokens[i] = NULL;

  return i;
}


#endif