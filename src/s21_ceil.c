#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0;
  if (x == 0 || x == S21_INF || x == -S21_INF || s21_isnan(x)) {
    result = x;
  } else {
    if (x >= 0) {
      int completed_part = (int)x;
      long double fraction = x - completed_part;
      if (fraction > 0) {
        result = completed_part + 1.0;
      } else {
        result = completed_part;
      }
    } else {
      result = (long int)x;
    }
  }
  return result;
}