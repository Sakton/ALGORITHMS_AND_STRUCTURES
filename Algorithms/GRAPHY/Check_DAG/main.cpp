#include <iostream>

#include "OrGraph.h"

/*
 * Алгоритм проверки на ацикличность графа
 *
 *
5
7
0 1
1 2
2 0
0 3
3 4
0 4
1 4
 * */

bool check_DAG( const OrGraph_t &graph, vertex_t start, std::vector< bool > &used ) {
  // reccurent version
  used[ start ] = true;
  std::cout << start << " used " << std::endl;
  auto neighbors_list = graph.sets_of_neighbors[ start ];
  for ( auto neighbor : neighbors_list ) {
    if ( neighbor == start ) continue;	//если пытамся пойти в саму себя ( текущую вершину из которой идем )
    if ( used[ neighbor ] ) return false;  //если сосед уже пройден и мы пытаемся в нее попасть - это цикл
    bool is_DAG = check_DAG( graph, neighbor, used );
    if ( !is_DAG ) return false;  // если по другим соседям найден цикл - тоже есть цикл
  }
  return true;	//если попали сюда, то циклов нет
}

int main()
{
  OrGraph_t grf;
  grf.input( );
  grf.print( );
  std::vector< bool > used( grf.vertex_number, false );
  // надо перебрать по всем вершинам, так как могут быть разные компоненты связности
  bool is_DAG = true;
  for ( int i = 0; i < grf.vertex_number; ++i ) {
    if ( used[ i ] ) continue;
    if ( !check_DAG( grf, i, used ) ) {
      is_DAG = false;
      break;
    }
  }

  if ( is_DAG )
    std::cout << "yes! this is acyclic graph" << std::endl;
  else
    std::cout << "NO! this is not acyclic graph" << std::endl;
}
