#include <iostream>

int fastPow( int a, int n ) {
  if ( n == 0 ) return 1;
  if ( n % 2 ) {
    return a * fastPow( a, n - 1 );
  } else {
    return fastPow( a * a, n / 2 );
  }
}

int fastPowIterative( int a, int n ) {
  if ( n == 0 ) return 1;
  int res = 1;
  while ( n ) {
    if ( n % 2 ) {
      res *= a;
      --n;
    } else {
      a *= a;
      n /= 2;
    }
  }
  return res;
}

int main( ) {
  std::cout << fastPow( 2, 10 ) << std::endl;
  std::cout << fastPowIterative( 2, 10 ) << std::endl;
}
