#include <algorithm>
#include <iostream>
#include <vector>

void dejkstra( const std::vector< std::vector< int > > &graph, int start );
bool allVisited( std::vector< int > &visited );

int main()
{
  dejkstra( { { 0, 7, 9, 1000, 1000, 14 },
	      { 7, 0, 10, 15, 1000, 1000 },
	      { 9, 10, 0, 11, 1000, 2 },
	      { 1000, 15, 11, 0, 6, 1000 },
	      { 1000, 1000, 1000, 6, 0, 9 },
	      { 14, 1000, 2, 1000, 9, 0 } },
	    0 );
}

void dejkstra( const std::vector< std::vector< int > > &graph, int start ) {
  std::vector< int > visited( graph.size( ), 0 );  // вектор отметок посещения вершины
  std::vector< int > lenth( graph.size( ), 1000 );  // вектор минимальных путей (вектор конечных длин)
  lenth[ start ] = 0;				    // длина на стартовой вершине = 0
  visited[ start ] = 1;				    // посещаем ее, раз с нее начинаем
  int lenGraph = graph.size( );
  while ( !allVisited( visited ) ) {
    for ( int i = 0; i < lenGraph; ++i ) {  // проход по смежным вершинам
      if ( !visited[ i ] && graph[ start ][ i ] < 1000 ) {
	// если вершина не помечена как окончательная, и она смежная, то пытаемся улучшить ситуацию
	int a = graph[ start ][ i ];
	int b = lenth[ start ];
	int sum = a + b;
	if ( lenth[ i ] > sum ) lenth[ i ] = sum;
      }
    }
    //находим новую вершину (из не посещенных) путь к которой минимален из массива конечных длин
    int min = 1000;
    for ( int j = 0; j < static_cast< int >( lenth.size( ) ); ++j ) {
      if ( !visited[ j ] && ( lenth[ j ] < min ) ) {
	min = lenth[ j ];
	start = j;
      }
    }
    visited[ start ] = 1;
  }
}

bool allVisited( std::vector< int > &visited ) {
  return std::find( visited.begin( ), visited.end( ), 0 ) == visited.end( );
}
