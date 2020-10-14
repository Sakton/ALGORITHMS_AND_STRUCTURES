#include <iostream>

//Вариант Хирьянова;

void insertionSortKhiryanov( int arr[], int n ) {
  for ( int pos = 0; pos < n - 1; ++pos ) {
    for ( int i = pos + 1; i < n; ++i ) {
      if ( arr[ i ] < arr[ pos ] ) {
        std::swap( arr[ pos ], arr[ i ] );
      }
    }
  }
}

/*
Сложность O(N^2)
Описание:
Знаем что минимальный элемент (или соответствующий условию сортировки)
должен быть на 1 месте, или на месте текущего i
Начиная со следующего и до конца элемента сравниваем елементы с элементом в
нужной позиции и если условие выполняется то меняем их местами. Тем самым
меньший элемент встанет на 1 позицию, также рассматриваем позицию 2 и так далее
до (n - 1) позиции, так как последний элемент в последней позиции уже будет
максимальным.
*/

void SelectionSort1( int arr[], int l, int r ) {
  for ( int i = l; i < r; ++i ) {
    int min = i;
    for ( int j = i + 1; j <= r; ++j ) {
      if ( arr[ j ] < arr[ min ] ) {
        std::swap( arr[ j ], arr[ min ] );
      }
    }
  }
}

/*
В принципе переменная max и не нужна тогда:
такая же как и у хирьянова
*/

void SelectionSort( int arr[], int l, int r ) {
  for ( int i = l; i < r; ++i ) {
    for ( int j = i + 1; j <= r; ++j ) {
      if ( arr[ j ] < arr[ i ] ) {
        std::swap( arr[ j ], arr[ i ] );
      }
    }
  }
}

int main( ) {
  int arr[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  SelectionSort( arr, 0, 8 );
  for ( int i = 0; i <= 8; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
}
