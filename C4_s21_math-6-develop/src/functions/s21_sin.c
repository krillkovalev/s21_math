#include "../s21_math.h"

long double s21_sin(double x) {
  x = range_PI(x);

  double part_res = x;
  double result = part_res;
  int n = 0;
  while (part_res > S21_EPS * S21_EPS || part_res < (-1) * S21_EPS * S21_EPS) {
    part_res = (part_res * (-1) * x * x) / ((2 * n + 2) * (2 * n + 3));
    result += part_res;
    n += 1;
  }
  return result;
}
