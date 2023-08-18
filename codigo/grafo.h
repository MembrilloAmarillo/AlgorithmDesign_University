/****************************************/
/* Date  : 13/03/2023                   */
/* Author: Sascha Paez                  */
/****************************************/
   
#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>


struct celda
{
    size_t x;
    size_t y;
    void* valor;
};

struct Grafo {
    struct celda *aristas;
    size_t rows;
    size_t cols;

    void * GRAFO_VALOR_NULO;
};

void Grafo_Iniciar(struct Grafo* G, size_t n, size_t m);

void Grafo_Destruir(struct Grafo* G);

void Grafo_Insertar(struct Grafo* G, size_t i, size_t j, void *val);

void Grafo_Eliminar(struct Grafo* G, size_t i, size_t j);

void* Grafo_Valor(struct Grafo* G, size_t i, size_t j);

struct celda* Grafo_Busca_Celda(struct Grafo* G, void *valor);

#endif