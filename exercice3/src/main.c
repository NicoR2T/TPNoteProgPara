#include "printMatrice.h"

int main(int argc, char *argv[]) {
    int i, j, rank, size, sum = 0;
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int aa[N],cc[N];

    // J'ai décidé d'initialiser les matrices a et b avec des valeurs alétoires entre 0 et 10
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i][j] = rand() % 10;
        }
    }

    //Initialisation de MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //Répartis les lignes de la première matrice aux différents processus
    MPI_Scatter(a, N*N/size, MPI_INT, aa, N*N/size, MPI_INT,0,MPI_COMM_WORLD);

    //Transmet la seconde matrice à tous les processus
    MPI_Bcast(b, N*N, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

    //Applique la multiplication des vecteurs issus des deux matrices à tous les processus
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum = sum + aa[j] * b[j][i];           
        }
        cc[i] = sum;
        sum = 0;
    }

    //Réunis les processus pour former la matrice finale qui contient le résultat recherché
    MPI_Gather(cc, N*N/size, MPI_INT, c, N*N/size, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);        
    MPI_Finalize();

    //On affiche enfin les trois matrices, et on pourra vérifier par calcul la véracité du code utilisé
    if (rank == 0) {
        printMatrice("A = ", a);
        printMatrice("B = ", b);
        printMatrice("C = ", c);
    }
}