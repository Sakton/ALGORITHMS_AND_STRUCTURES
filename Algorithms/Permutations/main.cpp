#include <cstdint>
#include <iostream>

/*
Алгоритмы и структуры данных (С++), лекция №10
Метод ветвей и границ
*/

void Permutations( int16_t number, int16_t current, int16_t buffer[],
                   bool used[] ) {
  if ( number == current ) {
    for ( int i = 0; i < number; ++i ) std::cout << buffer[ i ] << " ";
    std::cout << std::endl;
  } else {
    for ( int16_t i = 0; i < number; ++i ) {
      if ( !used[ i ] ) {
        used[ i ] = true;
        buffer[ current ] = i;
        Permutations( number, current + 1, buffer, used );
        used[ i ] = false;
      }
    }
  }
}

int main( ) {
  int16_t buffer[ 10 ] { 0 };
  bool used[ 10 ] { false };
  Permutations( 4, 0, buffer, used );
}
