#include "test/subtraction.h"

#include <check.h>

#include "src/romcalc.h"

static char actual[ROMCALC_MAX_LENGTH];

START_TEST(MMMCMXCIX_minus_CXI_is_MMMDCCCLXXXVIII) {
  char expected[] = "MMMDCCCLXXXVIII";
  subtract(actual, "MMMCMXCIX", "CXI");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(MMMDCCCLXXXVIII_minus_DCCCLXXXVIII_is_MMM) {
  char expected[] = "MMM";
  subtract(actual, "MMMDCCCLXXXVIII", "DCCCLXXXVIII");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(MMM_minus_M_is_MM) {
  char expected[] = "MM";
  subtract(actual, "MMM", "M");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(MM_minus_M_is_M) {
  char expected[] = "M";
  subtract(actual, "MM", "M");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(M_minus_C_is_CM) {
  char expected[] = "CM";
  subtract(actual, "M", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CM_minus_CD_is_D) {
  char expected[] = "D";
  subtract(actual, "CM", "CD");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(D_minus_C_is_CD) {
  char expected[] = "CD";
  subtract(actual, "D", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CD_minus_C_is_CCC) {
  char expected[] = "CCC";
  subtract(actual, "CD", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CCC_minus_C_is_CC) {
  char expected[] = "CC";
  subtract(actual, "CCC", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CC_minus_C_is_C) {
  char expected[] = "C";
  subtract(actual, "CC", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(C_minus_X_is_XC) {
  char expected[] = "XC";
  subtract(actual, "C", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XC_minus_XL_is_L) {
  char expected[] = "L";
  subtract(actual, "XC", "XL");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(L_minus_X_is_XL) {
  char expected[] = "XL";
  subtract(actual, "L", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XL_minus_X_is_XXX) {
  char expected[] = "XXX";
  subtract(actual, "XL", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XXX_minus_X_is_XX) {
  char expected[] = "XX";
  subtract(actual, "XXX", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XX_minus_X_is_X) {
  char expected[] = "X";
  subtract(actual, "XX", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

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

START_TEST(mmmcccxxxiii_minus_mmccxxii_is_MCXI) {
  char expected[] = "MCXI";
  subtract(actual, "mmmcccxxxiii", "mmccxxii");
  ck_assert_str_eq(expected, actual);
} END_TEST

TCase *subtraction(void) {
  TCase *subtraction = tcase_create("Subtraction");

  tcase_add_test(subtraction, MMMCMXCIX_minus_CXI_is_MMMDCCCLXXXVIII);
  tcase_add_test(subtraction, MMMDCCCLXXXVIII_minus_DCCCLXXXVIII_is_MMM);
  tcase_add_test(subtraction, MMM_minus_M_is_MM);
  tcase_add_test(subtraction, MM_minus_M_is_M);

  tcase_add_test(subtraction, M_minus_C_is_CM);
  tcase_add_test(subtraction, CM_minus_CD_is_D);
  tcase_add_test(subtraction, D_minus_C_is_CD);
  tcase_add_test(subtraction, CD_minus_C_is_CCC);
  tcase_add_test(subtraction, CCC_minus_C_is_CC);
  tcase_add_test(subtraction, CC_minus_C_is_C);

  tcase_add_test(subtraction, C_minus_X_is_XC);
  tcase_add_test(subtraction, XC_minus_XL_is_L);
  tcase_add_test(subtraction, L_minus_X_is_XL);
  tcase_add_test(subtraction, XL_minus_X_is_XXX);
  tcase_add_test(subtraction, XXX_minus_X_is_XX);
  tcase_add_test(subtraction, XX_minus_X_is_X);

  tcase_add_test(subtraction, X_minus_I_is_IX);
  tcase_add_test(subtraction, IX_minus_IV_is_V);
  tcase_add_test(subtraction, V_minus_I_is_IV);
  tcase_add_test(subtraction, IV_minus_I_is_III);
  tcase_add_test(subtraction, III_minus_I_is_II);
  tcase_add_test(subtraction, II_minus_I_is_I);

  tcase_add_test(subtraction, mmmcccxxxiii_minus_mmccxxii_is_MCXI);

  return subtraction;
}
