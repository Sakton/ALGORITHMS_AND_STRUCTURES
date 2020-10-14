#ifndef RESHETO_H
#define RESHETO_H
#include <vector>

/*
Сложность: N + N/2 + N/3 + N/5 + ... = N(1+1/2+1/3+1/4+...) = N*Hn (Hn -
гармонические числа) а Hn =~ Ln(N) => O(N*Ln(N)) - Ln - натуральный логарифм
 *
Представление: сами числа представляются индексами, а прорстое оно или нет
значением ячейки по этому индексу.


Вопрос как найти протые на интервале
*/

class Resheto {
public:
  Resheto(int n);
  void Print();
  void Work();

private:
  std::vector<int> data_;
};

#endif // RESHETO_H
