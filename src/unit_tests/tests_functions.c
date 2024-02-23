#include "test_s21_math.h"

START_TEST(s21_abs_func) {
  int x = -123;
  ck_assert_int_eq(s21_abs(x), abs(x));
  x = 123;
  ck_assert_int_eq(s21_abs(x), abs(x));
}
END_TEST

START_TEST(s21_fabs_func) {
  double x = -123.56;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = 123.56;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = S21_NAN;
  ck_assert_ldouble_nan(s21_fabs(x));
  x = -S21_INF;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = S21_INF;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = DBL_MIN;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
  x = DBL_MAX;
  ck_assert_ldouble_eq(s21_fabs(x), fabs(x));
}
END_TEST

START_TEST(s21_ceil_func) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_ceil(x));
  x = -S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  x = S21_INF;
  ck_assert_ldouble_eq(s21_ceil(x), ceil(x));
  for (double i = -100.0; i < 100.0; i += 0.25) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), S21_EXP);
  }
}
END_TEST

START_TEST(s21_floor_func) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_floor(x));
  x = -S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  x = S21_INF;
  ck_assert_ldouble_eq(s21_floor(x), floor(x));
  for (double i = -100.0; i < 100.0; i += 0.25) {
    ck_assert_ldouble_eq_tol(s21_floor(i), floor(i), S21_EXP);
  }
}
END_TEST

START_TEST(s21_sqrt_func) {
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-256));
  ck_assert_ldouble_eq_tol(s21_sqrt(1234567890), sqrt(1234567890), S21_EXP);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), S21_EXP);
}
END_TEST

START_TEST(s21_sin_func) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), S21_EXP);
  ck_assert_ldouble_eq_tol(s21_sin(12345), sin(12345), S21_EXP);
  ck_assert_ldouble_eq_tol(s21_sin(-12345), sin(-12345), S21_EXP);
  for (double i = -S21_PI; i < S21_PI; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sin(i), S21_EXP);
  }
}
END_TEST

START_TEST(s21_cos_func) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), S21_EXP);
  x = 12345;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), S21_EXP);
  x = -12345;
  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), S21_EXP);
  for (double i = -S21_PI; i < S21_PI; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cos(i), S21_EXP);
  }
}
END_TEST

START_TEST(s21_tan_func) {
  ck_assert_double_eq_tol(s21_tan(0.23), tan(0.23), S21_EXP);
  ck_assert_double_eq_tol(s21_tan(1234567), tan(1234567), S21_EXP);
  ck_assert_double_eq_tol(s21_tan(-1234567), tan(-1234567), S21_EXP);
  for (double i = -100; i < 100; i += 2) {
    ck_assert_double_eq_tol(s21_tan(i), tan(i), S21_EXP);
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_double_eq_tol(s21_tan(i), tan(i), S21_EXP);
  }
}
END_TEST

START_TEST(s21_asin_func) {
  for (double i = -1; i < 1; i += 0.05) {
    ck_assert_double_eq_tol(s21_asin(i), asin(i), S21_EXP);
  }
  ck_assert_double_nan(s21_asin(-2));
  ck_assert_double_nan(s21_asin(1.2));
}
END_TEST

START_TEST(s21_acos_func) {
  for (double i = -1; i < 1; i += 0.05) {
    ck_assert_double_eq_tol(s21_acos(i), acos(i), S21_EXP);
  }
  ck_assert_double_nan(s21_acos(-2));
  ck_assert_double_nan(s21_acos(1.2));
}
END_TEST

START_TEST(s21_atan_func) {
  ck_assert_double_eq_tol(s21_atan(1234567), atan(1234567), S21_EXP);
  ck_assert_double_eq_tol(s21_atan(1), atan(1), S21_EXP);
  ck_assert_double_eq_tol(s21_atan(0.001), atan(0.001), S21_EXP);
  ck_assert_double_eq_tol(s21_atan(-1234567), atan(-1234567), S21_EXP);
  for (double i = -1.0; i <= 1; i += 0.05) {
    ck_assert_double_eq_tol(s21_atan(i), atan(i), S21_EXP);
  }
}
END_TEST

START_TEST(s21_exp_func) {
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_ldouble_infinite(s21_exp(123456.45));
  ck_assert_double_eq_tol(s21_exp(-S21_INF), exp(-S21_INF), S21_EPS);
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(1.0), s21_exp(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-1.0), s21_exp(-1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-123456.45), s21_exp(-123456.45), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(1.23456789), s21_exp(1.23456789), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-1.23456789), s21_exp(-1.23456789), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(0.00001), s21_exp(0.00001), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-0.00001), s21_exp(-0.00001), S21_EPS);
}

END_TEST

START_TEST(s21_fmod_func) {
  ck_assert_ldouble_eq_tol(fmod(12345.67890, 12345.67890),
                           s21_fmod(12345.67890, 12345.67890), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(-12.67, -15.6), s21_fmod(-12.67, -15.6),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(0.67890, -12345.67890),
                           s21_fmod(0.67890, -12345.67890), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(-0.67890, 12345.67890),
                           s21_fmod(-0.67890, 12345.67890), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(0, -12345.67890), s21_fmod(0, -12345.67890),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(1.0e+10, 3.0), s21_fmod(1.0e+10, 3.0), S21_EPS);
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(s21_fmod(0, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, 0));
  ck_assert_double_nan(s21_fmod(0, -S21_NAN));
  ck_assert_double_nan(s21_fmod(-S21_NAN, 3.0));
  ck_assert_double_nan(s21_fmod(123.67, 0));
  ck_assert_ldouble_eq_tol(fmod(0, S21_INF), s21_fmod(0, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(3.0, S21_INF), s21_fmod(3.0, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(3.0, -S21_INF), s21_fmod(3.0, -S21_INF),
                           S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 12345.678901));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 0));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 0));
}
END_TEST

