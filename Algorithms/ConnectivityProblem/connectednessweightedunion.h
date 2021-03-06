#ifndef CONNECTEDNESSWEIGHTEDUNION_H
#define CONNECTEDNESSWEIGHTEDUNION_H
#include <memory>

/*
Алгоритм выполняется за O(M*log(N)) линейная сложность
Модификация алгоритма методом быстрого обьединения
ПРОБЛЕМА: при последовательном связывании 1-2, 2-3, 3-4 и тд.
получим дерево из одной линии, тем самым получим ситуацию когда при М
вволимых парах, надо пройти по 1,2,3....N-1 указателям.
тогда среднее значение N(N-1)/2N = (N-1)/2
Если же, вводимые пары уже имеют связь, то при их проверке
надо пройти для каждой до корня дерева, тогда поиск для таких пар > чем MN/2
Эта проблема может наращивать одно дерево, и создавая новый корень при связывании
(как бы увеличивая дерево)

РЕШЕНИЕ:
Чтобы убрать рост дерева, необходимо сохраняя корень большего дерева как общий,
присоединять к нему меньшее дерево, пусть дерево растет в ширь, увеличивая количество веток
Для этого потребуется дополнительный массив отслеживающий количество узлов в присоединяемом дереве
на основании количества узлов принимается решение о связывании меньшего дерева с большим
тем самым чтобы пройти по указателям в дереве с 2^n узлами нужно n переходов.
при слиянии деревьев с 2^n узлами, количество переходов увеличивается на 1 до ( n + 1 )
 */

class ConnectednessWeightedUnion {
public:
    ConnectednessWeightedUnion( int n );
    void Display( );
    void Read( );

    void Connectedness( int index_p, int index_q );

private:
    std::unique_ptr< int[] > trees_;
    std::unique_ptr< int[] > count_nodes_;
    int count_elements_;
};

#endif // CONNECTEDNESSWEIGHTEDUNION_H
