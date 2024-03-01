#ifndef print_h
#define print_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utilities/operateur/comparison.h"
#include "utilities/char/forchar.h"
#include "utilities/char/replace.h"

#include "var/struct_variable54.h"
#include "var/variables.h"
#include "var/get_value.h"

#include "evaluate.h"

void eval(char *a[], long long int o, struct variable *var[]){
  for (int i = 0; i < o+1; i++){
    evaluate(a[i], var);
  }
}

void print(char *a[], long long int o, struct variable *var[], int f){
  if (a[1] != NULL){
    
    for (int i = 0; i != o+1; i++){
      if (get_value(a[i], var) != NULL){
        printf("%s ", get_value(a[i], var));
      }
      else {
        printf("%s ", a[i]);
      }
    }
    
  } else {
    if (get_value(a[0], var) != NULL){
      printf("%s ", get_value(a[0], var));
    }
    else {
      printf("%s ", a[0]);
    }
  }
  if (f == 1){
  printf("\n");
  }
}

void input(char *a[], long long int o, struct variable *var[]){
  char *b = (char*)malloc(sizeof(char) * 4000);
  char ce[999] = "\"output\" = ";
  fgets(b, 400, stdin);
  b[strcspn(b, "\n")] = 0;

  replace(b, ' ', '~');
  
  strcat(ce, "\"");
  strcat(ce, b);
  strcat(ce, "\"");
  saucisse(var, ce);
  free(b);
}


int choose(char a[], char *b[], int c, struct variable *var[]){
  //printf("a = %s\n", a);
  //printf("%d : %s\n", strcmp(a, "print"), a);
  if (strcmp(a, "print") == 0){
    print(b, c, var, 1);
    return 0;
  }
  if (strcmp(a, "input") == 0){
    print(b, c, var, 0);
    input(b, c, var);
    return 0;
  }
  if (strcmp(a, "if") == 0){
    int i, j, fe;
    char *list2[999];
    i = compar(b[0], var);
    if (i == 1){
      eval(b, c, var);
    }
  }
  return 1;
}




int find(char a[], char *b){
  
  while (*a != '\0'){
    if (*a == *b){
      return 1;
    }
    a++;
  }
  return 0;
}

#endif