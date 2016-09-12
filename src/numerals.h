#ifndef NUMERALS_H
#define NUMERALS_H

#include <stddef.h>

typedef struct {
  char *key;
  int value;
} Numeral;

extern Numeral numerals[];
extern size_t n_numerals;

int value_of(const char *key);

#endif
