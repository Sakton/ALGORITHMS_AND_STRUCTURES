#include "connectednessarray.h"

ConnectednessArray::ConnectednessArray( int32_t count_elements )
    : array_( new int[ count_elements ], []( int * arr ) {
	std::cout << "del Array" << std::endl; delete[] arr; } )
    , count_elem_{ count_elements }
{
    //множество обьектов представим в виде массива
    //где каждый элемент не связан и сам по себе, т.е. arr[i] = i, arr[3] = 3 и тд
    for ( int i = 0; i < count_elem_; ++i ) {
	array_[ i ] = i;
    }
}

void ConnectednessArray::Display( ) const
{
    for ( int i = 0; i < count_elem_; ++i ) {
	std::cout << array_[ i ] << ' ';
    }
    std::cout << std::endl;
}

void ConnectednessArray::Read( )
{
    //вводим пары - те элементы которые связаны
    int32_t p = 0;
    int32_t q = 0;

    while ( std::cin >> p >> q ) {
	Connected( p, q );
	Display( );
    }
}

void ConnectednessArray::Connected( int32_t index_p, int32_t index_q )
{
    //элементы считаются связанными если его значение указывает на связанный элемент
    //т.е. или arr[p] == q, или arr[q] == p и все связанные элементы будут указывать на
    //некий последний корень
    //запомним его, ячейка сменит свое значение на arr[p] при проходе, а нам надо знать
    //старое значение корня
    int32_t old = array_[ index_p ]; //старое значение
    int32_t now = array_[ index_q ]; //новое значение

    //и если новый элемент не звязан
    //связываем теперь все элементы с q, которые были связаны с p
    if ( old != now ) {
	//те элементы что указывали на p-й элемент (старый корень)
	//теперь указывают на q-й элемент - (новый корень)
	for ( int i = 0; i < count_elem_; ++i ) {
	    if ( array_[ i ] == old )
		array_[ i ] = now;
	}
    }
}
