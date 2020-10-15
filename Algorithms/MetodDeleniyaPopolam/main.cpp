#include <cmath>
#include <iostream>

// TODO тут описание добавить
double funk( double x ) { return x * std::sin( x ) - 5 * x - std::cos( x ); }

int main( ) {
  double l = -1.0;
  double r = 1.0;
  double e = 1e-10;
  while ( std::fabs( l - r ) > e ) {
    double m = ( l + r ) / 2;
    if ( funk( m ) * funk( l ) <= 0 ) {
      r = m;
    } else {
      l = m;
    }
  }
  std::cout << "root l = " << l << std::endl;
}
