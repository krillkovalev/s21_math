#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  if ((x != 0 && y == 0) || ((x - x) != 0) || (x == S21_INF && y == S21_INF) ||
      x != x || y != y || x == S21_INF) {
    result = S21_NAN;
  } else if (x == 0) {
    result = 0;
  } else if ((y == S21_INF) || (y == -S21_INF)) {
    result = x;
  } else {
    long long int quotient = 0;
    quotient = x / y;
    result = (long double)x - quotient * (long double)y;
  }
  return result;
}