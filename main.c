#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "choose.h"
#include "spliting.h"
#include "evaluate.h"

#include "var/struct_variable54.h"
#include "var/variables.h"
#include "utilities/extraire.h"
#include "utilities/extract.h"

#include "utilities/char/forchar.h"

//1098+ line of code yet ! :)
//in 16 different file ! ;)

/*
█ = alt + 987 ▄ = alt + 988 ▀ = alt + 989 ▌ = alt + 990 ▐ = alt + 991 ■ = alt + 992 ▄ = alt + 993 ▀ = alt + 994
6669 = ♪
⌂ = 9999999
*/

void replace_newlines(char *text) {
    int inside_brackets = 0;
    char *ptr = text;

    while (*ptr != '\0') {
        if (*ptr == ',') {
            inside_brackets = 1;
        } else if (*ptr == ')') {
            inside_brackets = 0;
        }

        if (*ptr == '\n' && inside_brackets) {
            *ptr = ',';
        }

        ptr++;
    }
}

int read(char i[], char b[]){
  FILE *file = fopen(b, "r");
  char c;
  int number = 0;
  

  if (file == NULL){
    printf("Error: can't open file %s\n", b);
  }
  while ((c = fgetc(file)) != EOF){
    strncat(i, &c, 1);
    if (c == '\n'){
      number++;
    }
  }
  number++;

  fgets(i, 100, file);
  fclose(file);
  return number;
}

void list_arg(const char *input_string, char arguments[][99], int *arg_count) {
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

int list_line(char *a, char c[][400]) {

  char *b = strtok(a, "\n");
  int i = 0;

  while (b != NULL) {
    strcpy(c[i] ,strdup(b));

    i++;
    b = strtok(NULL, "\n");
    }
  return i;

  }

/*int evaluate(char a[], struct variable *var[]){
  char command[999] = "";

  char token[999] = "";
  char list[99][99];
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
     list_arg(token, list, &number);
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
}*/

int main(void) {
  char var[696];

  struct variable *var_list[999];
  for (int i = 0;i < 999;i++){
    var_list[i] = (struct variable*)malloc(2*sizeof(struct variable));
    copy((*var_list)[i].name, "");
    copy((*var_list)[i].value, "");
    copy((*var_list)[i].type, "");
  }

  char *c = (char*)malloc(999 * sizeof(char));
  
  int number;
  number = read(c, "saucisse.txt");
  //char **list = splitline(c, "\n");

  char list[100][400];
  
  replace_newlines(c);
  int number2 = list_line(c, list);
  
  free(c);
  int buffer = 0;
  /* bonjour */
  printf("%d", number);
  while (buffer != number){
    printf("\n%s\n", list[buffer]);
    if (strcmp(list[buffer], "") == 0){continue;}
    strcpy(var,"");
    var[1] = '\0';
    //printf(">>>> ");
    //fgets(var, sizeof(var), stdin);
    //new_line(list[buffer], '\n');
    
    evaluate(list[buffer], var_list);

    buffer++;
  }
  return 0;
}
