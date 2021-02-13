#include "listarray.h"

ListArray::ListArray( ) : size { 0 } {}

bool ListArray::isEmpty( ) const { return size == 0; }

int ListArray::getLenth( ) const { return size; }

bool ListArray::insert( int index, ListItemType newItem ) {
  if ( 1 <= index && index <= size + 1 && size < MAX_LIST ) {
    for ( int pos = size - 1; pos >= index; --pos ) {
      items[ translate( pos + 1 ) ] = items[ translate( pos ) ];
    }
    items[ translate( index ) ] = newItem;
    ++size;
    return true;
  }
  return false;
}

bool ListArray::remove( int index ) {
  if ( 1 <= index && index <= size ) {
    for ( int pos = index + 1; pos <= size; ++pos ) {
      items[ translate( pos - 1 ) ] = items[ translate( pos ) ];
    }
    --size;
    return true;
  }
  return false;
}

ListItemType ListArray::retrieve( int index ) {
  ListItemType ret { -1 };
  if ( 1 <= index && index <= size ) {
    ret = items[ translate( index ) ];
    remove( index );
  }
  return ret;
}

int ListArray::translate( int index ) const { return index - 1; }
