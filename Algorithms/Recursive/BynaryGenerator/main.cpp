#include <iostream>
#include <vector>

/*
Метод поиска с возвратом (backtracking)
https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D0%B8%D1%81%D0%BA_%D1%81_%D0%B2%D0%BE%D0%B7%D0%B2%D1%80%D0%B0%D1%82%D0%BE%D0%BC
*/

void BinaryGenerator( int countRegex ) {
  static std::vector< int > res;
  res.reserve( countRegex );
  if ( countRegex == 0 ) {
    for ( auto el : res ) std::cout << el << " ";
    std::cout << std::endl;
  } else {
    res.push_back( 0 );
    BinaryGenerator( countRegex - 1 );
    res.pop_back( );
    res.push_back( 1 );
    BinaryGenerator( countRegex - 1 );
    res.pop_back( );
  }
}

int main( ) { BinaryGenerator( 3 ); }
