#include <iostream>

/*
Считаем что функция сама знает как перемещать элементы
Если элементов нет, то и перемещать нечего - базовый случай, выход
Тогда сперва на вспомогательный i = 6 - j - k  ( если пронумеровать метса 1,2,3 в сумме они 6 )

Чтобы переложить нижний елемент на целевой надо сперва n - 1 элементы переложить на вспомогательный
затем перекладываем нужный, и с вспомогательного на целевой те n-1 элемент
*/

void Hanoi( int nElem, int j, int k ) {
  if ( nElem == 0 ) {
    // std::cout << "1 with " << j << " to " << k << std::endl;
    return;
  }
  int tmp = 6 - j - k;  //временный столбец
  Hanoi( nElem - 1, j, tmp );
  std::cout << nElem << " with " << j << " to " << k << std::endl;
  Hanoi( nElem - 1, tmp, k );
}

//или
void Hanoi1( int nElem, int j, int k ) {
  if ( nElem == 0 ) {
    std::cout << "1 with " << j << " to " << k << std::endl;
  }
  int tmp = 6 - j - k;  //временный столбец
  Hanoi( nElem - 1, j, tmp );
  std::cout << nElem << " with " << j << " to " << k << std::endl;
  Hanoi( nElem - 1, tmp, k );
}

int main( ) { Hanoi1( 3, 1, 3 ); }
