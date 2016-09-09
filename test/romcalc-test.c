#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"
#include "test/error-handling.h"
#include "test/addition.h"

static char actual[ROMCALC_MAX_LENGTH];

START_TEST(X_minus_I_is_IX) {
  char expected[] = "IX";
  subtract(actual, "X", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IX_minus_IV_is_V) {
  char expected[] = "V";
  subtract(actual, "IX", "IV");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(V_minus_I_is_IV) {
  char expected[] = "IV";
  subtract(actual, "V", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IV_minus_I_is_III) {
  char expected[] = "III";
  subtract(actual, "IV", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(III_minus_I_is_II) {
  char expected[] = "II";
  subtract(actual, "III", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(II_minus_I_is_I) {
  char expected[] = "I";
  subtract(actual, "II", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

TCase *subtraction(void) {
  TCase *subtraction = tcase_create("Subtraction");

  tcase_add_test(subtraction, X_minus_I_is_IX);
  tcase_add_test(subtraction, IX_minus_IV_is_V);
  tcase_add_test(subtraction, V_minus_I_is_IV);
  tcase_add_test(subtraction, IV_minus_I_is_III);
  tcase_add_test(subtraction, III_minus_I_is_II);
  tcase_add_test(subtraction, II_minus_I_is_I);

  return subtraction;
}

Suite *operations(void) {
  Suite *operations = suite_create("Operations");

  suite_add_tcase(operations, addition());
  suite_add_tcase(operations, subtraction());

  return operations;
}

int main(void) {
  SRunner *srunner = srunner_create(error_handling());
  srunner_add_suite(srunner, operations());

  srunner_run_all(srunner, CK_ENV);
  int ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (ntests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
