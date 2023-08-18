#include <cstdio>

#include "Small_Vector.h"

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
