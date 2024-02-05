#include "../s21_math.h"

long double s21_asin(double x) {
  double part_res = x;
  double result = part_res;
  int n = 1;
  while (part_res > S21_EPS * S21_EPS || part_res < -S21_EPS * S21_EPS) {
    if (x < -1 || x > 1) {
      result = S21_NAN;
      break;
    }
    if (x == 1 || x == -1) {
      result = S21_PI / 2 * x;
      break;
    }
    part_res *= x * x * (2 * n - 1) * (2 * n - 1) / ((2 * n + 1) * 2 * n);
    n += 1;
    result += part_res;
  }
  return result;
}