#include <iostream>
#include <string>
#include <vector>

/*
Алгоритм поиска расстояния левинштейна
Используется для радиопередач при поиске искажений и в биологии
Вычисляет минимальное количетво редакций исходной строки в нужную
редакции могут буть: удаление, вставка, замена символа, (вставка лишнего символа?)
https://ru.wikipedia.org/wiki/%D0%A0%D0%B0%D1%81%D1%81%D1%82%D0%BE%D1%8F%D0%BD%D0%B8%D0%B5_%D0%9B%D0%B5%D0%B2%D0%B5%D0%BD%D1%88%D1%82%D0%B5%D0%B9%D0%BD%D0%B0
 */

int levensein_distance( const std::string &a, const std::string &b );

int main( ) {
  std::string a( "POLYNOMIAL" ), b( "EXPONENTIAL" );
  std::cout << levensein_distance( a, b );
}

int levensein_distance( const std::string &a, const std::string &b ) {
  using size_type = std::string::size_type;
  std::vector< std::vector< int > > L( a.size( ) + 1, std::vector< int >( b.size( ) + 1 ) );

  // base case, при длине одной из строк = 0, количество правок равно длине другой строки
  //или вставок или удалений
  //заполняем базовые случаи
  for ( size_type i = 0; i <= a.size( ); ++i ) {  //строка от 0 до i включительно
    L[ i ][ 0 ] = i;
  }
  for ( size_type k = 0; k <= b.size( ); ++k ) {
    L[ 0 ][ k ] = k;
  }

  // recursive size (Динамическая таблица результатов)
  for ( size_type i = 1; i <= a.size( ); ++i ) {
    for ( size_type k = 1; k <= b.size( ); ++k ) {
      if ( a[ i - 1 ] == b[ k - 1 ] )
        L[ i ][ k ] = L[ i - 1 ][ k - 1 ];
      else
        //минимум из вставок, удалений, замен
        L[ i ][ k ] = std::min( L[ i - 1 ][ k ], std::min( L[ i ][ k - 1 ], L[ i - 1 ][ k - 1 ] ) ) + 1;
      //+1 раз символы разные, то к мин операций будет еще 1 на вставку символа или удаление
    }
  }

  return L[ a.size( ) ][ b.size( ) ];
}
