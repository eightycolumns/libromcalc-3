#include "src/numerals.h"

#include <assert.h>
#include <string.h>

Numeral numerals[] = {
  {"M", 1000},
  {"CM", 900},
  {"D", 500},
  {"CD", 400},
  {"C", 100},
  {"XC", 90},
  {"L", 50},
  {"XL", 40},
  {"X", 10},
  {"IX", 9},
  {"V", 5},
  {"IV", 4},
  {"I", 1},
};

size_t n_numerals = sizeof numerals / sizeof numerals[0];

int value_of(const char *key) {
  assert(key != NULL);

  for (size_t i = 0; i < n_numerals; i += 1) {
    if (strcmp(key, numerals[i].key) == 0) {
      return numerals[i].value;
    }
  }

  return 0;
}
