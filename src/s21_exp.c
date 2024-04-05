#include "s21_math.h"

long double s21_exp(double x) {
  if (s21_isnan(x)) return S21_NAN;
  if (x == S21_INF || x == -S21_INF) return x < 0 ? 0 : S21_INF;
  int sign = x < 0;
  if (sign) x *= -1;
  long double result = 1;
  long double temp = x;
  unsigned flag = 1;
  while (s21_fabs(temp) >= S21_EPS) {
    result += temp;
    temp = (temp * x) / ++flag;
  }
  if (x == 1 && !sign) {
    result = S21_EXP;
  }
  return sign ? (1 / result) : result;
}
