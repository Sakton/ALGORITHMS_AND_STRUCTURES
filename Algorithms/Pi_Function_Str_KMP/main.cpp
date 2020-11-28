#include <iostream>
#include <string>
#include <vector>

// аналог https://e-maxx.ru/algo/z_function
// описание текущей
// https://e-maxx.ru/algo/prefix_function

std::vector< int > prefix_function( const std::string &s );

int main( ) {
  //  std::string line;
  //  std::getline( std::cin, line );
  //  std::string tmp;
  //  std::getline( std::cin, tmp );

  std::string s1 = "accabacbabacabacabaabacaaba";
  std::string s2 = "abacaba";

  std::string summary = s2 + '#' + s1;
  // std::cout << summary;

  std::vector< int > pi = prefix_function( summary );
  std::string::size_type counter = 0;
  for ( auto &el : pi )
    if ( el == static_cast< int >( s2.size( ) ) ) ++counter;
  std::cout << "counter = " << counter;
}

std::vector< int > prefix_function( const std::string &s ) {
  int n = s.size( );
  std::vector< int > pi( n );
  for ( int i = 1; i < n; ++i ) {
    int k = pi[ i - 1 ];  //предыдущее значение пи-фии
    while ( k > 0 && s[ i ] != s[ k ] ) {
      k = pi[ k - 1 ];  //ищем по найденным предыдущим пи ф-ям символ
      //либо прийдет в 0, либо в место где определено значение ф-ии в подстроке
    }
    if ( s[ i ] == s[ k ] ) {  //пи ф-я увеличится если символы совпали
      ++k;
    }
    pi[ i ] = k;  //результ пи ф-ии на этом этапе
  }
  return pi;
}
