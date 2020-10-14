#include "connectednesstree.h"
#include <iostream>

ConnectednessTree::ConnectednessTree( int count_elements )
    : array_( new int[ count_elements ], []( int * arr ) -> void {
	std::cout << "del array" << std::endl;
	delete[] arr;
    } )
    , count_element_{ count_elements }
{
    //В начале никто не связан и каждый обьет показывает на себя
    for ( int i = 0; i < count_element_; ++i ) {
	array_[ i ] = i;
    }
}

void ConnectednessTree::Display( ) const
{
    for ( int i = 0; i < count_element_; ++i ) {
	std::cout << array_[ i ] << ' ';
    }
    std::cout << std::endl;
}

void ConnectednessTree::Read( )
{
    int p = 0, q = 0;
    while ( std::cin >> p >> q ) {
	Connectedness( p, q );
	Display( );
    }
}

void ConnectednessTree::Connectedness( int index_p, int index_q )
{
    //находим корни деревьев
    //начальное значение индекса на указатель следующего элемента в ячеке
    int i = array_[ index_p ];

    std::cout << array_[ index_p ] << "->";
    //двигаемся по указателям пока не найдется такой что показавает на себя - корень 1 дерева
    for ( ; i != array_[ i ]; i = array_[ i ] ) {
	std::cout << array_[ i ] << "->";
    }
    std::cout << std::endl;

    int j = array_[ index_q ];

    std::cout << array_[ index_q ] << "->";
    //двигаемся по указателям пока не найдется такой что показавает на себя - корень 2 дерева
    for ( ; j != array_[ j ]; j = array_[ j ] ) {
	std::cout << array_[ i ] << "-->";
    }

    std::cout << std::endl;

    if ( array_[ i ] != array_[ j ] ) { //если
	array_[ i ] = array_[ j ]; //связываем корни, получаем одно дерево из 2
    }
}
