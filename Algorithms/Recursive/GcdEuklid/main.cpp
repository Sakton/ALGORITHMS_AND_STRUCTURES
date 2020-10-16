#include <iostream>

/*
a - делимое
b - делитель

алгоритм основан на формуле gcd(a, b) = gcd(b, a % b)
*/

int GcdEuklid( int a, int b )
{
    if ( b == 0 ) //базовый случай, если статок от деления равен нулю, то искомый элемент - предыдущий остаток от деления а
        return a;
    return GcdEuklid( b, a % b );
}

//можно сократить
int GcdEuclid1( int a, int b ) {
  return ( b == 0 ) ? a : GcdEuclid1( b, a % b );
}

int main( ) {
  std::cout << GcdEuklid( 50, 15 ) << std::endl;
  std::cout << GcdEuclid1( 50, 15 );
}
