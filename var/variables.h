#ifndef get_list_h
#define get_list_h

#include "struct_variable54.h"
#include "../utilities/copy.h"
#include "../utilities/extract.h"
#include "../utilities/copy.h"
#include "../split2.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "name_variable.h"

#include "../utilities/char/forchar.h"


#ifndef split240_h
#define split240_h

int split240(char chaine[], char *delim, char *a[]) {
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


int get_list(struct variable var[], char b[]){
  int i = 0;

  for (int o = 0; o < 999; o++){
    if (strcmp(var[o].name, "") != 0){
      i++;
    }
    else {
      return i;
    }
    if (strcmp(var[o].name, b) == 0){
      return o;
    }
  }
  return i;
}

#ifndef get_type_h
#define get_type_h

int get_type(char a[]){
  return 0;
}

#ifndef get_name_h
#define get_name_h

char* get_name(char a[]){
  int i = 0;
  char* b = (char*)malloc(999 * sizeof(char));
  
  while (*a){
    if (i == 1){
      strcat(b, a);
    }
    if (strchr(a, '"') && i == 1){
      //nothing yet
      
    }
      
    if (strchr(a, '\'') && i == 0){
      i = 1;
    }else if (strchr(a, '\'') && i == 1){
      return b;
    }
    a++;
  }
  return b;
}
#ifndef saucisse_h
#define saucisse_h

void saucisse(struct variable *var[], char b[]){
  char *ratatouille[9999];
  char sep = '=';
  char buffer[999];
  
  strcpy(buffer, "int");
  split240(b, &sep, ratatouille);

  
  int i = get_list(*var, name_variable(b));

  
  if (get_type(b) == 0){
    char buff[999];
    char buffer2[999];
    char *point1 = (*var)[i].name;
    char *point2 = (*var)[i].value;
    char *point3 = (*var)[i].type;


    //name_variable(b, buff);
    strcpy(buff, name_variable(b));
    //printf("%s", name_variable(b));

    strcpy(point1, "");
    strcpy(point2, "");
    strcpy(point3, "");

    strip(ratatouille[1]);
    
    strcpy(point1, buff);
    strcpy(point2, name_variable(ratatouille[1]));
    strcpy(point3, buffer);

    //printf("\n %s %s %s\n", point1, point2, point3);
    
    /*printf("\n -> %s <-\n", (*var)[i].name);
    printf("\n -> %s <-\n", (*var)[i].type);
    printf("\n -> %s <-\n", (*var)[i].value);*/
  }
}

#endif
#endif
#endif
#endif

#ifndef last_h
#define last_h

void last(struct variable *var[], char b[], char c[]){
  char buffer[999];

  strcpy(buffer, "int");

  int i = get_list(*var, name_variable(b));


  if (get_type(b) == 0){
    char buff[999];
    char buffer2[999];
    char *point1 = (*var)[i].name;
    char *point2 = (*var)[i].value;
    char *point3 = (*var)[i].type;


    //name_variable(b, buff);
    strcpy(buff, name_variable(b));
    //printf("%s", name_variable(b));

    strcpy(point1, "");
    strcpy(point2, "");
    strcpy(point3, "");


    strcpy(point1, c);
    strcpy(point2, b);
    strcpy(point3, buffer);

    //printf("\n %s %s %s\n", point1, point2, point3);

    /*printf("\n -> %s <-\n", (*var)[i].name);
    printf("\n -> %s <-\n", (*var)[i].type);
    printf("\n -> %s <-\n", (*var)[i].value);*/
  }
}

#endif

#ifndef something_h
#define something_h

void something(struct variable *var[]){
  for (int i = 0; i < 999; i++){
    if (strcmp((*var)[i].name, "") != 0){
      printf("\n%s : %s\n", (*var)[i].name, (*var)[i].value);
    }
  }
}

#endif