START_TEST(s21_log_func) {
  ck_assert_ldouble_eq_tol(s21_log(2.71839), log(2.71839), S21_EPS);
  ck_assert_ldouble_infinite(s21_log(0.0));
  ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), S21_EPS);
  ck_assert_ldouble_nan(s21_log(-50.12));
  ck_assert_ldouble_eq_tol(s21_log(0.000001), log(0.000001), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_log(123456.0), log(123456.0), S21_EPS);
  ck_assert_ldouble_nan(s21_log(-S21_NAN));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_infinite(s21_log(S21_INF));
  ck_assert_ldouble_nan(s21_log(-S21_INF));
}

END_TEST

START_TEST(s21_pow_func) {
  ck_assert_ldouble_eq_tol(pow(2.0, 3.0), s21_pow(2.0, 3.0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(1.0, 3.0), s21_pow(1.0, 3.0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(1.0, S21_INF), s21_pow(1.0, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(1.0, -S21_INF), s21_pow(1.0, -S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-1.0, S21_INF), s21_pow(-1.0, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-1.0, -S21_INF), s21_pow(-1.0, -S21_INF),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-2.0, 3.0), s21_pow(-2.0, 3.0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(2.0, 3.5), s21_pow(2.0, 3.5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(2.5, 2.0), s21_pow(2.5, 2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0.0, 5.0), s21_pow(0.0, 5.0), S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(0.0, -5.5));
  ck_assert_ldouble_infinite(s21_pow(-0.5, -S21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -0.5), pow(-S21_INF, -0.5),
                           S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 0.5));
  ck_assert_ldouble_infinite(s21_pow(4.0, S21_INF));
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 4.0));
  ck_assert_ldouble_eq_tol(pow(4.0, 0.0), s21_pow(4.0, 0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-0.5, S21_INF), s21_pow(-0.5, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(-S21_INF, -4.5), s21_pow(-S21_INF, -4.5),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(pow(S21_INF, -4.5), s21_pow(S21_INF, -4.5), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(0.0, 0.0), s21_pow(0.0, 0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(pow(S21_NAN, 0), s21_pow(S21_NAN, 0), S21_EPS);
  ck_assert_double_nan(s21_pow(-2.0, 4.5));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_nan(s21_pow(0.0, -S21_NAN));
  ck_assert_double_nan(s21_pow(0.0, S21_NAN));
  ck_assert_double_nan(s21_pow(-S21_NAN, 3.0));
}

END_TEST

Suite *lib_suite(void) {
  Suite *suite;
  suite = suite_create("Functions checking");

  TCase *tc_abs = tcase_create("Abs func");
  suite_add_tcase(suite, tc_abs);
  tcase_add_test(tc_abs, s21_abs_func);

  TCase *tc_fabs = tcase_create("Fabs func");
  suite_add_tcase(suite, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_func);

  TCase *tc_ceil = tcase_create("Ceil func");
  suite_add_tcase(suite, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_func);

  TCase *tc_floor = tcase_create("Floor func");
  suite_add_tcase(suite, tc_floor);
  tcase_add_test(tc_floor, s21_floor_func);

  TCase *tc_sqrt = tcase_create("Sqrt func");
  suite_add_tcase(suite, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_func);

  TCase *tc_sin = tcase_create("Sin func");
  suite_add_tcase(suite, tc_sin);
  tcase_add_test(tc_sin, s21_sin_func);

  TCase *tc_cos = tcase_create("Cos func");
  suite_add_tcase(suite, tc_cos);
  tcase_add_test(tc_cos, s21_cos_func);

  TCase *tc_tan = tcase_create("Tan func");
  suite_add_tcase(suite, tc_tan);
  tcase_add_test(tc_tan, s21_tan_func);

  TCase *tc_asin = tcase_create("Asin func");
  suite_add_tcase(suite, tc_asin);
  tcase_add_test(tc_asin, s21_asin_func);

  TCase *tc_acos = tcase_create("Acos func");
  suite_add_tcase(suite, tc_acos);
  tcase_add_test(tc_acos, s21_acos_func);

  TCase *tc_atan = tcase_create("Atan func");
  suite_add_tcase(suite, tc_atan);
  tcase_add_test(tc_atan, s21_atan_func);

  TCase *tc_exp = tcase_create("Exp func");
  suite_add_tcase(suite, tc_exp);
  tcase_add_test(tc_exp, s21_exp_func);

  TCase *tc_fmod = tcase_create("Fmod func");
  suite_add_tcase(suite, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_func);

  TCase *tc_log = tcase_create("Log func");
  suite_add_tcase(suite, tc_log);
  tcase_add_test(tc_log, s21_log_func);

  TCase *tc_pow = tcase_create("Pow func");
  suite_add_tcase(suite, tc_pow);
  tcase_add_test(tc_pow, s21_pow_func);

  return suite;
}

int main(void) {
  Suite *s;
  SRunner *sr;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return 0;
}
