#include <iostream>
//#include <

template < typename Item >
void quickSortrecursive( Item a[], int l, int r );

template < typename Item >
int partition( Item a[], int l, int r );

// template<typename BidirectionalIterator>

int main( ) {
  // int arr[] { 8, 2, 6, 9, 1, 3, 5, 4, 7, 0 };
  int arr[] { 8, 2, 6, 9, 1, 3, 5, 4, 7, 0 };
  /*std::cout <<  partition( arr, 0, 8 ); */
  quickSortrecursive( arr, 0, 9 );

  for ( auto x : arr ) std::cout << x << " ";
}

template < typename Item >
void quickSortrecursive( Item a[], int l, int r ) {
  if ( r <= l ) return;
  int idx = partition( a, l, r );
  quickSortrecursive( a, l, idx - 1 );
  quickSortrecursive( a, idx + 1, r );
}

// TODO ТУТ РАЗОБРАТЬ СНОВА!!!
template < typename Item >
int partition( Item a[], int l, int r ) {
  int i = l;
  int j = r - 1;
  int pivot = a[ r ];
  while ( i < j ) {
    while ( i <= r && a[ i ] < pivot ) ++i;
    while ( j >= 0 && pivot < a[ j ] ) --j;
    if ( i < j ) std::swap( a[ i ], a[ j ] );
  }
  std::swap( a[ i ], a[ r ] );
  return i;
}
