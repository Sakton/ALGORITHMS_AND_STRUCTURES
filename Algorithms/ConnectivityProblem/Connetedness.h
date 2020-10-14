#pragma once
#include <vector>

//TODO надо переработать до поной ясности

/*
Тестовый набор: {{3,4},{4,9},{8,0},{2,3},{5,6},{2,9},{5,9},{7,3},{4,8},{5,6},{0,2},{6,1}}
std::vector<std::pair<int, int>> vbecPair = {{3,4},{4,9},{8,0},{2,3},{5,6},{2,9},{5,9},{7,3},{4,8},{5,6},{0,2},{6,1}};
*/

class Connetedness {
    using VecPair = std::vector< std::pair< int, int > >;

public:
    explicit Connetedness( int countElements = 0 );

    void addInCin( );
    void connectPairs( VecPair vp );
    void printResult( );

private:
    void resize( int count );
    void vievsTests( int & p, int & q );
    //главный метод
    void connected( int p, int q );
    void connectedTree( int p, int q );
    void connectedTreeVzv( int p, int q );
    void connectecTreeVzvDiv2( int p, int q );

private:
    using Vec = std::vector< int >;
    Vec connectedness;
    Vec sizesTree;
};
