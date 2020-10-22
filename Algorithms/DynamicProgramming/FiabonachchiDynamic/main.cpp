#include <iostream>

/*

1 1 2 3 5 8 13 21 34 55 89 143
a b c a b c a  b  c  a  b  c
*/

//восходящее динамическое программирование

int FiabonachichiDymamic( int n ) {
  int a = 1;
  int b = 1;
  int c = a + b;
  //за 1 раз вычисляются 3 числа
  while ( ( --n / 3 ) > 2 ) {  //за 1 раз вычисляются 3 числа
    a = c + b;
    b = c + a;
    c = a + b;
  }
  return c;
}

int FiabonachichiDymamic1( int n ) {
  int f1 = 0;
  int f2 = 1;
  int f = f1 + f2;
  //первое и 2 числа уже вычислены, поэтому их не учитываем
  while ( ( n-- ) > 2 ) {
    f1 = f2;
    f2 = f;
    f = f1 + f2;
  }
  return f;
}

// нисходящее динамическое программирование
//Седжевик 5.11 стр. 204

int F( int n ) {
  static int knownF[ 20 ];  //массив уже вычисленных значений
  if ( knownF[ n ] != 0 ) return knownF[ n ];
  int t = n;  //при n <= 1 установит значение в базовых случаях
  if ( n < 0 ) return 0;
  if ( n > 1 ) t = F( n - 1 ) + F( n - 2 );
  return knownF[ n ] = t;
}

int main( ) {
  std::cout << FiabonachichiDymamic( 12 ) << std::endl;
  std::cout << F( 12 ) << std::endl;
}
