#include <iostream>

// кузнечик ищет путь по наименьшим стоимостям
// https://www.youtube.com/watch?v=y8X781XLt-o (1:40:00)

int min_cost( int n, int cennik[] ) {
  int *tmp = new int[ n + 1 ];
  tmp[ 1 ] = cennik[ 1 ];
  tmp[ 2 ] = cennik[ 1 ] + cennik[ 2 ];
  for ( int i = 3; i <= n; ++i ) {
    tmp[ i ] = std::min( tmp[ i - 1 ], tmp[ i - 2 ] ) + cennik[ i ];
  }

  //путь индексов
  int current = n;
  std::cout << current << " ";
  while ( current != 1 ) {
    if ( tmp[ current - 1 ] == tmp[ current ] - cennik[ current ] ) {
      current -= 1;
    } else {
      current -= 2;
    }
    std::cout << current << " ";
  }
  std::cout << std::endl;
  return tmp[ n ];
}

int main( ) {
  // int cennic[ 10 ] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  // int cennic[ 10 ] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  // int cennic[ 10 ] { 0, 1, 2, 4, 8, 16, 32, 64, 128, 100 };
  // int cennic[ 10 ] { 1, 0, 2, 4, 8, 16, 32, 64, 50 };  // 9 7 5 3 1
  int cennic[ 10 ] { 1, 0, 2, 4, 8, 16, 32, 64, 20 };  // 9 8 6 4 2 1
  std::cout << min_cost( 9, cennic );
}
