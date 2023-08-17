#include <iostream>
#include <vector>
#include <algorithm>

float 
pesos( const std::vector<bool>& S, const std::vector<float>& Pesos )
{
    float peso = 0.0f;
    for( uint32_t i = 0; i < S.size(); ++i )
    {
        if( S[i] )
        {
            peso += Pesos[i];
        }
    }
    return peso;
}

float
valor( const std::vector<bool>& M, const std::vector<float>& Valores )
{
    float valor = 0.0f;
    for( uint32_t i = 0; i < M.size(); ++i )
    {
        if( M[i] )
        {
            valor += Valores[i];
        }
    }
    return valor;
}

float
cota(
    const std::vector<float>& Valores,
    const std::vector<float>& Pesos,
    uint32_t n, uint32_t cap,
    const std::vector<bool>& S,
    uint32_t Objeto )
{
    float m = valor( S, Valores );
    float peso_total = pesos( S, Pesos );
    while( Objeto <= n && peso_total + Pesos[Objeto] <= cap )
    {
        m = m + Valores[Objeto];
        peso_total = peso_total + Pesos[Objeto];
        ++Objeto;
    }
    if ( Objeto <= n && peso_total < cap )
    {
        m = m + ( Valores[Objeto] * ( cap - peso_total ) / Pesos[Objeto] );
    }

    return m;
}

std::vector<bool>
mdr_aux(
    std::vector<float>& Valores,
    std::vector<float>& Pesos,
    uint32_t n, uint32_t cap,
    std::vector<bool>& S,
    uint32_t Objeto,
    std::vector<bool>& M )
{
    if( Pesos[Objeto] + pesos(S, Pesos) <= cap )
    {
        S[Objeto] = true;
        if ( Objeto == n )
        {
            M = S;
        }
        else
        {
            M = mdr_aux( Valores, Pesos, n, cap, S, Objeto + 1, M );
        }
    }
    S[Objeto] = false;
    if ( cota(Valores, Pesos, n, cap, S, Objeto + 1 ) > valor(M, Valores) )
    {
        if ( Objeto == n )
        {
            M = S;
        }
        else
        {
            M = mdr_aux( Valores, Pesos, n, cap, S, Objeto + 1, M );
        }
    }
    return M;
}

std::vector<bool>
mdr( std::vector<float>& Valores, std::vector<float>& Pesos, uint32_t cap )
{
    std::vector<bool> solucion( Valores.size(), false );
    auto M = solucion;

    solucion = mdr_aux( Valores, Pesos, Valores.size() - 1, cap, solucion, 0, M );

    return solucion;
}

int
main( void )
{
    std::vector<float> Valores = { 10.0f, 60.0f, 10.0f, 100.0f };
    std::vector<float> Pesos   = { 50.0f, 60.0f, 60.0f, 100.0f };
    uint32_t cap = 180;

    auto M = mdr( Valores, Pesos, cap );

    for_each(M.begin(), M.end(), [&](auto x){ std::cout << x << " "; } );
    return 0;
}