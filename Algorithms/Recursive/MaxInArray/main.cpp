#include <iostream>

/*
Алгоритм разделяй и властвуй.
Массив делится пополам и в каждой половине находится максимум
будет делится пока в каждой части не останется 1 элемент он и будет сравниваться
*/

int MaxInArray( int arr[], int l, int r )
{
    if ( l == r ) {
        return arr[ l ];
    }
    int m = ( l + r ) / 2;
    int maxL = MaxInArray( arr, l, m );
    int maxR = MaxInArray( arr, m + 1, r );
    return ( maxL > maxR ) ? maxL : maxR;
}

int main()
{
}
