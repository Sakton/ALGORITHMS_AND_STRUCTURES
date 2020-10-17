#include <iostream>

//алгоритм хирьянова МФТИ
// TODO алгоритм - гавно ПЕРЕДЕЛАТЬ
void MergeSort( int *A, int16_t sz ) {
  if ( sz <= 1 ) return;
  int16_t middle = sz / 2;
  int *left = A;
  int *right = A + middle;
  int16_t left_size = middle;
  int16_t right_size = sz - left_size;
  MergeSort( left, left_size );
  MergeSort( right, right_size );
  // Merge
  int *merg_array = new int[ sz ];

  int i_l = 0;
  int i_r = 0;
  int i_m = 0;

  while ( i_l < left_size && i_r < right_size ) {
    if ( left[ i_l ] <= right[ i_r ] ) {
      merg_array[ i_m++ ] = left[ i_l++ ];
    } else {
      merg_array[ i_m++ ] = right[ i_r++ ];
    }
  }

  while ( i_l < left_size ) {
    merg_array[ i_m++ ] = left[ i_l++ ];
  }

  while ( i_r < right_size ) {
    merg_array[ i_m++ ] = right[ i_r++ ];
  }
  // copy
  //каждый рекурсивный вызов переписывает исходный массив ???
  //при сбое или исключении - данные будут утеряны
  for ( int i = 0; i < sz; ++i ) A[ i ] = merg_array[ i ];

  delete[] merg_array;
}

int main()
{
  int arr[] { 5, 4, 3, 2, 1, 9, 8, 7, 6, 0 };
  MergeSort( arr, 10 );
  for ( int i = 0; i < 10; ++i ) std::cout << arr[ i ] << " ";
  return 0;
}
