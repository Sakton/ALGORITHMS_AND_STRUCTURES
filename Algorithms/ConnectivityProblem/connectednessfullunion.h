#ifndef CONNECTEDNESSFULLUNION_H
#define CONNECTEDNESSFULLUNION_H
#include <memory>

/*
Задание 1.16
*/

class ConnectedNessFullUnion
{
public:
    ConnectedNessFullUnion( int n );
    void Display( );
    void Read( );

    void Connectedness( int index_p, int index_q );

private:
    std::unique_ptr< int[] > trees_;
    std::unique_ptr< int[] > count_nodes_;
    int count_elements_;
};

#endif // CONNECTEDNESSFULLUNION_H
