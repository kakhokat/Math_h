#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int integer_part = 0;
  long double res = 0.0;

  if (y == 0 || s21_isnan(x) || s21_isnan(y) || x == S21_INF || x == -S21_INF) {
    res = S21_NAN;
  } else if (y == S21_INF || y == -S21_INF) {
    res = x;
  } else if (y != 0) {
    integer_part = x / y;
    res = (long double)x - integer_part * (long double)y;
  }
  return res;
}
