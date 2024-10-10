#include <stdio.h>
#define SIZE 5

int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int added[SIZE][SIZE] = {{0}};
    // Iterate through each matrix
    for (int i=0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            added[i][j] = m1[i][j] + m2[i][j]; // Insert sum into each corresponding element of added array
            printf("%d ", added[i][j]);
        }
        printf("\n");
    }
}

int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int product[SIZE][SIZE] = {{0}};
    for (int i=0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                product[i][j] += m1[i][k]*m2[k][j];
            }
            printf("%d ", product[i][j]);
        }
    printf("\n");
    }
}

int transposeMatrix(int m1[SIZE][SIZE]) {
    int transposed[SIZE][SIZE] = {{0}};
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            transposed[i][j] = m1[j][i];
            printf("%d ", transposed[i][j]);
        }
    printf("\n");
    }
}


int main() {
    // Initialize matrix
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Initialize matrix
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    addMatrices(m1, m2);
    multiplyMatrices(m1, m2);
    transposeMatrix(m1);
}