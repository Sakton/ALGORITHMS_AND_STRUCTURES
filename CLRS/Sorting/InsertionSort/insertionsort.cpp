#include "insertionsort.h"

// InsertionSort::InsertionSort()
//{

//}

//ИНИЦИАЛИЗАЦИЯ

//СОХРАНЕНИЕ

//ЗАВЕРШЕНИЕ
void insertionSort( int arr[], int n ) {
  for ( int j = 1; j < n; ++j ) {
    int key = arr[ j ];
    int i = j - 1;
    while ( i >= 0 && arr[ i ] > key ) {
      arr[ i + 1 ] = arr[ i ];
      --i;
    }
    arr[ i + 1 ] = key;
  }
}
