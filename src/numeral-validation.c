#include "src/numeral-validation.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "src/numerals.h"
#include "src/strings.h"

static bool is_empty_string(const char *string);
static bool illegal_characters(const char *substring);
static bool illegal_order(const char *previous, const char *current);
static bool illegal_repetition(const char *previous, const char *current);
static bool is_repeatable(const char *substring);

bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  if (is_empty_string(string)) {
    return false;
  }

  char previous_substring[3] = "";
  char current_substring[3] = "";

  size_t i = 0;
  size_t string_length = strlen(string);

  while (i < string_length) {
    strcpy(previous_substring, current_substring);

    char two_char_substring[3];
    substring(two_char_substring, &string[i], 2);
    to_uppercase(two_char_substring);

    char one_char_substring[2];
    substring(one_char_substring, &string[i], 1);
    to_uppercase(one_char_substring);

    if (value_of(two_char_substring) > 0) {
      strcpy(current_substring, two_char_substring);
      i += 2;
    } else {
      strcpy(current_substring, one_char_substring);
      i += 1;
    }

    if (illegal_characters(current_substring)) {
      return false;
    }

    if (illegal_order(previous_substring, current_substring)) {
      return false;
    }

    if (illegal_repetition(previous_substring, current_substring)) {
      return false;
    }
  }

  return true;
}

static bool is_empty_string(const char *string) {
  assert(string != NULL);
  return strcmp("", string) == 0;
}

static bool illegal_characters(const char *substring) {
  assert(substring != NULL);
  return value_of(substring) == 0;
}

static bool illegal_order(const char *previous, const char *current) {
  assert(previous != NULL);
  assert(current != NULL);

  if (strcmp("", previous) == 0) {
    return false;
  }

  return value_of(previous) < value_of(current);
}

static bool illegal_repetition(const char *previous, const char *current) {
  assert(previous != NULL);
  assert(current != NULL);

  static int counter;

  if (strcmp(previous, current) == 0) {
    counter += 1;
  } else {
    counter = 1;
  }

  int limit = is_repeatable(current) ? 3 : 1;

  return counter > limit;
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
