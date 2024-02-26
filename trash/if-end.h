#ifndef if_end_h
#define if_end_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../var/struct_variable54.h"
#include "../utilities/extract.h"

void if_end(struct line *line[], char *a[], int b){
  int i;
  int j = 0;
  int k = 0;
  int l = 0;
  
  for (i = 0; i < b; i++){
    char list[999], buff[999];
    char c1, c2;
    c1 = ' ';c2 = '(';
    
    if (extract2(a[i], &c1, &c2, buff, list) != NULL){
      if (strcmp(buff, "if") == 0 || strcmp(buff, "while") == 0){  
        (*line)[j].delimiter = i;
        j++;
      }
    }

    if (strcmp(a[i], "}") == 0){
      j--;
      (*line)[k].len = l;
      k++;
    }
    if (j == 1){
      (*line)[k].CL[l] = a[i];
      l++;
    }
  }
}

#endif