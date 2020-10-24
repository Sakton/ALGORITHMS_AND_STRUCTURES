#include <cassert>
#include <chrono>
#include <iostream>

class Timer {
 private:
  // Псевдонимы типов используются для удобного доступа к вложенным типам
  using clock_t = std::chrono::high_resolution_clock;
  using second_t = std::chrono::duration< double, std::ratio< 1 > >;

  std::chrono::time_point< clock_t > m_beg;

 public:
  Timer( ) : m_beg( clock_t::now( ) ) {}

  void reset( ) { m_beg = clock_t::now( ); }

  double elapsed( ) const {
    return std::chrono::duration_cast< second_t >( clock_t::now( ) - m_beg )
        .count( );
  }
};

/*
K(i,j) = K(i - 1,j) + K(i, j - 1)
Сложность O(C(i, j))) - Количество сочетаний i по j
*/

int64_t CountPathesRecursive( int row, int col ) {
  assert( ( row >= 0 ) && ( col >= 0 ) && "Assert BOBOBOBO" );

  if ( row == 1 || col == 1 )
    return 1;
  else
    return CountPathesRecursive( row - 1, col ) +
           CountPathesRecursive( row, col - 1 );
}

int64_t CountPathesDynamic( int row, int col ) {
  // 1. Подготовка 2мерн массива
  int64_t **arr = new int64_t *[ row ];
  for ( int i = 0; i < row; ++i ) {
    arr[ i ] = new int64_t[ col ] { 0 };
  }
  // 2. Установка начальных значений
  for ( int i = 0; i < row; ++i ) {
    arr[ i ][ 0 ] = 1;
  }
  for ( int j = 0; j < col; ++j ) {
    arr[ 0 ][ j ] = 1;
  }
  // 3. Вычисление значений путей
  for ( int i = 1; i < row; ++i ) {
    for ( int j = 1; j < col; ++j ) {
      arr[ i ][ j ] = arr[ i - 1 ][ j ] + arr[ i ][ j - 1 ];
    }
  }
  // 4. Сохранение вычисленного значения
  int64_t res = arr[ row - 1 ][ col - 1 ];
  // 5. Очистка памяти
  for ( int i = 0; i < row; ++i ) {
    delete[] arr[ i ];
  }
  delete[] arr;
  return res;
}

int main( ) {
  Timer t;
  // 18,18 уже 22 сек
  std::cout << CountPathesRecursive( 18, 18 ) << std::endl;
  std::cout << "t1 = " << t.elapsed( ) << std::endl;

  t.reset( );
  std::cout << CountPathesDynamic( 18, 18 ) << std::endl;
  std::cout << "t2 = " << t.elapsed( ) << std::endl;
}
