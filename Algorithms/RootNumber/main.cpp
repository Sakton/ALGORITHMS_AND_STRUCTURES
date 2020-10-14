#include <cmath>
#include <iostream>

/*
Итерационная формула Герона
https://ru.wikipedia.org/wiki/%D0%98%D1%82%D0%B5%D1%80%D0%B0%D1%86%D0%B8%D0%BE%D0%BD%D0%BD%D0%B0%D1%8F_%D1%84%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%93%D0%B5%D1%80%D0%BE%D0%BD%D0%B0

*/

double RootQuadrat( double num ) {
  double root = num / 2;  //начальное предположение о корне
  double e = 1e-4;
  while ( ( root - num / root ) > e ) {
    root = ( root + num / root ) / 2;
  }
  return root;
}

/*
Алгоритм нахождения корня n-ной степени
https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%BD%D0%B0%D1%85%D0%BE%D0%B6%D0%B4%D0%B5%D0%BD%D0%B8%D1%8F_%D0%BA%D0%BE%D1%80%D0%BD%D1%8F_n-%D0%BD%D0%BE%D0%B9_%D1%81%D1%82%D0%B5%D0%BF%D0%B5%D0%BD%D0%B8
*/

double RootNn( double num, double n ) {
  double root = num / 2;  //начальное предположение о корне
  double e = 1e-4;
  double root1 = ( ( n - 1 ) * root + num / std::pow( root, n - 1 ) ) / n;
  while ( std::fabs( root - root1 ) > e ) {
    root = root1;
    root1 = ( ( n - 1 ) * root + num / std::pow( root, n - 1 ) ) / n;
  }
  return root;
}

int main( ) {
  std::cout << RootQuadrat( 10 ) << std::endl;
  std::cout << RootNn( 10, 2 ) << std::endl;
}
