#ifndef __PRINTMATRICE_H_

#define __PRINTMATRICE_H_

//Inclusion des librairies
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include "mpi.h"

//Le N correspond à la taille de la matrice carrée, ici c'est 4 pour que la matrice soit assez intéressant mais sans être trop complexe à vérifier de tête
#define N 4

//Cette fonction permet d'afficher une matrice carrée de taille N avec une chaîne de caractères qui la précéde
void printMatrice(char *prompt, int a[N][N]);

#endif