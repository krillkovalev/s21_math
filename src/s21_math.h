#ifndef __S21_MATH__
#define __S21_MATH__

#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define S21_PI 3.14159265358979324
#define S21_EPS 1e-6
#define S21_LN10 2.30258509299404590109
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_MAX_DOUBLE 1.7976931348623157e308
#define S21_EXP 2.71828182845904523536

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_sqrt(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
long double s21_log(double x);
double range_PI(double x);
long double ch_atan(double x);

#endif
