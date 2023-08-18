#ifndef _WARSHALL_H_
#define _WARSHALL_H_

#include "Small_Vector.h"

template <size_t N> Small_Vector<Small_Vector<bool, N>, N>
Warshall( const Small_Vector<Small_Vector<bool, N>, N>& Aristas )
{
  Small_Vector<bool, N> Adyacencia(Aristas.size());

  for( size_t i = 0; i < Aristas.size(); ++i )
    {
      Adyacencia[i][i] = true;
    }

  for( size_t k = 0; k < Aristas.size(); ++k )
    {
      for( size_t i = 0; i < Aristas.size(); ++i )
	{
	  for( size_t j = 0; j < Aristas.size(); ++j )
	    {
	      Adyacencia[i][j] = Aristas[i][j] || ( Aristas[i][k] && Aristas[k][j] );
	    }
	}
    }

  return Adyacencia;
}

#endif // _WARSHALL_H_
