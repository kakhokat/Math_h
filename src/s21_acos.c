#include "s21_math.h"

long double s21_acos(double x) {
  long double ans = 0;
  if (x > 0 && x <= 1.) {
    ans = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x >= -1. && x < 0) {
    ans = S21_M_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x == 0) {
    ans = S21_M_PI / 2;
  } else {
    ans = S21_NAN;
  }
  return ans;
}