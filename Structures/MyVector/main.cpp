#include <iostream>
#include <vector>

#include "MyVector.h"

using namespace sktn;

int main( ) {
  MyVector< int > myVector( 10 );
  int x = 111;
  for ( auto it = myVector.begin( ); it != myVector.end( ); ++it ) {
    *it = ++x;
  }

  for ( auto it = myVector.cbegin( ); it != myVector.cend( ); ++it ) {
    *it = 10;
    std::cout << *it << " ";
  }

  //  std::vector< int > v { 20, 30, 40, 50, 60, 70, 80, 90 };
  //  MyVector< int > vv( v.cbegin( ), v.cend( ) );

  //  for ( auto &el : vv ) std::cout << el << " ";

  // std::copy( myVector.begin( ), myVector.end( ), std::ostream_iterator< int >( std::cout, " " ) );

  return 0;
}
