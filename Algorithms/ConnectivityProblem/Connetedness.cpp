#include "Connetedness.h"
#include <iostream>

Connetedness::Connetedness( int countElements )
    : connectedness( countElements, 0 )
    , sizesTree( countElements, 1 )
{
    //каждому элементу, расположенному по индексу, приваиваем значение индекса
    for ( int i = 0; i < countElements; ++i ) {
	connectedness[ i ] = i;
    }
}

void Connetedness::addInCin( )
{
    std::cout << "Enter pair p q \n";
    int p, q;
    while ( std::cin >> p >> q ) {
	if ( p < 0 || q < 0 ) {
	    std::cin.ignore( std::numeric_limits< std::streamsize >::max( ), '\n' );
	    break;
	}
	//connected( p, q );
	//connectedTree(p,q);
	connectedTreeVzv( p, q );
    }
}

void Connetedness::vievsTests( int & p, int & q )
{
    std::cout << p << " " << q << "    ";
    printResult( );
}

void Connetedness::connectPairs( VecPair vp )
{
    for ( auto [ p, q ] : vp ) {
	//connected( p, q );
	//connectedTree(p,q);
	//connectedTreeVzv( p, q );
	connectecTreeVzvDiv2( p, q );

	vievsTests( p, q );
    }
}

void Connetedness::printResult( )
{
    for ( auto el : connectedness ) {
	std::cout << el << " ";
    }
    std::cout << std::endl;
}

void Connetedness::resize( int count )
{
    connectedness.resize( 2 * count );
}

void Connetedness::connected( int p, int q )
{
    // O(M*N)
    // p и q - индексы, связываем с индексом q
    // индексы связаны - если елементы по эим индексам одинаковы
    //***
    //необходимо сохранить значение елемента, так как при проходе массива он может измениться
    int t = connectedness[ p ];
    if ( t == connectedness[ q ] ) //если индекся связаны, то ничего не делаем
	return;
    for ( std::size_t i = 0; i < connectedness.size( ); ++i ) {
	// в этом алгоритме элементы связанных индексов имеют одинаковое значение
	// если i-й элемент связан с элементом P, то связываем его с индексом Q,
	// тоесть присваиваем всем связанным с P элементом значения Q элемента
	// тем самым они становятся все связаны с Q элементом
	if ( connectedness[ i ] == t ) {
	    connectedness[ i ] = connectedness[ q ];
	}
    }
}

void Connetedness::connectedTree( int p, int q )
{
    // улучшение 1
    // O((N-1)/2)
    // алгоритм выражает связность в виде дерева
    // p, q - индексы которые связазываются
    // вначале i = p, j = q - начальное положение
    int i = p;
    int j = q;
    // так как представление - дерево, и всязные компоненты представляют дерево
    // то корнем дерева будет элемент раный индексу
    // двигаемся до корней по деревьям
    for ( ; i != connectedness[ i ]; i = connectedness[ i ] )
	;
    for ( ; j != connectedness[ j ]; j = connectedness[ j ] )
	;
    // если корни разные - то это разные деревья связанных элементов
    // и связываем оба дерева через их корни
    if ( i != j )
	// дерево с корнем в i, становится поддеревом дерева с крнем в j
	connectedness[ i ] = j;
}

void Connetedness::connectedTreeVzv( int p, int q )
{
    // улучшение метода connectedTree()
    // в этом алгоритме нужна вспомогательная структура данных - массив
    // который хранит количество узлов в соответствующих деревьях
    // чтобы операция обьединения могла связывать меньшее из 2 деревьев
    int i = p;
    int j = q;
    for ( ; i != connectedness[ i ]; i = connectedness[ i ] )
	;
    for ( ; j != connectedness[ j ]; j = connectedness[ j ] )
	;
    if ( i != j ) {
	if ( sizesTree[ i ] < sizesTree[ j ] ) {
	    connectedness[ j ] = i;
	    sizesTree[ j ] += sizesTree[ i ];
	}
	else {
	    connectedness[ i ] = j;
	    sizesTree[ i ] += sizesTree[ j ];
	}
    }
}

void Connetedness::connectecTreeVzvDiv2( int p, int q )
{
    // улучшение метода connectedTreeVzv()
    // в этом алгоритме нужна вспомогательная структура данных - массив
    // который хранит количество узлов в соответствующих деревьях
    // чтобы операция обьединения могла связывать меньшее из 2 деревьев
    // улучшение состоит в том, что во время поиска корня, уменьшаем пути деревьев в 2 раза
    int i = p;
    int j = q;
    for ( ; i != connectedness[ i ]; i = connectedness[ i ] ) {
	connectedness[ i ] = connectedness[ connectedness[ i ] ];
    }
    for ( ; j != connectedness[ j ]; j = connectedness[ j ] ) {
	connectedness[ j ] = connectedness[ connectedness[ j ] ];
    }
    if ( i != j ) {
	if ( sizesTree[ i ] < sizesTree[ j ] ) {
	    connectedness[ j ] = i;
	    sizesTree[ j ] += sizesTree[ i ];
	}
	else {
	    connectedness[ i ] = j;
	    sizesTree[ i ] += sizesTree[ j ];
	}
    }
}
