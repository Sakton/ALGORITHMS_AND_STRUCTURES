#include <iostream>
#include <memory>

/*
Сложность O(N*W) - N - количество ключей, W - количество разрядов
Поразрядная LSD - least significant digit radix sort - сначала по младшей цифре
Идея - в основе метод подсчета (но не очевидно что то)
Используют когда большие ключи 2^64
*/

void RadixLsd( int arr[], int l, int r ) {
  std::unique_ptr< int[] > heap_0( new int[ r - l + 1 ] );
  std::unique_ptr< int[] > heap_1( new int[ r - l + 1 ] );

  for ( int radix = 0; radix < 32; ++radix ) {
    int index0 = 0;
    int index1 = 0;
    for ( int i = l; i <= r; ++i ) {  //разложить по кучкам в зависимости от наличия 1 в разряде
      if ( ( arr[ i ] & ( 1 << radix ) ) == 0 ) {  //масочку ёк
        heap_0[ index0++ ] = arr[ i ];
      } else {
        heap_1[ index1++ ] = arr[ i ];
      }
    }
    int ii = 0;
    for ( int i = 0; i < index0; ++i ) {  //сложить в кучу спева эти
      arr[ ii++ ] = heap_0[ i ];
    }
    for ( int i = 0; i < index1; ++i ) {  // сверху эти
      arr[ ii++ ] = heap_1[ i ];
    }
  }
}

int main()
{
  int arr[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  RadixLsd( arr, 0, 8 );
  for ( int i = 0; i <= 8; ++i ) {
    std::cout << arr[ i ] << ' ';
  }
}
