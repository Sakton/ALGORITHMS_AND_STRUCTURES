#include <iostream>
#include <vector>

/*
Пусть известны кратчайшие расстояния между городами
Возможно есть путь короче и через некий промежуточный город K
выбираем минимум между известным растоянием, и суммой расстояний через город(а) К.
Динамическое программирование. Сложность O(n3).
https://www.youtube.com/watch?v=ZN7z_TUjVTY
 */

void print( std::vector< std::vector< int > > &graph );

int main( ) {
  std::vector< std::vector< int > > graph { { 0, 8, 10, 100 }, { 8, 0, 3, 100 }, { 10, 3, 0, 5 }, { 100, 100, 5, 0 } };
  int numberOfSities = 4;

  print( graph );

  for ( int k = 0; k < numberOfSities; ++k )
    for ( int i = 0; i < numberOfSities; ++i )
      for ( int j = 0; j < numberOfSities; ++j )
	graph[ i ][ j ] = std::min( graph[ i ][ j ], graph[ i ][ k ] + graph[ j ][ k ] );

  std::cout << std::endl << std::endl;
  print( graph );
}

void print( std::vector< std::vector< int > > &graph ) {
  for ( auto &vec : graph ) {
    for ( auto &el : vec ) {
      std::cout << el << " ";
    }
    std::cout << std::endl;
  }
}
