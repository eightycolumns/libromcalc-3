#include "src/strings.h"

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

static bool includes_lowercase(const char *string);
static bool includes_uppercase(const char *string);

bool is_empty_string(const char *string) {
  assert(string != NULL);
  return strcmp("", string) == 0;
}

bool is_mixed_case(const char *string) {
  assert(string != NULL);
  return includes_lowercase(string) && includes_uppercase(string);
}

char *substring(char *dest, const char *src, size_t n) {
  assert(dest != NULL);
  assert(src != NULL);

  strncpy(dest, src, n);
  dest[n] = '\0';

  return dest;
}

char *to_uppercase(char *string) {
  assert(string != NULL);

  size_t i = 0;

  while ((string[i] = toupper(string[i])) != '\0') {
    i += 1;
  }

  return string;
}

static bool includes_lowercase(const char *string) {
  assert(string != NULL);

  size_t string_length = strlen(string);

  for (size_t i = 0; i < string_length; i += 1) {
    if (islower(string[i])) {
      return true;
    }
  }

  return false;
}

static bool includes_uppercase(const char *string) {
  assert(string != NULL);

  size_t string_length = strlen(string);

  for (size_t i = 0; i < string_length; i += 1) {
    if (isupper(string[i])) {
      return true;
    }
  }

  return false;
}
