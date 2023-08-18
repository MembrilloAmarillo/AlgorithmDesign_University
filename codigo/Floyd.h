#ifndef _FLOYD_H_
#define _FLOYD_H_

#include "Small_Vector.h"

#define min( a, b ) ( a < b ? a : b )

template <size_t N> Small_Vector<Small_Vector<uint32_t, N>>
Floyd( const Small_Vector<Small_Vector<uint32_t, N>, N>& Pesos,
       Small_Vector<size_t, N>& Caminos )
{
  Small_Vector<uint32_t, N> Distancias( Pesos );

  for( size_t i = 0; i < Distancias.size(); ++i )
    {
      Distancias[i][i] = 0;
    }

  for( size_t i = 0; i < Caminos.size(); ++i )
    {
      for( size_t j = 0; j < Caminos.size(); ++j )
	{
	  Caminos[i][j] = i;
	  Caminos[j][i] = j;
	}
    }
  
  for( size_t k = 0; k < Distancias.size(); ++k )
    {
      for( size_t i = 0; i < Distancias.size(); ++i )
	{
	  for( size_t j = 0; j < Distancias.size(); ++j )
	    {
	      #if 0

	      Distancias[i][j] = min( Distancias[i][j],
				      Distancias[i][k] + Distancias[k][j] );
	      #else

	      if( Distancias[i][j] > Distancias[i][k] + Distancias[k][j] )
		{
		  Caminos[i][j] = k;
		  Distancias[i][j] = Distancias[i][k] + Distancias[k][j];
		}
	      
	      #endif
	    }
	}
    }
}

#endif _FLOYD_H_
