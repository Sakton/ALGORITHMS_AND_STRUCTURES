#ifndef LISTARRAY_H
#define LISTARRAY_H

//класс массив-список

const int MAX_LIST = 100;
typedef int ListItemType;

class ListArray {
 public:
  ListArray( );

  bool isEmpty( ) const;
  //Определяет пуст ли массив-список
  //Постусловие: если список пуст, возвращает TRUE, иначе FALSE
  int getLenth( ) const;
  //возвращает текущее количество элементов
  bool insert( int index, ListItemType newItem );
  // index - позиция куда надо вставить элемент
  //если втавка успешна возврат TRUE, иначе FALSE
  bool remove( int index );
  // удаляет элемент на позиции index
  //если удаление успешно возврат TRUE, иначе FALSE
  ListItemType retrieve( int index );
  // Извлекает из списка элемент и возвращает его копию, и удалает из списка

 private:
  ListItemType items[ MAX_LIST ];
  int size;
  int translate( int index ) const;
};

#endif // LISTARRAY_H
