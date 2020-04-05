/* Inclusion des librairies */
#include "triFusion.h"

int main (int argc, char** argv) {
    //On initialise le tableau qu'on cherche à trier, et un tableau temporaire utilisé pour pouvoir appliquer le tri fusion
    int *tab = malloc(sizeof(int) * N);
    int *temp = malloc(sizeof(int) * N);

    //Affichage du tableau non trié
    printf("Tableau initial non trié: ");

    srand(time(NULL));
    for (int i = 0; i<N; i++) {
        tab[i] = rand() % N;
        printf("%3d", tab[i]);
    }
   
    //On applique ensuite le tri fusion pour pouvoir trié le tableau avec en paramètre sa taille et le nombre de threads accordés
    triFusion_parallele(tab, N, temp, OMP_NUM_THREADS);

    //Et enfin on affiche de nouveau le tableau, mais cette fois-ci trié par l'algorithme
    printf("\n\nTableau trié: ");
    for (int i=0; i<N; i++) {
        printf("%3d", tab[i]);
    }
    printf("\n");
    
    return 0;
}
