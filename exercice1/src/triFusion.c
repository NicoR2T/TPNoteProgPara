#include "triFusion.h"

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

void triFusion_fonct(int tab[], int taille, int temp[]) {
    if (taille <= 2) {
        tri(tab, taille, temp);
        return;
    }
    triFusion_fonct(tab, taille/2, temp);
    triFusion_fonct(tab + taille/2, taille - taille/2, temp);
    tri(tab, taille, temp);
}

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