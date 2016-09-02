#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];

START_TEST(sum_cannot_by_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = add(NULL, "I", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(augend_cannot_by_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = add(sum, NULL, "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(addend_cannot_by_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = add(sum, "I", NULL);
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(difference_cannot_be_NULL) {
  int expected = ROMCALC_NULL_POINTER_ERROR;
  int actual = subtract(NULL, "II", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

int main(void) {
  TCase *null_pointer_error = tcase_create("Null Pointer Error");
  tcase_add_test(null_pointer_error, sum_cannot_by_NULL);
  tcase_add_test(null_pointer_error, augend_cannot_by_NULL);
  tcase_add_test(null_pointer_error, addend_cannot_by_NULL);
  tcase_add_test(null_pointer_error, difference_cannot_be_NULL);

  Suite *error_handling = suite_create("Error Handling");
  suite_add_tcase(error_handling, null_pointer_error);

  SRunner *srunner = srunner_create(error_handling);
  srunner_run_all(srunner, CK_ENV);
  int ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (ntests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
