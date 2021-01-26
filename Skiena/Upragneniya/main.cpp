#include <iostream>

// 2.10
// 1
int mystery( int n );
int mystery1( int n );

int main()
{
  std::cout << mystery( 4 ) << std::endl;
  //************************************************
  std::cout << mystery1( 4 ) << std::endl;
  return 0;
}

int mystery( int n ) {
  int res = 0;
  for ( int i = 1; i <= n - 1; ++i ) {
    for ( int j = i + 1; j <= n; ++j ) {
      for ( int k = 1; k <= j; ++k ) {
        ++res;
        std::cout << "i = " << i << ", j = " << j << ", k = " << k << ", res = " << res << std::endl;
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  return res;
}

int mystery1( int n ) {
  int res = 0;
  for ( int i = 1; i <= n - 1; ++i ) {
    for ( int j = i + 1; j <= n; ++j ) {
      res += j;
      std::cout << "i = " << i << ", j = " << j << ", res = " << res << std::endl;
    }
    std::cout << std::endl;
  }
  return res;
}
