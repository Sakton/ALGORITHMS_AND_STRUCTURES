#include "array_of_ints.h"

#include <stdexcept>

int array_of_ints::size( ) const { return N; }

const int& array_of_ints::at( int i ) const {
  if ( i < 0 && i >= N ) throw std::out_of_range( "OUT_OF_RANGE" );
  return data[ i ];
}

int& array_of_ints::at( int i ) { return const_cast< int& >( static_cast< const array_of_ints& >( *this ).at( i ) ); }
