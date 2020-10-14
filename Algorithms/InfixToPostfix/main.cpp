#include <iostream>
#include <stack>
#include <string>

std::string InfixToPostfix( const std::string & str )
{
    std::string res;
    std::stack< char > stack;
    for ( char ch : str ) {
        if ( '1' <= ch && ch <= '9' ) {
            res += ch;
        }
        if ( ch == ')' ) {
            res += stack.top( );
            stack.pop( );
        }
        if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
            stack.push( ch );
        }
    }
    return res;
}

int main()
{
    std::cout << InfixToPostfix( "(5*(((9+8)*(4*6))+7)" );
}
