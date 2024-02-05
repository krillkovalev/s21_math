#include "../s21_math.h"

long double s21_floor(double x) {
  long double result;
  if (x == s21_ceil(x))
    result = x;
  else
    result = s21_ceil(x) - 1;
  return result;
}