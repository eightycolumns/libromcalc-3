#include "src/romcalc.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} Numeral;

static Numeral numerals[] = {
  {"X", 10},
  {"IX", 9},
  {"V", 5},
  {"IV", 4},
  {"I", 1},
};

static size_t n_numerals = sizeof numerals / sizeof numerals[0];

static int roman_to_arabic(const char *roman);
static char *substring(char *dest, const char *src, size_t n);
static bool numerals_array_includes(const char *key);
static int value_of(const char *key);
static char *arabic_to_roman(char *roman, int arabic);

int add(char *sum, const char *augend, const char *addend) {
  if (sum == NULL || augend == NULL || addend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  int result = roman_to_arabic(augend) + roman_to_arabic(addend);

  arabic_to_roman(sum, result);

  return ROMCALC_SUCCESS;
}

int subtract(char *difference, const char *minuend, const char *subtrahend) {
  if (difference == NULL || minuend == NULL || subtrahend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  int result = roman_to_arabic(minuend) - roman_to_arabic(subtrahend);

  arabic_to_roman(difference, result);

  return ROMCALC_SUCCESS;
}

static int roman_to_arabic(const char *roman) {
  assert(roman != NULL);

  int arabic = 0;

  size_t i = 0;

  while (i < strlen(roman)) {
    char two_char_substring[3];
    substring(two_char_substring, &roman[i], 2);

    char one_char_substring[2];
    substring(one_char_substring, &roman[i], 1);

    if (numerals_array_includes(two_char_substring)) {
      arabic += value_of(two_char_substring);
      i += 2;
    } else {
      arabic += value_of(one_char_substring);
      i += 1;
    }
  }

  return arabic;
}

static char *substring(char *dest, const char *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);

  strncpy(dest, src, n);
  dest[n] = '\0';

  return dest;
}

static bool numerals_array_includes(const char *key) {
  assert(key != NULL);

  for (size_t i = 0; i < n_numerals; i += 1) {
    if (strcmp(key, numerals[i].key) == 0) {
      return true;
    }
  }

  return false;
}

static int value_of(const char *key) {
  assert(key != NULL);
  assert(numerals_array_includes(key));

  int value = 0;

  for (size_t i = 0; i < n_numerals; i += 1) {
    if (strcmp(key, numerals[i].key) == 0) {
      value = numerals[i].value;
    }
  }

  return value;
}

static char *arabic_to_roman(char *roman, int arabic) {
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
