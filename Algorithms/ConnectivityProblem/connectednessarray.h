#ifndef CONNECTEDNESSARRAY_H
#define CONNECTEDNESSARRAY_H
#include <iostream>
#include <memory>

/*
Алгоритм выполняется за O(M*N) квадратичная сложность
МЕТОД БЫСТРОГО ПОИСКА
для M исследуемых пар выполняется полный проход по массиву N
этот алгоритм медленный
*/

class ConnectednessArray {
public:
    explicit ConnectednessArray( int32_t count_elements );

    void Display( ) const;
    void Read( );

private:
    void Connected( int32_t index_p, int32_t index_q );

private:
    std::unique_ptr< int[], void ( * )( int * ) > array_;
    int32_t count_elem_;
};

#endif // CONNECTEDNESSARRAY_H
