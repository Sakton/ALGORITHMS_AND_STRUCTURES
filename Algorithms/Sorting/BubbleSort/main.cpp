#include <iostream>

/*
Сложность: O(N^2)
Идея:
Идя с конца массива в начало, каждый раз выбираем наименьший элемент и двигаем
его в начало, тем самым наименьший элемент будет двигаться к позиции i и займет
это место. то что левее позиции i - отсортированно
*/

void BubbleSort( int arr[], int l, int r ) {
  for ( int i = 0; i < r; ++i ) {
    for ( int j = r; j >= i; --j ) {
      if ( arr[ j ] < arr[ j - 1 ] ) std::swap( arr[ j ], arr[ j - 1 ] );
    }
  }
}

int main()
{
  int arr[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  BubbleSort( arr, 0, 8 );
  for ( int i = 0; i <= 8; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
}
