#include "resheto.h"

#include <iostream>

Resheto::Resheto(int n) { data_ = std::vector<int>(n, 1); }

void Resheto::Print() {
  for (std::size_t i = 2; i < data_.size(); ++i) {
    if (data_[i]) std::cout << i << " ";
  }
  std::cout << std::endl;
}

/*
Алгоритм:
Начиная с 2 и пока квадрат проверяемого числа меньше последнего искомого из
интервала
делаем:
если элемент - простое число, то начиная с следующего кратного i числа обьявляем
их уже не простыми т.е.  = 0
*/

void Resheto::Work() {
  //начиеаем с 2, пока квадрат i меньше длины
  for (std::size_t i = 2; i * i < data_.size(); ++i) {
    if (data_[i]) {
      for (int j = i; j * i < data_.size(); ++j) {
        data_[j * i] = 0;
      }
    }
  }
}
