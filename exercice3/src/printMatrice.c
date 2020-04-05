#include "printMatrice.h"

void printMatrice(char *prompt, int a[N][N]) {
        int i, j;

        //Affiche la chaîne de caractères puis la matrice souhaitée en parcourant tous les indices
        printf ("%s\n", prompt);
        for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                        printf(" %d", a[i][j]);
                }
                printf ("\n");
        }
        printf ("\n");
}