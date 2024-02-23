#include "../s21_math.h"

long double s21_atan(double x) {
  double result = 0;

  if (x < 1 && x > -1) {
    result = ch_atan(x);
  } else if (x == 1) {
    result = S21_PI / 4;
  } else if (x == -1) {
    result = -S21_PI / 4;
  } else if (x > 1) {
    result = S21_PI / 2 - ch_atan(1 / x);
  } else if (x < -1) {
    result = -S21_PI / 2 - ch_atan(1 / x);
  }

  return result;
}

long double ch_atan(double x) {
  double part_res = x;
  double result = part_res;
  int n = 1;
  while (s21_fabs(part_res) > S21_EPS * S21_EPS) {
    part_res = -1 * part_res * x * x * (2 * n - 1) / (2 * n + 1);
    n += 1;
    result += part_res;
  }
  return result;
}