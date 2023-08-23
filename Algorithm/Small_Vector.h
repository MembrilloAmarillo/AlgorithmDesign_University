#ifndef _SMALL_VECTOR_H_
#define _SMALL_VECTOR_H_

#include <vector>
#include <cstring>
#include <cstdint>
#include <cassert>

template <typename T, size_t N> class Small_Vector {
public:
  Small_Vector( size_t end = 0 ) : v_end( end ) {}

  Small_Vector( std::initializer_list<T> IL ) : v_end( N )
  {
    for( size_t i = 0; i < N; ++i )
      {
	smallvector[i] = *( IL.begin() + i );
      }
  }

  Small_Vector( const Small_Vector<T, N>& V ) : 
    v_end  ( V.v_end )
  {
    memcpy( smallvector, V.smallvector, v_end );
  }
    
  typedef T* iterator;
  typedef T const* const_iterator;
    
  T* data() const { return smallvector; }
  std::vector<T> to_std_vec() const { return std::vector<T>( smallvector, smallvector + v_end ); }
    
  iterator begin() { return smallvector; }
  iterator end()   { return smallvector + v_end; }
    
  const_iterator cbegin() const { return smallvector; }
  const_iterator cend()   const { return smallvector + v_end; }
    
  T& operator [] ( size_t idx ) { return smallvector[idx]; }
  const T& operator [] ( size_t idx ) const { return smallvector[idx]; }
    
  void push_back( T el )
  {
    assert( v_end < N );
    smallvector[v_end] = el; v_end++;
  }

  void erase( size_t idx )
  {
    assert( idx >= 0 && idx < v_end );

    for( size_t i = idx; i < v_end - 1; ++i )
      {
	smallvector[i] = smallvector[i+1];
      }

    --v_end;
  }

  void pop_back() { assert( v_end > 0 ); v_end--; }
  T peek_back() { assert(v_end > 0); return smallvector[v_end]; }

  size_t size() const { return v_end; }
    
private:
  size_t v_end;
  T smallvector[N];
};

#endif // _SMALL_VECTOR_H_
