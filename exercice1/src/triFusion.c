#include "triFusion.h"

//Cette fonction va trier un tableau en appliquant la méthode du tri fusion en parallele,
//c'est à dire qu'elle va partager en de nombreux sous-tableaux le tableau de base et va appeler récursivement la fonction tri
//pour pouvoir finalement laisser chaque tâche s'occuper d'un sous-tableau et reconstruire le tableau une fois trié
void triFusion_parallele (int tab[], int taille, int temp[], int nbre_threads) {
    if (nbre_threads == 1) {
        triFusion_fonct(tab, taille, temp);
    }
    else {
        #pragma omp parallel
        {
            #pragma omp single nowait
            {
                #pragma omp task
                {
                    triFusion_parallele(tab, taille/2, temp, nbre_threads/2);
                }
                #pragma omp task
                {
                    triFusion_parallele(tab + taille/2, taille - taille/2, temp + taille/2, nbre_threads - nbre_threads/2);
                }
                #pragma omp taskwait
                {
                    tri(tab, taille, temp);
                }
            }
        }
    }
}


//Divise le tableau de manière récursive en divisant la taille par 2 à chaque fois jusqu'à atteindre un sous-tableau d'une taille de 2 maximum
void triFusion_fonct(int tab[], int taille, int temp[]) {
    if (taille <= 2) {
        tri(tab, taille, temp);
        return;
    }
    triFusion_fonct(tab, taille/2, temp);
    triFusion_fonct(tab + taille/2, taille - taille/2, temp);
    tri(tab, taille, temp);
}

//Tri un sous-tableau et le range dans l'ordre croissant
void tri(int tab[], int taille, int temp[]) {
    int debut = 0;
    int fin = taille/2;
    int compteur = 0;
    while (debut < taille/2 && fin < taille) {
        if (tab[debut] < tab[fin]) {
            temp[compteur] = tab[debut];
            debut++;
        } else {
            temp[compteur] = tab[fin];
            fin++;
        }
        compteur++;
    }
    while (debut < taille/2) {
        temp[compteur] = tab[debut];
        debut++;
        compteur++;
    }
    while (fin < taille) {
        temp[compteur] = tab[fin];
        fin++;
        compteur++;
    }
    for (int i = 0; i<taille; i++) {
        tab[i] = temp[i];
    }
}