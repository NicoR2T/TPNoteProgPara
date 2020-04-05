#ifndef __TRIFUSION_H_

#define __TRIFUSION_H_

// Inclusions des librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

//Ici on va pouvoir définir la taille du tableau et le nombre de threads
#define N 10
#define OMP_NUM_THREADS 2

//Fonction qui applique le triFusion sur un tableau et le trie en utilisant un nombre de tâches dépendant de la valeur de OMP_NUM_THREADS
void triFusion_parallele (int tab[], int taille, int temp[], int nbre_threads);

//Réalise le tri fusion pour une tâche en particulier
void triFusion_fonct(int tab[], int taille, int temp[]);

//Tri une sous-partie du tableau final
void tri(int tab[], int taille, int temp[]);

#endif