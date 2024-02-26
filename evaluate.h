#ifndef eval_h
#define eval_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "choose.h"
#include "spliting.h"

#include "var/struct_variable54.h"
#include "var/variables.h"
#include "utilities/extraire.h"
#include "utilities/extract.h"

#include "utilities/char/forchar.h"

void list_arg2(const char *input_string, char arguments[][400], int *arg_count) {
    // Vérifier si la chaîne d'entrée est NULL
    if (input_string == NULL) {
        *arg_count = 0;
        return;
    }

    // Initialiser le compteur d'arguments
    *arg_count = 0;

    // Rechercher le premier guillemet dans la chaîne
    const char *start_quote = strchr(input_string, '\"');

    // Tant qu'il y a des guillemets
    while (start_quote != NULL) {
        // Rechercher le dernier guillemet après le premier guillemet trouvé
        const char *end_quote = strchr(start_quote + 1, '\"');

        // Si un deuxième guillemet est trouvé
        if (end_quote != NULL) {
            // Copier l'argument entre les guillemets dans le tableau d'arguments
            int arg_length = end_quote - start_quote - 1;
            if (arg_length > 0 && arg_length < 50) {
                strncpy(arguments[*arg_count], start_quote + 1, arg_length);
                arguments[*arg_count][arg_length] = '\0';
                (*arg_count)++;
            }
        }

        // Rechercher le prochain guillemet dans la chaîne
        start_quote = strchr(end_quote + 1, '\"');
    }
}


int evaluate(char a[], struct variable *var[]){
  char command[999] = "";

  char token[999] = "";
  char list[99][400];
  char list2[999];
  char list3[999];
  char separator = ',';
  char sep2 = '=';
  int number  = 0;

  char aa, ab, ac;
  aa = '-'; ab = '('; ac = ')';

  command[0] = '\0';


  if (extract2(a , &ab, &ab, command, list2) != NULL){
    extraire(a, &ab, &ac, token, list3);

    if (find(token, &separator) == 1){
     list_arg2(token, list, &number);
    }else {

      strcpy(list[0], token);
    }

    choose(command, list, number, var);
  }
  else if (find(a, &sep2) == 1){
    saucisse(var, a);
  }else{
    printf("Error: %s is not a valid command\n", command);
    //exit(1);
  }
  return 0;
}
#endif