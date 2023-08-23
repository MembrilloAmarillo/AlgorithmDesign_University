#ifndef _ORDENACION_FUSION_H_
#define _ORDENACION_FUSION_H_

#include <cassert>

#include "Small_Vector.h"

template <typename T, size_t N> static void
ordenacion_insercion( Small_Vector<T, N>& V, size_t ini, size_t fin )
{
  assert( fin <= V.size() );
  
  size_t i = ini;

  while( i < fin )
    {
      T val = V[i];
      size_t j = i;

      while( ( j > 0 ) && ( val < V[j-1] ) )
	{
	  V[j] = V[j-1];
	  --j;
	}
      V[j] = val;
      ++i;
    }
}

template< typename T, size_t N> static void
fusion( Small_Vector<T, N>& V, size_t ini, size_t k, size_t fin )
{
  size_t n = fin - ini;

  size_t p = ini;
  size_t q = k;

  Small_Vector<T, N> w( V.size() );
  
  for( size_t i = 0; i < n; ++i )
    {
      if( ( p < k ) && ( ( q > fin ) || V[p] <= V[q] ) )
	{
	  w[i] = V[p];
	  ++p;
	}
      else
	{
	  w[i] = V[q];
	  ++q;
	}
    }
  for( size_t i = 0; i < n; ++i )
    {
      V[ini + i] = w[i];
    }
}

template< typename T, size_t N> static void
ordenacion_fusion( Small_Vector<T, N>& V, size_t ini, size_t fin )
{
  size_t n = fin - ini;
  if ( n <= 3 ) // n_0 -> Umbral, 3 es el optimo global
    {
      ordenacion_insercion( V, ini, fin );
    }
  else
    {
      size_t k = ini + (n >> 1);
      ordenacion_fusion( V, ini, k );
      ordenacion_fusion( V, k, fin );
      fusion( V, ini, k, fin );
    }
}
#endif
