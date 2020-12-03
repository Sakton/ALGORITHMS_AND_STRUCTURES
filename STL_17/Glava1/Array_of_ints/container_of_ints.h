#ifndef CONTAINER_OF_INTS_H
#define CONTAINER_OF_INTS_H

class container_of_ints {
 public:
  virtual ~container_of_ints( ) {}
  virtual int size( ) const = 0;
  virtual const int& at( int i ) const = 0;
  virtual int& at( int i ) = 0;
};

#endif  // CONTAINER_OF_INTS_H
