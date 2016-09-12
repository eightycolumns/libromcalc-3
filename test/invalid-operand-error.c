#include "test/invalid-operand-error.h"

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];

START_TEST(IIV_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "IIV", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(IVV_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "IVV", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(VX_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "VX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XXL_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "XXL", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XLL_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "XLL", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(LC_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "LC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CCD_is_an_invalid_operand) {
  int expected = ROMCALC_INVALID_OPERAND_ERROR;
  int actual = add(sum, "CCD", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *invalid_operand_error(void) {
  TCase *invalid_operand_error = tcase_create("Invalid Operand Error");

  tcase_add_test(invalid_operand_error, IIV_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, IVV_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, VX_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, XXL_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, XLL_is_an_invalid_operand);
  tcase_add_test(invalid_operand_error, LC_is_an_invalid_operand);

  tcase_add_test(invalid_operand_error, CCD_is_an_invalid_operand);

  return invalid_operand_error;
}