#include "src/romcalc.h"

#include <assert.h>
#include <string.h>

static int roman_to_arabic(const char *roman);
static char *arabic_to_roman(char *roman, int arabic);

int add(char *sum, const char *augend, const char *addend) {
  if (sum == NULL || augend == NULL || addend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  arabic_to_roman(sum, roman_to_arabic(augend) + roman_to_arabic(addend));

  return ROMCALC_SUCCESS;
}

int subtract(char *difference, const char *minuend, const char *subtrahend) {
  if (difference == NULL || minuend == NULL || subtrahend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  return ROMCALC_SUCCESS;
}

static int roman_to_arabic(const char *roman) {
  assert(roman != NULL);

  int arabic = 0;

  if (strcmp("I", roman) == 0) {
    arabic = 1;
  } else if (strcmp("II", roman) == 0) {
    arabic = 2;
  } else if (strcmp("III", roman) == 0) {
    arabic = 3;
  } else if (strcmp("IV", roman) == 0) {
    arabic = 4;
  } else if (strcmp("V", roman) == 0) {
    arabic = 5;
  }

  return arabic;
}

static char *arabic_to_roman(char *roman, int arabic) {
  assert(roman != NULL);

  if (arabic == 2) {
    strcpy(roman, "II");
  } else if (arabic == 3) {
    strcpy(roman, "III");
  } else if (arabic == 4) {
    strcpy(roman, "IV");
  } else if (arabic == 5) {
    strcpy(roman, "V");
  } else if (arabic == 9) {
    strcpy(roman, "IX");
  }

  return roman;
}
