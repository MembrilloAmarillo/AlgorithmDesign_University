#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdint>
#include <cassert>

template <typename T, size_t N> class Small_Vector {
public:
  Small_Vector() : v_end( 0 ) {}

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
    
  using iterator =  T*;
  using const_iterator = const T*;
    
  T* data() const { return smallvector; }
  std::vector<T> to_std_vec() const { return std::vector<T>( smallvector, smallvector + v_end ); }
    
  iterator begin() { return smallvector; }
  iterator end()   { return smallvector + v_end; }
    
  const_iterator cbegin() const { return smallvector; }
  const_iterator cend()   const { return smallvector + v_end; }
    
  T& operator [] ( size_t idx ) { return smallvector[idx]; }
  const T& operator [] ( size_t idx ) const { return smallvector[idx]; }
    
  void push_back( T el ) {
    assert( v_end < N );
    smallvector[v_end] = el; v_end++;
  }
  void pop_back() { assert( v_end > 0 ); v_end--; }
  T peek_back() { assert(v_end > 0); return smallvector[v_end]; }

  size_t size() const { return v_end; }
    
private:
  size_t v_end;
  T smallvector[N];
};

struct ConjuntoMoneda {
  uint32_t cantidad;
  uint32_t valor;
};

template <size_t N> void
OrdenaPorValor( Small_Vector<ConjuntoMoneda, N>& Monedas )
{
  for( size_t j = 1; j < Monedas.size(); ++j )
    {
      for( size_t i = 1; i < Monedas.size(); ++i )
	{
	  if( Monedas[i].valor < Monedas[i - 1].valor )
	    {
	      ConjuntoMoneda tmp = Monedas[i - 1];
	      Monedas[i - 1]     = Monedas[i];
	      Monedas[i]         = tmp;
	    }
	}
    }
}

template <size_t N> Small_Vector<ConjuntoMoneda, N>
CambioMonedas( Small_Vector<ConjuntoMoneda, N>& Monedas, size_t a_devolver )
{
  Small_Vector<ConjuntoMoneda, N> Solucion;
  OrdenaPorValor( Monedas );

  while( Monedas.size() > 0 && a_devolver > 0 )
    {
      ConjuntoMoneda prometedor = Monedas.peek_back();
      Monedas.pop_back();

      if( prometedor.valor * prometedor.cantidad <= a_devolver )
	{
	  Solucion.push_back( prometedor );
	  a_devolver -= prometedor.valor * prometedor.cantidad;
	}
      else if( ( (uint32_t)a_devolver / prometedor.valor ) > 0 )
	{
	  Solucion.push_back( { (uint32_t)a_devolver / prometedor.valor, prometedor.valor } );
	  a_devolver -= prometedor.valor * ( (uint32_t)a_devolver / prometedor.valor );
	}	
    }

  return Solucion;
}

int
main( void )
{
  Small_Vector<ConjuntoMoneda, 6> Monedas( {{5, 50}, {4, 20}, {7, 10}, {5, 5}, {3, 1}, {10, 2}} );
  CambioMonedas( Monedas, 89 );
  return 0;
}
