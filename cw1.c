#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **mat1, **mat2, **result;

int populate_matrix(int **mat, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat[i][j] = rand() %100;
        }
    }
    return 0;
}

int print_matrix(int **mat, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int multiply_matrixes(int **mat1, int **mat2, int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
        {
            for(int k=0; k<c; k++)
            {
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    int N, M, seed;

    if (argc != 4)
    {
        printf("ERROR: incorrect number of arguments\n");
    }

    else if((atoi(argv[1])==0) || (atoi(argv[2])==0))
    {
        printf("ERROR: invalid argument\n");
    }

    // else if((atoi(argv[3])==0))
    // {
    // }

    else
    {

        N = atoi(argv[1]);
        M = atoi(argv[2]);
        seed = atoi(argv[3]);

        //srand(time(seed));
        srand(seed);

        printf("MATRIX 1:\n");
        // creat_matrix(mat1,N,M);
        mat1 = malloc(N * sizeof(int *));
        if(mat1 == NULL) return -1;
        for(int i=0; i<N; i++)
        {
            mat1[i] = malloc(M * sizeof(int));
            if(mat1[i] == NULL) return -1;
        }
        populate_matrix(mat1,N,M);
        print_matrix(mat1,N,M);

        printf("MATRIX 2:\n");
        //creat_matrix(mat2,M,N);
        mat2= malloc(M * sizeof(int *));
        if(mat2 == NULL) return -1;
        for(int i=0; i<M; i++)
        {
            mat2[i] = malloc(N * sizeof(int));
            if(mat2[i] == NULL) return -1;
        }
        populate_matrix(mat2,M,N);
        print_matrix(mat2,M,N);

        printf("RESULT:\n");
        // creat_matrix(result,N,N);
        result = malloc(N * sizeof(int *));
        if(result == NULL) return -1;
        for(int i=0; i<N; i++)
        {
            result[i] = malloc(N * sizeof(int));
            if(result[i] == NULL) return -1;
        }
        clock_t begin = clock();
        multiply_matrixes(mat1, mat2, N, M);
        clock_t end = clock();

        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        print_matrix(result,N,N);
        printf("EXECUTION TIME: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);

        for(int num=0; num<N; num++)
        {
            free(mat1[num]);
            free(result[num]);
        }
        for(int num=0; num<M; num++)
        {
            free(mat2[num]);
        }
        free(mat1);
        free(mat2);
        free(result);
    }

    return 0;
}
