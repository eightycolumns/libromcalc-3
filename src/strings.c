#include "src/strings.h"

#include <assert.h>
#include <ctype.h>
#include <string.h>

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
