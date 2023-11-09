#define INF 999999999
#include <stdio.h>
#include <stdlib.h>

int minmult(int n, const int* d, int** P);
void input(int n, int* d);
int minimum(int** M, int i, int j, const int* d, int* mink);
void order(int i, int j);

int** M;
int** P;

int main(void)
{
    int n;
    int* d;

    scanf("%d", &n);
    d = (int*) malloc(sizeof(int) * (n + 1));
    M = (int**) malloc(sizeof(int*) * (n + 1));
    P = (int**) malloc(sizeof(int*) * (n + 1));

    for (int i = 1; i <= n; i++)
    {
        M[i] = (int*) malloc(sizeof(int) * (n + 1));
        P[i] = (int*) malloc(sizeof(int) * (n + 1));
    }
    input(n, d);
    printf("%d\n", minmult(n, d, P));
    order(1, n);
}

void input(int n, int* d)
{
    scanf("%d", &d[0]);
    for (int i = 2; i <= n * 2; i++)
    {
        scanf("%d", &d[i / 2]);
    }
}

int minmult(int n, const int* d, int** P)
{
    int j, k;

    for (int i = 1; i <= n; i++)
        M[i][i] = 0;
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (int i = 1; i <= n - diagonal; i++)
        {
            j = i + diagonal;
            M[i][j] = minimum(M, i, j, d, &k);
            P[i][j] = k;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         printf("%3d ", M[i][j]);
        //     }
        //     printf("\n");
        // }
        //     printf("\n\n");
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         printf("%3d ", P[i][j]);
        //     }
        //     printf("\n");
        // }
        //     printf("\n\n");

    }
    return (M[1][n]);
}
int minimum(int** M, int i, int j, const int* d, int* mink)
{
    int minvalue = INF;
    int sum;

    *mink = 0;
    for (int k = i; k < j; k++)
    {
        sum = 0;
        sum += M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);
        if (minvalue > sum)
        {
            minvalue = sum;
            *mink = k;
        }
    }
    return (minvalue);
}

void order(int i, int j)
{
    int k;

    if (i == j)
        printf("A%d", i);
    else
    {
        k = P[i][j];
        printf("(");
        order(i, k);
        order(k + 1,j);
        printf(")");
    }
}