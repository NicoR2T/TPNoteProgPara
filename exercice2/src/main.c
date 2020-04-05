//Inclusion des librairies:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    //On initalise MPI à l'aide des valeurs entré lors du lancement du programme
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Je déclare la matrice et le vecteur pour lesquels on cherche le produit
    int *matriceA = malloc(sizeof(int) * size * size);
    int *vecteurB = malloc(sizeof(int) * size);

    //Je les initialise ensuite avec des valeurs aléatoires entre 0 et 10
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriceA[i*size + j] = rand() % 10;
        }
    }

    for (int i = 0; i < size; i++) {
        vecteurB[i] = rand() % 10;
    }

    //Je déclare les variables que j'utiliserai plus tard pour la fonction MPI_Reduce_scatter
    int sendbuf[size];
    int recvbuf;

    //Sendbuf va calculer l'ensemble des valeurs cherchées lors du produit de chaque valeur de la matrice avec les valeurs du vecteur, dans le but d'obtenir le vecteur résultant
    for (int i=0; i<size; i++)
        sendbuf[i] = matriceA[rank + size*i]*vecteurB[rank];

    //On affiche le calcul précédent pour vérifier qu'il est le bon, puis la fonction Reduce scatter fera la somme en respectant le calcul d'un produit matrice vecteur
    printf("Proc %d: ", rank);
    for (int i=0; i<size; i++) printf("%d ", sendbuf[i]);
    printf("\n");

    //Cette liste remplit de 1 permet d'expliquer à la fonction Reduce scatter que nous avons toutes les valeurs prévues
    int recvcounts[size];
    for (int i=0; i<size; i++)
        recvcounts[i] = 1;

    //On applique enfin la fonction avec toutes les valeurs initialisées précédemment, qui va calculer toutes les valeurs du vecteur résultant et les stocker dans c
    MPI_Reduce_scatter(sendbuf, &recvbuf, recvcounts, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    //On affiche enfin le résultat final, et on compare avec le résultat attendu
    printf("Proc %d: %d\n", rank, recvbuf);

    //Ici j'affiche la matrice et le vecteur, ainsi que le résultat attendu pour vérifier si chaque processeur renvoit la bonne valeur
    if (rank==0) {
        printf("Matrice A initiale:\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%2d", matriceA[i*size + j]);
            }
            printf("\n");
        }

        printf("\nVecteur B initial:");
        for (int i = 0; i < size; i++) {
            printf("%2d", vecteurB[i]);
        }
        printf("\n");

        int sum;

        for (int i = 0; i < size; i++) {
            sum = 0;
            for (int j = 0; j < size; j++) {
                sum += matriceA[i*size+j]*vecteurB[j];
            }
            printf("Valeur cherchée du proc %d: %d\n", i, sum);
        }
    }

    MPI_Finalize();

    return 0;
}