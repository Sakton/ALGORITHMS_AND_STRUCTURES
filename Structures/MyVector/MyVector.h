#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <memory>
#include <stdexcept>

namespace sktn {

template < typename T >
class MyVector;

template < typename T >
class MyVectorIterator {
  using type_name = T;
  using reference = type_name&;
  using const_reference = const type_name&;
  using pointer = type_name*;
  using pointer_on_const = const type_name*;

  friend class MyVector< T >;
  MyVectorIterator( pointer p = nullptr ) : p_ { p } {}

 public:
  MyVectorIterator( const MyVectorIterator& oth ) : p_ { oth.p_ } {}
  reference operator*( ) { return *p_; }
  const_reference operator*( ) const { return *p_; }
  pointer operator->( ) { return p_; }
  pointer_on_const operator->( ) const { return p_; }
  pointer operator++( ) { return ++p_; }
  pointer_on_const operator++( ) const { return ++p_; }
  pointer operator++( int ) {
    pointer t = p_;
    ++p_;
    return t;
  }
  pointer_on_const operator++( int ) const {
    pointer t = p_;
    ++p_;
    return t;
  }
  pointer operator--( ) { p_--; }
  pointer_on_const operator--( ) const { p_--; }

  pointer operator--( int ) {
    pointer t = p_;
    --p_;
    return t;
  }

  pointer_on_const operator--( int ) const {
    pointer t = p_;
    --p_;
    return t;
  }

  bool operator==( const MyVectorIterator& othI ) const { return othI.p_ == p_; }
  bool operator!=( const MyVectorIterator& othI ) const { return othI.p_ != p_; }

 private:
  pointer p_;
};

template < typename T >
class MyReverseIterator {
  using type_name = T;
  using reference = type_name&;
  using const_reference = const type_name&;
  using pointer = type_name*;
  using pointer_on_const = const type_name*;

  MyReverseIterator( pointer p );

 public:
  // FIXME reverse iterator
 private:
  pointer p_;
};

template < typename T /*, typename Iter*/ >
class MyVector {
 public:
  // type definition
  using type_name = T;
  using reference = type_name&;
  using const_reference = const type_name&;
  using iterator = MyVectorIterator< T >;
  using const_iterator = const MyVectorIterator< T >;
  using size_type = std::size_t;

  MyVector( );
  MyVector( size_type n );
  MyVector( size_type n, type_name elem );
  MyVector( const std::initializer_list< type_name >& initList );
  template < typename OtherIterartor >
  MyVector( const OtherIterartor cbeg, const OtherIterartor cend );
  MyVector( const MyVector& oth );
  MyVector( MyVector&& oth );

  MyVector& operator=( const MyVector& oth );
  MyVector& operator=( MyVector&& oth );

  // size
  bool empty( ) const;
  size_type size( ) const;
  size_type max_size( ) const;
  size_type capacity( ) const;

  // iteration
  iterator begin( );
  const_iterator cbegin( ) const;
  iterator end( );
  const_iterator cend( ) const;

  // modify
  void swap( );

 private:
  size_type size_;
  size_type max_size_;
  size_type capacity_;
  std::unique_ptr< T[] > data_;
};

template < typename T >
MyVector< T >::MyVector( ) : size_ { 0 }, max_size_ { 0 }, capacity_ { 0 } {}

template < typename T >
MyVector< T >::MyVector( size_type n ) : size_ { n }, max_size_ { n }, capacity_ { n }, data_ { new T[ n ] { T( ) } } {}

template < typename T >
typename MyVector< T >::iterator MyVector< T >::begin( ) {
  return iterator( data_.get( ) );
}

template < typename T >
typename MyVector< T >::const_iterator MyVector< T >::cbegin( ) const {
  return const_iterator( data_.get( ) );
}

template < typename T >
typename MyVector< T >::iterator MyVector< T >::end( ) {
  return iterator( data_.get( ) + size_ );
}

template < typename T >
typename MyVector< T >::const_iterator MyVector< T >::cend( ) const {
  return const_iterator( data_.get( ) + size_ );
}

template < typename T >
template < typename OtherIterartor >
MyVector< T >::MyVector( const OtherIterartor cbeg, const OtherIterartor cend ) : size_ { 0 }, max_size_ { 0 }, capacity_ { 0 } {
  size_type n = std::distance( cbeg, cend );
  if ( n < 0 ) throw std::runtime_error( "N < 0 ERROR!" );
  size_ = n;
  max_size_ = n;
  capacity_ = n;
  data_.reset( new T[ n ] { T( ) } );
  MyVector< T >::iterator i = this->begin( );
  for ( auto it = cbeg; it != cend; ++it ) {
    *i++ = *it;
  }
}

}  // namespace sktn

#endif  // MYVECTOR_H
