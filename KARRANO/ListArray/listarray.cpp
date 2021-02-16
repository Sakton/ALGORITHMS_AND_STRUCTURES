#include "listarray.h"

ListArray::ListArray( ) : size { 0 } {}

bool ListArray::isEmpty( ) const { return size == 0; }

int ListArray::getLenth( ) const { return size; }

bool ListArray::insert( int index, ListItemType newItem ) {
  //  if ( 1 <= index && index <= size + 1 && size < MAX_LIST ) {
  //    for ( int pos = size - 1; pos >= index; --pos ) {
  //      items[ translate( pos + 1 ) ] = items[ translate( pos ) ];
  //    }
  //    items[ translate( index ) ] = newItem;
  //    ++size;
  //    return true;
  //  }
  //  return false;
  if ( size >= MAX_LIST ) throw ListArrayException( "ListArrayException: liatsarray is full" );
  if ( index >= 1 && index <= size + 1 ) {
    for ( int pos = size - 1; pos >= index; --pos ) {
      items[ translate( pos + 1 ) ] = items[ translate( pos ) ];
    }
    items[ translate( index ) ] = newItem;
    ++size;
    return true;
  } else {
    throw ListArrayIndexOutOfRangeException( "ListArrayIndexOutOfRangeException: insert bad index" );
  }
}

bool ListArray::remove( int index ) {
  if ( 1 <= index && index <= size ) {
    for ( int pos = index + 1; pos <= size; ++pos ) {
      items[ translate( pos - 1 ) ] = items[ translate( pos ) ];
    }
    --size;
    return true;
  } else {
    throw ListArrayIndexOutOfRangeException( "ListArrayIndexOutOfRangeException: remove bad index" );
  }
}

ListItemType ListArray::retrieve( int index ) {
  if ( 1 <= index && index <= size ) {
    ListItemType ret = items[ translate( index ) ];
    remove( index );
    return ret;
  } else {
    throw ListArrayIndexOutOfRangeException( "ListArrayIndexOutOfRangeException: remove bad index" );
  }
}

int ListArray::translate( int index ) const { return index - 1; }

ListArrayIndexOutOfRangeException::ListArrayIndexOutOfRangeException( const std::string &message )
    : std::out_of_range( message.c_str( ) ) {}

ListArrayException::ListArrayException( const std::string &message ) : std::exception( message.c_str( ) ) {}
