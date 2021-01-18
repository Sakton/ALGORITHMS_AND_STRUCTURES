#include <iostream>
#include <queue>

#include "Graph.h"
/*
5
7
0 1
1 2
2 0
0 3
3 4
0 4
1 4
*/

// DFS - в глубину
// BFS - в ширину

void just_dfs( const Graph_t &graph, vertex_t start, std::vector< bool > &used );
void just_bfs( const Graph_t &graph, vertex_t start, std::vector< bool > &used );

int main( ) {
  Graph_t grf;
  grf.input( );
  grf.print( );
  std::vector< bool > used( grf.vertex_number, false );
  //  just_dfs( grf, 0, used );
  //  std::cout << std::endl << std::endl;
  just_bfs( grf, 0, used );
}

void just_dfs( const Graph_t &graph, vertex_t start, std::vector< bool > &used ) {
  // reccurent version
  used[ start ] = true;
  std::cout << start << " used " << std::endl;
  auto neighbors_list = graph.sets_of_neighbors[ start ];
  for ( auto neighbor : neighbors_list ) {
    if ( !used[ neighbor ] ) just_dfs( graph, neighbor, used );
  }
}

void just_bfs( const Graph_t &graph, vertex_t start, std::vector< bool > &used ) {
  std::queue< vertex_t > fired;
  fired.push( start );
  used[ start ] = true;
  std::cout << start << " used_bfs " << std::endl;
  while ( !fired.empty( ) ) {
    vertex_t cur = fired.front( );
    fired.pop( );
    auto neighbors_list = graph.sets_of_neighbors[ cur ];
    for ( auto neighbor : neighbors_list ) {
      if ( !used[ neighbor ] ) {
	std::cout << neighbor << " used_bfs " << std::endl;
	used[ neighbor ] = true;
	fired.push( neighbor );
      }
    }
  }
  std::cout << std::endl;
}
