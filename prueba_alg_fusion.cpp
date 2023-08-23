#include <iostream>

#include "Ordenacion_Fusion.h"

int
main( void )
{
  Small_Vector< int, 7 > A = { 3, 5, 2, 6, 1, 10, 4 };
  ordenacion_fusion( A, 0, A.size() );

  for( size_t x = 0; x < A.size(); ++x )
    {
      std::cout << A[x] << " ,";
    }
  std::cout << "\n";
  
  return 0;
}
