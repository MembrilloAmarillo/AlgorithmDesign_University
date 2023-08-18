/****************************************/
/* Date  : 13/03/2023                   */
/* Author: Sascha Paez                  */
/****************************************/

// Arbol de expansion minimo
// Dado un grafo G = {Vertices, Aristas} conexo y ponderado con valores
// no negativos en sus aristas, se trata de calcular un subgrafo {Vertices, S},
// conexo de forma que la suma de los valores de sus aristas se minima (S es un
// conjunto minimo de aristas).
// Se demuestra que un subgrafo tal es un arbol. Este se denomina <<de expansion>>
// por unir todos los vertices y <<minimo>> por ser minimo el valor total de sus
// aristas. 
// Supondremos la existencia de un orden en Aristas inducido por la funcion de 
// ponderacion p.
// {i, j} <= {k, l} <=> p(i, j) <= p(k, l)