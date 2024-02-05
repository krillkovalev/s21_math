#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double result = 4.0;
  long double part_res = 0.0;
  while (s21_fabs(result - part_res) > S21_EPS * S21_EPS) {
    if (x < 0) {
      result = -S21_NAN;
      break;
    }
    if (x == S21_INF) {
      result = S21_INF;
      break;
    }

    part_res = result;
    result = (part_res + x / part_res) / 2;
  }
  return result;
}
