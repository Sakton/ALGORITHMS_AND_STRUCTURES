#include <iostream>

/*
 * Сортировка подсчетом
Сложность O(N + M) - где N - количество сортируемых элементов,
M - колисество ключей (диапазон ключей) в котором лежат сортируемые числа

1. Собираем статистику в вспомогательный массив по количеству вхождений ключей в
сортируемый массив 2.
2. Проходя по ключам смотрим сколько раз этот ключ попался в массиве,
и столько раз перезаписываем его обратно в массив.

Сумма количеств раз вхождений элементов в исходный массив, равен длине массива

*/

void CountSort( int arr[], int l, int r, int M ) {
  //ОБЯЗАНЫ ЗНАТЬ ДИАПАЗОН
  int *statistic = new int[ M + 1 ] { 0 };
  for ( int i = l; i <= r; ++i ) {
    ++statistic[ arr[ i ] ];
  }

  int k = 0;
  for ( int i = 0; i <= M; i++ ) {
    for ( int j = 0; j < statistic[ i ]; ++j ) {
      arr[ k++ ] = i;
    }
  }
  delete[] statistic;
}

int main()
{
  int arr[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  CountSort( arr, 0, 8, 9 );
  for ( int i = 0; i <= 8; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
}
