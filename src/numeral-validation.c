#include "src/numeral-validation.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "src/numerals.h"
#include "src/strings.h"

static bool is_legal_order(const char *previous, const char *current);
static bool is_legal_repetition(const char *previous, const char *current);
static bool is_repeatable(const char *substring);

bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  char previous_substring[3] = "";
  char current_substring[3] = "";

  size_t i = 0;
  size_t string_length = strlen(string);

  while (i < string_length) {
    strcpy(previous_substring, current_substring);

    char two_char_substring[3];
    substring(two_char_substring, &string[i], 2);

    char one_char_substring[2];
    substring(one_char_substring, &string[i], 1);

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

    if (!is_legal_order(previous_substring, current_substring)) {
      return false;
    }

    if (!is_legal_repetition(previous_substring, current_substring)) {
      return false;
    }
  }

  return true;
}

static bool is_legal_order(const char *previous, const char *current) {
  assert(previous != NULL);
  assert(current != NULL);

  return value_of(previous) >= value_of(current);
}

static bool is_legal_repetition(const char *previous, const char *current) {
  assert(previous != NULL);
  assert(current != NULL);

  static int counter = 1;

  if (strcmp(previous, current) == 0) {
    counter += 1;
  } else {
    counter = 1;
  }

  int limit = is_repeatable(current) ? 3 : 1;

  return counter <= limit;
}

static bool is_repeatable(const char *substring) {
  assert(substring != NULL);

  return (
    strcmp("I", substring) == 0 ||
    strcmp("X", substring) == 0 ||
    strcmp("C", substring) == 0 ||
    strcmp("M", substring) == 0
  );
}
