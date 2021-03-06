#include <iostream>

/*
Алгоритм: возведение в степень через сумму
Идея
3^4 = 3*3^3 = 3^3 + 3^3 + 3^3
3^3 = 3*3^2 = 3^2 + 3^2 + 3^2
3^2 = 3 * 3 = 3 + 3 + 3
в итоге получается M-арное дерево, где M - число возводимое в степень

Базовый случай: если показатель степени = 1, то это само число
Рекуррентный случай:
      в переменную будем накапливать результаты возведения в степень
      от степени на 1 ниже и суммировать их столько раз сколько лучей вышло из узла
      т.е. (3*3^2 = 3^2 + 3^2 + 3^2), цикл по самому числу постоянен
*/

//вариант если нету умножения (именно через сумму)
int powSumm1( int x, int n )
{
    if ( n == 1 )
        return x;
    else {
        int res = 0;
        for ( int i = 0; i < x; ++i ) {
            res += powSumm1( x, n - 1 );
        }
        return res;
    }
}

//улучшение(это не лучшее возведение в степень)
//int powSumm( int x, int n )
//{
//    if ( n == 1 )
//        return x;
//    return x * powSumm( x, n - 1 );
//}

int main()
{
    std::cout << powSumm1( 10, 6 );
}
