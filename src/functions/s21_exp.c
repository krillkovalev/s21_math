#include "../s21_math.h"

long double s21_exp(double x) {
  long double part_res = 1;
  long double result = 1;
  long double i = 1;
  int minus_st = 0;
  if (x < 0) {
    x *= -1;
    minus_st = 1;
  }
  while (s21_fabs(part_res) > S21_EPS * S21_EPS) {
    part_res = part_res * (x / i);
    i++;
    result += part_res;
    if (result > S21_MAX_DOUBLE) {
      result = S21_INF;
      break;
    }
  }

  if (minus_st == 1) {
    if (result > S21_MAX_DOUBLE) {
      result = 0;
    } else {
      result = 1.0 / result;
    }
  }

  if (result > S21_MAX_DOUBLE) {
    result = S21_INF;
  }

  return result;
}