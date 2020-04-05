/* Inclusion des librairies */
#include "triFusion.h"

int main (int argc, char** argv) {
    int *tab = malloc(sizeof(int) * N);
    int *temp = malloc(sizeof(int) * N);

    printf("Tableau initial non trié: ");

    srand(time(NULL));
    for (int i = 0; i<N; i++) {
        tab[i] = rand() % N;
        printf("%3d", tab[i]);
    }
   
    triFusion_parallele(tab, N, temp, OMP_NUM_THREADS);

    printf("\n\nTableau trié: ");
    for (int i=0; i<N; i++) {
        printf("%3d", tab[i]);
    }
    printf("\n");
    return 0;
}
