#ifndef ORGRAPH_H
#define ORGRAPH_H
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using vertex_t = int32_t;

class OrGraph_t {
 public:
  void input( ) {
    std::cin >> vertex_number;
    std::cin >> edges_number;
    sets_of_neighbors.clear( );
    // создает вектор с пустыми множествами ( пустые списки
    // смежности для каждой вершины )
    sets_of_neighbors.resize( vertex_number );
    while ( edges_number-- ) {
      vertex_t a, b;
      std::cin >> a >> b;
      sets_of_neighbors[ a ].insert( b );  // вставка соседа b вершины a
      //   sets_of_neighbors[ b ].insert( a );  // вставка соседа a вершины b
      // они взаимные соседи
    }
  }

  void print( ) {
    int i = 0;
    for ( auto sosedi : sets_of_neighbors ) {
      std::cout << i++ << " --> [ ";
      for ( auto el : sosedi ) {
	std::cout << el << ", ";
      }
      std::cout << "\b\b ]\n";
    }
  }

  // private:
  int vertex_number { 0 };
  int edges_number { 0 };
  // словарь, от вершины и ее отображение на множество вершин
  // соседей или списки смежности для каждой вершины
  std::vector< std::set< vertex_t > > sets_of_neighbors;
};

#endif	// ORGRAPH_H
