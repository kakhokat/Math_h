#include "s21_math.h"

long double s21_log(double x) {
  double ex_pow = 0;
  double result = 0;
  double prev = 0;

  if (x == 1) {
    result = 0;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x > 0) {
    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) {
      continue;
    }

    for (int i = 0; i < 100; i++) {
      prev = result;
      result = prev + 2 * (x - s21_exp(prev)) / (x + s21_exp(prev));
    }
    result = result + ex_pow;
  } else {
    result = S21_NAN;
  }

  return result;
}
