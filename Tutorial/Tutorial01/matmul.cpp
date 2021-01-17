#include <cstdio>
#include <iostream>

using namespace std;

//Defines for Readability
#define M 2
#define P 3
#define N 2

void matmul_one_element( int A[][P], int B[][N], int C[][N], 
                        int i, int j);
//Purpose: Perform the matrix multiplication for one element at C[i][j]
//       : C[i][j] = Sum (A[i][k] * B[k][j]), where k = 0...P-1


void matmul ( int A[][P], int B[][N], int C[][N]);
//Purpose: Perform matrix multiplication for matrices A x B, result in C


int main()
{
    int matA[M][P] = { 
                        {1, 2, 3},
                        {4, 5, 6}
                     };

    int matB[P][N] = {
                        {1, 2},
                        {3, 4},
                        {5, 6}
                     };

    int matC[M][N] = {{0}}; //just zeroes the whole matrix

    
    int i, j;

    matmul(matA, matB, matC);

    //Simply print out the matrix for checking
    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++){
            cout << matC[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

void matmul_one_element( int A[][P], int B[][N], int C[][N], 
                        int i, int j) 
{
    // for (int matA = 0; matA <= P; matA++)
    // {
    //     for (int matB = 0; matB <= N; matB++)
    //     {
    //         C[i][j] += A[i][matA] * B[matB][j];
    //     }
    // }
    for (int k = 0; k < P; k++)
    {
        C[i][j] += A[i][k] * B[k][j];
    }
    
    
}

void matmul ( int A[][P], int B[][N], int C[][N])
{
}
