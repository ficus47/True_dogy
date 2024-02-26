

#ifndef comparaison_h
#define comparaison_h

#include "../../var/variables.h"
#include "../../var/struct_variable54.h"
#include "../../utilities/extract.h"
#include "../../utilities/char/forchar.h"
#include "../../var/get_value.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int compar(char a[], struct variable *line[]){
  char eq[3] = "==";
  int b = 0;
  char aa, bb;
  aa = ' ';bb = '=';
  
  char buff[999];
  char buff2[999];
  char list[999];
  
  if (strstr(a, eq) != NULL){
    extract2(a, &aa, &bb, buff, list);
    extract2(a, &bb, &aa, buff2, list);
    buff2[0] = ' ';

    strip(buff2);
    if (strcmp(get_value(buff, line), get_value(buff2, line))){
      b = 1;
    }
  }
  return b;
}

#endif 
