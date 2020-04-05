#ifndef __TRIFUSION_H_

#define __TRIFUSION_H_

// Inclusions des librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

//Ici on va pouvoir définir la taille du tableau
#define N 10
#define OMP_NUM_THREADS 2

//Fonction qui applique le triFusion sur un tableau et le trie
void triFusion_parallele (int tab[], int taille, int temp[], int nbre_threads);

void triFusion_fonct(int tab[], int taille, int temp[]);

void tri(int tab[], int taille, int temp[]);

#endif