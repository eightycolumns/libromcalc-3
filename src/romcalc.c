#include "src/romcalc.h"

#include <stddef.h>

#include "src/numeral-conversion.h"

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
