#include "../s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  long double preres = 0;
  int count = 0;

  if (x == 0) {
    res = -S21_INF;
  } else if (x == 1) {
    res = 0;
  } else if (x < 0 || x == S21_NAN || x == -S21_INF) {
    res = S21_NAN;
  } else if (x == S21_INF) {
    res = S21_INF;
  } else {
    for (; x >= S21_EXP; x /= S21_EXP) {
      count++;
    }
    for (int i = 0; i < 100; i++) {
      preres = res;
      res = preres + 2 * (x - s21_exp(preres)) / (x + s21_exp(preres));
    }
    res = res + count;
  }
  return res;
}