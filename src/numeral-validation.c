#include "src/numeral-validation.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "src/numerals.h"
#include "src/strings.h"

bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  char previous_substring[3] = "";
  char current_substring[3] = "";

  int repetition_counter = 1;

  size_t i = 0;
  size_t string_length = strlen(string);

  while (i < string_length) {
    char two_char_substring[3];
    substring(two_char_substring, &string[i], 2);

    char one_char_substring[2];
    substring(one_char_substring, &string[i], 1);

    strcpy(previous_substring, current_substring);

    if (value_of(two_char_substring) > 0) {
      strcpy(current_substring, two_char_substring);
      i += 2;
    } else {
      strcpy(current_substring, one_char_substring);
      i += 1;
    }

    if (strcmp("", previous_substring) == 0) {
      continue;
    }

    if (value_of(previous_substring) < value_of(current_substring)) {
      return false;
    }

    if (strcmp(previous_substring, current_substring) == 0) {
      repetition_counter += 1;
    } else {
      repetition_counter = 1;
    }

    if (
      (strcmp("I", current_substring) == 0 && repetition_counter > 3) ||
      (strcmp("X", current_substring) == 0 && repetition_counter > 3) ||
      (strcmp("C", current_substring) == 0 && repetition_counter > 3) ||
      (strcmp("M", current_substring) == 0 && repetition_counter > 3)
    ) {
      return false;
    }
  }

  return true;
}
