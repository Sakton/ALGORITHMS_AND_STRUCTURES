#include <iostream>

#include "listarray.h"

int main( ) {
  try {
    ListArray la;
    for ( int i = 1; i < 2; ++i ) la.insert( i, 10 * i );
    std::cout << la.retrieve( 1 );
    std::cout << la.retrieve( 1 );
    std::cout << la.retrieve( 1 );
    std::cout << la.retrieve( 1 );
    std::cout << la.retrieve( 1 );
    std::cout << la.retrieve( 1 );
  } catch ( ListArrayIndexOutOfRangeException &e ) {
    std::cerr << e.what( );
  } catch ( ListArrayException &e ) {
    std::cerr << e.what( );
  } catch ( std::out_of_range &e ) {
    std::cerr << e.what( );
  } catch ( std::exception &e ) {
    std::cerr << e.what( );
  } catch ( ... ) {
    std::cerr << "unknown Exception";
  }
}
