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
    strncpy(two_char_substring, &roman[i], 2);
    two_char_substring[2] = '\0';

    char one_char_substring[2];
    strncpy(one_char_substring, &roman[i], 1);
    one_char_substring[1] = '\0';

    bool numerals_array_includes_two_char_substring = false;

    for (size_t j = 0; j < n_numerals; j += 1) {
      if (strcmp(two_char_substring, numerals[j].key) == 0) {
        numerals_array_includes_two_char_substring = true;
      }
    }

    if (numerals_array_includes_two_char_substring) {
      for (size_t k = 0; k < n_numerals; k += 1) {
        if (strcmp(two_char_substring, numerals[k].key) == 0) {
          arabic += numerals[k].value;
        }
      }

      i += 2;
    } else {
      for (size_t k = 0; k < n_numerals; k += 1) {
        if (strcmp(one_char_substring, numerals[k].key) == 0) {
          arabic += numerals[k].value;
        }
      }

      i += 1;
    }
  }

  return arabic;
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
