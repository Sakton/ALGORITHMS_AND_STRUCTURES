#include "connectednessweightedunion.h"
#include <iostream>

ConnectednessWeightedUnion::ConnectednessWeightedUnion( int n )
    : trees_( new int[ n ] )
    , count_nodes_( new int[ n ] )
    , count_elements_{ n }
{
    //1. Создаем обьекты и устанавливаем количество узлов
    //сейчас все узлы - корни деревьев с 1 узлом
    for ( int i = 0; i < n; ++i ) {
	trees_[ i ] = i;
	count_nodes_[ i ] = 1;
    }
}

void ConnectednessWeightedUnion::Display( )
{
    for ( int i = 0; i < count_elements_; ++i ) {
	std::cout << trees_[ i ] << ' ';
    }
    std::cout << std::endl;
    for ( int i = 0; i < count_elements_; ++i ) {
	std::cout << count_nodes_[ i ] << ' ';
    }
    std::cout << std::endl;
}

void ConnectednessWeightedUnion::Read( )
{
    int a = 0, b = 0;
    while ( std::cin >> a >> b ) {
	Connectedness( a, b );
	Display( );
    }
}

void ConnectednessWeightedUnion::Connectedness( int index_p, int index_q )
{
    //1. идем до корней
    int i = trees_[ index_p ];
    for ( ; i != trees_[ i ]; i = trees_[ i ] ) {
	//улучшение: сжатие пути делением пополам
	//заставляем текущий елемент ссылаться через 1 выше по дереву
	//т.е. если дерево было 1->2->3->4, то по отношению к 1 елементу оно станет 1->3->4
	//1 ссылается на 3 и 2 ссылается на 3 - или 1 стало дочерним узлом 3, а было дочерним 2
	trees_[ i ] = trees_[ trees_[ i ] ];
    }
    int j = trees_[ index_q ];
    for ( ; j != trees_[ j ]; j = trees_[ j ] ) {
	trees_[ j ] = trees_[ trees_[ j ] ];
    }
    //2. Теперь сравниваем количество элементов в деревьях
    //присоединяем меньшее дерево к большему и корректируем количество
    //меньший элемент указывает на корень большего
    //и количество элементов большего увеличилось на количество меньшего
    if ( trees_[ i ] != trees_[ j ] ) {
	if ( count_nodes_[ i ] < count_nodes_[ j ] ) {
	    trees_[ i ] = trees_[ j ];
	    count_nodes_[ j ] += count_nodes_[ i ];
	} else { //если больше или равны
	    trees_[ j ] = trees_[ i ];
	    count_nodes_[ i ] += count_nodes_[ j ];
	}
    }
}
