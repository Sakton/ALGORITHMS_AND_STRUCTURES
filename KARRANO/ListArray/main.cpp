#include <iostream>

#include "listarray.h"

int main( ) {
  ListArray la;
  la.insert( 1, 10 );
  std::cout << la.retrieve( 1 );
  std::cout << la.retrieve( 1 );
  std::cout << la.retrieve( 1 );
  std::cout << la.retrieve( 1 );
  std::cout << la.retrieve( 1 );
  std::cout << la.retrieve( 1 );
}
