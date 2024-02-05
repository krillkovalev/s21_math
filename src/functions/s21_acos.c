#include "../s21_math.h"

long double s21_acos(double x) {
  double result = x;
  if (x <= 1 && x >= -1) {
    result = S21_PI / 2.0 - s21_asin(x);
  } else {
    result = S21_NAN;
  }
  return result;
}