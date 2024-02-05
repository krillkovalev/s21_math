#include "../s21_math.h"

long double s21_ceil(double x) {
  double result;

  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_INF;
  } else {
    char str[1024];
    double post_x = x;
    sprintf(str, "%.0lf", post_x);
    sscanf(str, "%lf", &result);

    if ((x > 0 && result < x) || (x < 0 && result < x)) {
      result = result + 1;
    }
  }

  return result;
}
