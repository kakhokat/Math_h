#include "s21_math.h"

long double s21_atan(double x) {
  long double sum_atan = 0;
  if (x == S21_INF) {
    sum_atan = S21_M_PI / 2;
  } else if (x == -S21_INF) {
    sum_atan = -S21_M_PI / 2;
  } else if (-1. < x && x < 1.) {
    for (register int i = 0; i < 5000 && s21_fabs(s21_pow(x, 1 + (2 * i)) /
                                                  (1 + (2 * i))) > 0.0000001;
         i++) {
      sum_atan += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (register int i = 0; i < 7000 && s21_fabs(s21_pow(x, -1 - (2 * i)) /
                                                  (1 + (2 * i))) > 0.0000001;
         i++) {
      sum_atan += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    sum_atan = S21_M_PI * s21_sqrt(x * x) / (2 * x) - sum_atan;
  }
  return sum_atan;
}