#include <iostream>
#include <string>

/*
Простой пример нисходящего анализатора
*/

double CalcPrefix( const std::string & s )
{
    int x = 0;
    static int index = 0;
    if ( s[ index ] == ' ' ) {
        ++index;
    }
    if ( s[ index ] == '+' ) {
        ++index;
        return CalcPrefix( s ) + CalcPrefix( s );
    }
    if ( s[ index ] == '-' ) {
        ++index;
        return CalcPrefix( s ) - CalcPrefix( s );
    }
    if ( s[ index ] == '*' ) {
        ++index;
        return CalcPrefix( s ) * CalcPrefix( s );
    }
    if ( s[ index ] == '/' ) {
        ++index;
        return CalcPrefix( s ) / CalcPrefix( s );
    }
    if ( std::isdigit( s[ index ] ) ) {
        while ( std::isdigit( s[ index ] ) ) {
            x = x * 10 + s[ index++ ] - '0';
        }
    }
    return x;
}

int main()
{
    //2075
    std::cout << CalcPrefix( "* + 7 * * 4 6 + 8 9 5" );
}
