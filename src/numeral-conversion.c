#include "src/numeral-conversion.h"

#include <assert.h>
#include <string.h>

#include "src/numerals.h"

static char *substring(char *dest, const char *src, size_t n);

int roman_to_arabic(const char *roman) {
  assert(roman != NULL);

  int arabic = 0;

  size_t i = 0;
  size_t roman_length = strlen(roman);

  while (i < roman_length) {
    char two_char_substring[3];
    substring(two_char_substring, &roman[i], 2);

    char one_char_substring[2];
    substring(one_char_substring, &roman[i], 1);

    if (value_of(two_char_substring) > 0) {
      arabic += value_of(two_char_substring);
      i += 2;
    } else {
      arabic += value_of(one_char_substring);
      i += 1;
    }
  }

  return arabic;
}

char *arabic_to_roman(char *roman, int arabic) {
  assert(roman != NULL);

  strcpy(roman, "");

  for (size_t i = 0; i < n_numerals; i += 1) {
    while (arabic >= numerals[i].value) {
      strcat(roman, numerals[i].key);
      arabic -= numerals[i].value;
    }
  }

  return roman;
}

static char *substring(char *dest, const char *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);

  strncpy(dest, src, n);
  dest[n] = '\0';

  return dest;
}
