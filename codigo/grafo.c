#include "grafo.h"

void Grafo_Iniciar(struct Grafo* G, size_t n, size_t m)
{
    G = (struct Grafo*)VirtualAlloc(NULL, sizeof(struct Grafo), 
        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    
    if (G == NULL)
    {
        fprintf(stderr, "[ERROR] Fallo al inicializar grafo\n");
        exit(1);
    }
    G->aristas = (struct celda*)VirtualAlloc(NULL, n * m * sizeof(struct celda), 
                MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (G->aristas == NULL)
    {
        fprintf(stderr, "[ERROR] Fallo al inicializar aristas en grafo\n");
        exit(1);
    }

    G->rows = n;
    G->cols = m;
}

void Grafo_Insertar(struct Grafo* G, size_t i, size_t j, void *valor)
{
    assert((i >= 0) && (i < G->rows));
    assert((j >= 0) && (j < G->cols));

}