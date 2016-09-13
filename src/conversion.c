#include "src/conversion.h"

#include <assert.h>
#include <string.h>

#include "src/numeral-validation.h"
#include "src/numerals.h"
#include "src/strings.h"

int roman_to_arabic(const char *roman) {
  assert(roman != NULL);
  assert(is_roman_numeral(roman));

  int arabic = 0;

  size_t i = 0;
  size_t roman_length = strlen(roman);

  while (i < roman_length) {
    char two_char_substring[3];
    substring(two_char_substring, &roman[i], 2);
    to_uppercase(two_char_substring);

    char one_char_substring[2];
    substring(one_char_substring, &roman[i], 1);
    to_uppercase(one_char_substring);

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
  assert(is_in_range(arabic));

  strcpy(roman, "");

  for (size_t i = 0; i < n_numerals; i += 1) {
    while (arabic >= numerals[i].value) {
      strcat(roman, numerals[i].key);
      arabic -= numerals[i].value;
    }
  }

  return roman;
}
