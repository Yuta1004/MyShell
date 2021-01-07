#ifndef MY_STR_H
#define MY_STR_H

#include "../vector/vector.h"

char *replace(char *raw_str, char *target_str, char *rep_str, int n);
Vector* split(char *raw_str, char target);

#endif // !MY_STR_H