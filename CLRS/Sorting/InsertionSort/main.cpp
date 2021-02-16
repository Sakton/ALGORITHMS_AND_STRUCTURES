#include <iostream>

#include "insertionsort.h"

int main( ) {
  std::cout << "Hello World!" << std::endl;
  int arr[] { 5, 2, 4, 6, 1, 3 };
  insertionSort( arr, 6, []( int a, int b ) -> bool { return a < b; } );
  for ( auto el : arr ) std::cout << el << " ";
  return 0;
}
