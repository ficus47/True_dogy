#include "struct_variable54.h"
#include "name_variable.h"
#include "../utilities/char/replace.h"
#include "../utilities/char/forchar.h"

#include <string.h>
#include <stdio.h>

#ifndef GET_VALUE_H
#define GET_VALUE_H

char* get_value(char a[], struct variable *var[]){
  strip(a);
  for (int i = 0; i < 999; i++){
    if (strcmp(a, (*var)[i].name) == 0){
      if (strcmp((*var)[i].name, "output") == 0){
        replace((*var)[i].value, '~', ' ');
        return  (*var)[i].value;

      }
      return (*var)[i].value;
    }
  }
  return NULL;
}

#endif