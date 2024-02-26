#ifndef VARIABLE_H
#define VARIABLE_H

#include <string.h>

struct variable {
char name[999];
char value[999];
char type[999];
};

#endif

#ifndef LINE_H
#define LINE_H

struct line {
int line;
int type;
};

#endif

#ifndef TOKEN_H
#define TOKEN_H

struct token {
int num_line;
char *token[999];
};

#endif 