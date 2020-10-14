#include <iostream>
#include <vector>
/*
рисуем линейку рекурсивно:
рекурсия ведется по количеству штрихов или высоты линейки
ограничения: длина линейки - это степень 2
пока высота есть делим интервал пополам и в конце лепим штрих
*/

using my = std::vector< std::vector< char > >;

void Rule( int l, int r, int h )
{
    static my rule( 4, std::vector< char >( r - l, '_' ) );
    //static int hh = std::max( h, hh ); //держим максимальное значение
    static int hh = h;
    //    std::cout << "hh = " << hh;
    int m = ( l + r ) / 2;
    if ( h > 0 ) {
        for ( int i = 0; i < h; ++i ) {
            rule[ i ][ m ] = '|';
        }
        Rule( l, m, h - 1 );
        Rule( m + 1, r, h - 1 );
    }

    if ( h == hh ) {
        //можно добавить штрихи в начало и конец
        for ( int i = h - 1; i >= 0; --i ) {
            for ( int j = 0; j < ( r - l ); ++j ) {
                std::cout << rule[ i ][ j ];
            }
            std::cout << std::endl;
        }
    }
}

int main( )
{
    Rule( 0, 63, 4 );
}
