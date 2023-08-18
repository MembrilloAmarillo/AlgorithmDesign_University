#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#define UINT32_MAX ( 1 << 32 ) - 1

#include "Small_Vector.h"

template <size_t N> size_t
selecciona_vertice( const Small_Vector<size_t, N>& Candidatos,
		    const Small_Vector<uint32_t, N>& Distancias )
{
  uint32_t v = UINT32_MAX;
  size_t k = 0;

  for( size_t i = 0; i < Candidatos.size(); ++i )
    {
      if( Distancias[i] < v )
	{
	  v = Distancias[i];
	  k = i;
	}
    }

  return k;
}


template <size_t N> Small_Vector<uint32_t, N>
Dijkstra( const Small_vector<Small_Vector<uint32_t, N>, N>& Pesos, size_t n, size_t origen, Small_Vector<size_t, N>& Camino )
{
  Small_Vector<uint32_t, N> Distancias;
  Small_Vector<size_t, N>   Candidatos;
  Small_Vector<size_t, N>   Camino;

  for( int i = 0; i < n; ++i )
    {
      Candidatos.push_back( i );
      Camino[i] = origen;
      Distancias[i] = Pesos[origen][i];
    }

  Candidatos.erase( origen );

  while( Candidatos.size() > 0 )
    {
      size_t k = selecciona_vertice( Candidatos, Distancias );
      Candidatos.erase( k );
      for( size_t i = 0; i < Candidatos.size(); ++i )
	{
	  if( Distancias[k] + Pesos[k][j] < Pesos[i][j] )
	    {
	      Distancias[j] = Distancias[k] + Pesos[k][j];
	      Camino[j] = k;
	    }
	}
    }
  return Distancias;
}

#endif // _DIJKSTRA_H_
