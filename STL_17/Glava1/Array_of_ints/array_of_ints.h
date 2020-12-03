#ifndef ARRAY_OF_INTS_H
#define ARRAY_OF_INTS_H
#include "container_of_ints.h"

class array_of_ints : public container_of_ints {
 public:
  // array_of_ints( );

  int size( ) const override;
  int &at( int i ) override;
  const int &at( int i ) const override;

 private:
  static constexpr int N = 10;
  int data[ N ] = { };
};

#endif // ARRAY_OF_INTS_H
