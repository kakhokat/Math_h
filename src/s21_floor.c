#include "s21_math.h"

long double s21_floor(double x) {
  if (x != S21_INF && x != -S21_INF && !s21_isnan(x)) {
    int floor_num = (int)x;
    if (x < 0 && x != floor_num) {
      floor_num--;
    }
    return floor_num;
  } else {
    return x;
  }
}