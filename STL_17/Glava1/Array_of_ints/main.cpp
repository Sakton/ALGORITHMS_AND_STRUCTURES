#include <iostream>

#include "array_of_ints.h"

void double_each_element( array_of_ints &arr );

int main( ) {
  array_of_ints arr;
  for ( int i = 0; i < arr.size( ); ++i ) {
    arr.at( i ) = 10 * i;
  }
  for ( int i = 0; i < arr.size( ); ++i ) {
    std::cout << arr.at( i ) << " ";
  }
  std::cout << std::endl;
  double_each_element( arr );
  for ( int i = 0; i < arr.size( ); ++i ) {
    std::cout << arr.at( i ) << " ";
  }
}

void double_each_element( array_of_ints &arr ) {
  for ( int i = 0; i < arr.size( ); ++i ) {
    arr.at( i ) *= 2;
  }
}
