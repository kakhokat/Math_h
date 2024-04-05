#ifndef S21_MATH
#define S21_MATH

#include <stdio.h>
#include <stdlib.h>

long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_fabs(long double x);
long double s21_fmod(double x, double y);
int s21_isnan(double x);
double s21_divide(double d1, double d2);
long double s21_sqrt(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
int s21_abs(int x);
long double s21_ceil(double x);
long double s21_floor(double x);

#define S21_EPS 1e-12
#define S21_NAN s21_divide(0, 0)
#define S21_EXP 2.7182818284590452354
#define S21_INF s21_divide(1, 0)
#define S21_M_PI 3.14159265358979323846
#define S21_DBL_MAX 1.79769e+308

#endif
