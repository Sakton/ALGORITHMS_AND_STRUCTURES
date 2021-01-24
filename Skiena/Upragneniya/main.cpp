#include <iostream>

// 2.10
// 1
int mystery( int n );

int main()
{
  std::cout << mystery( 5 ) << std::endl;
  return 0;
}

int mystery( int n ) {
  int res = 0;
  for ( int i = 1; i < n - 1; ++i )
    for ( int j = i + 1; j < n; ++j )
      for ( int k = 1; k < j; ++k ) ++res;
  return res;
}
