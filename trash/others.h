int get_line(char *a[], struct line *line[], int c){
  int i;
  int j;
  int aa = 0;
  for (j = 0; i < c; j++){
    if ((*line)[j].delimiter == i){
      break;
    }
  }


  for (i = 0; i != (*line)[j].len; i++){
    if (strcmp((*line)[j].CL[i], " ") == 0 || strcmp((*line)[j].CL[i], "") == 0){
      continue;  
    }

    a[i] = (*line)[j].CL[i];
    aa++;
  }
  return aa;
}