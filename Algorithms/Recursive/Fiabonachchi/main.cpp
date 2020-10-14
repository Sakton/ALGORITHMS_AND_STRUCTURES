#include <iostream>

/*
 * Проблема многих вычислений
*/

int F( int n )
{
    if ( n == 1 || n == 2 )
        return 1;
    return F( n - 1 ) + F( n - 2 );
}

int main()
{
    //55
    std::cout << F( 10 );
}
