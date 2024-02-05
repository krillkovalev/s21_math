#include "../s21_math.h"

double range_PI(double x) {
  if (x > S21_PI || x < -S21_PI) {
    if (x > S21_PI) {
      x = x - ((long long int)(x / (2 * S21_PI))) * 2 * S21_PI - 2 * S21_PI;
    }
    if (x < -S21_PI) {
      x = x - ((int)(x / (2 * S21_PI))) * 2 * S21_PI + 2 * S21_PI;
    }
  }
  return x;
}

long double s21_cos(double x) {
  x = range_PI(x);

  double part_res = 1;
  double result = part_res;
  int n = 1;
  while (part_res > S21_EPS * S21_EPS || part_res < (-1) * S21_EPS * S21_EPS) {
    part_res = (part_res * (-1) * x * x) / ((2 * n - 1) * (2 * n));
    result += part_res;
    n += 1;
  }
  return result;
}
