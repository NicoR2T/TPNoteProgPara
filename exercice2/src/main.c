#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *matriceA = malloc(sizeof(int) * size * size);
    int *vecteurB = malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriceA[i*size + j] = rand() % 10;
        }
    }

    for (int i = 0; i < size; i++) {
        vecteurB[i] = rand() % 10;
    }

    int sendbuf[size];
    int recvbuf;

    for (int i=0; i<size; i++)
        sendbuf[i] = matriceA[rank + size*i]*vecteurB[rank];

    printf("Proc %d: ", rank);
    for (int i=0; i<size; i++) printf("%d ", sendbuf[i]);
    printf("\n");

    int recvcounts[size];
    for (int i=0; i<size; i++)
        recvcounts[i] = 1;

    MPI_Reduce_scatter(sendbuf, &recvbuf, recvcounts, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    printf("Proc %d: %d\n", rank, recvbuf);

    MPI_Finalize();

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

    //Vérification:
    int sum;

    for (int i = 0; i < size; i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            sum += matriceA[i*size+j]*vecteurB[j];
        }
        printf("Valeur cherchée du proc %d: %d\n", i, sum);
    }

    return 0;
}