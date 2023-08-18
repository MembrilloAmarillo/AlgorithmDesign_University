#ifndef _PRIM_H_
#define _PRIM_H_

#include <cstdint>

#include "Small_Vector.h"

template <size_t N> Small_Vector<size_t, N>
prim( const Small_Vector<Small_Vector<uint32_t, N>, N>& Pesos, size_t n )
{
  Small_Vector<uint32_t, N> Distancias(N);
  Small_Vector<size_t, N>   Cercanos(N);
  Small_Vector<size_t, N>   Candidatos;
  Small_Vector<size_t, N>   Solucion(N);
  
  for( size_t i = 1; i < n; ++i )
    {
      Candidatos.push_back( i );
      Cercanos[i] = 1;
      Distancias[i] = Pesos[1][j];
    }

  while( Candidatos.size() != 0 )
    {
      size_t k = selecciona_vertice( Candidatos, Distancias );
      Candidatos.erase( k );
      Solucion[ Cercanos[k] ] = k;

      for( int j = 0; j < Candidatos.size(); ++j )
	{
	  if ( Pesos[k][j] < Distancias[j] )
	    {
	      Cercanos[j] = k;
	      Distancias[j] = Pesos[k][j];
	    }
	}
    }
}
#endif // _PRIM_H_
