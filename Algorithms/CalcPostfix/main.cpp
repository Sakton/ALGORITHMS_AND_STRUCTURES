#include <iostream>
#include <stack>
#include <string>

double CalcPostfix( const std::string & s )
{
    std::stack< double > stack;
    for ( auto it = s.cbegin( ); it != s.end( ); ++it ) {
        if ( std::isdigit( *it ) ) {
            double x = 0;
            while ( std::isdigit( *it ) ) {
                x = x * 10 + ( *it - '0' );
                ++it;
            }
            stack.push( x );
        }
        if ( *it == '+' ) {
            double a = stack.top( );
            stack.pop( );
            double b = stack.top( );
            stack.pop( );
            stack.push( a + b );
        }
        if ( *it == '-' ) {
            double a = stack.top( );
            stack.pop( );
            double b = stack.top( );
            stack.pop( );
            stack.push( a - b );
        }
        if ( *it == '*' ) {
            double a = stack.top( );
            stack.pop( );
            double b = stack.top( );
            stack.pop( );
            stack.push( a * b );
        }
        if ( *it == '/' ) {
            double a = stack.top( );
            stack.pop( );
            double b = stack.top( );
            stack.pop( );
            stack.push( a / b );
        }
    }
    double res = stack.top( );
    stack.pop( );
    return res;
}

int main()
{
    //2075
    std::cout << CalcPostfix( "5 9 8 + 4 6 * * 7 + *" );
}
