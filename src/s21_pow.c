#include "s21_math.h"

long double s21_pow_float(double base, double exp) {
  long double res;
  if (base == 0 && !s21_isnan(exp))
    res = exp < 0 ? S21_INF : 0;
  else if (base == -1 && (exp == S21_INF || exp == -S21_INF))
    res = 1;
  else if (base == 1)
    res = 1;
  else if (exp == 0)
    res = 1;
  else if (s21_isnan(base))
    res = S21_NAN;
  else if (exp == S21_INF)
    res = s21_fabs(base) < 1 ? 0 : S21_INF;
  else if (exp == -S21_INF)
    res = s21_fabs(base) < 1 ? S21_INF : 0;
  else if (base == -S21_INF && !s21_isnan(exp))
    res = exp < 0 ? 0 : S21_INF;
  else {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}

long double s21_pow_int(double base, double exp) {
  long double total = 1;
  if (exp < 0) {
    exp *= -1;
    for (int i = 0; i < exp; i++) total *= base;
    total = 1 / total;
  } else if (exp > 0) {
    for (int i = 0; i < exp; i++) total *= base;
  }
  return total;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  long double condition = exp - (long long int)exp;
  if (condition <= 0.0000001 && condition >= -0.0000001 && !s21_isnan(exp) &&
      !s21_isnan(base)) {
    res = s21_pow_int(base, exp);
  } else {
    res = s21_pow_float(base, exp);
  }
  return res;
}