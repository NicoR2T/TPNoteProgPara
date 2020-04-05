#ifndef __PRINTMATRICE_H_

#define __PRINTMATRICE_H_

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include "mpi.h"

#define N 4

void printMatrice(char *prompt, int a[N][N]);

#endif