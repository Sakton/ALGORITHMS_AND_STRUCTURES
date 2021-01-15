#include <iostream>

int fastPow( int a, int n ) {
  if ( n == 0 ) return 1;
  if ( n % 2 ) {
    return a * fastPow( a, n - 1 );
  } else {
    return fastPow( a * a, n / 2 );
  }
}

int main( ) { std::cout << fastPow( 2, 10 ); }
