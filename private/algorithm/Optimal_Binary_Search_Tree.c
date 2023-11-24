#define INF 999999999
#include <stdio.h>
#include <stdlib.h>

void optsearchtree(int n, const float *P, float* mink, int** R);
float minimum(const float* p, int i, int j, float* mink);

float** A;

int main(void)
{
    int n;
    float *p;
    int** R;
    float minavg;

    scanf("%d", &n);
    p = (float*) calloc(sizeof(float), n + 1);
    R = (int**) calloc(sizeof(int*), (n + 2));
    for (int i = 1; i <= n; i++)
        scanf("%f", &p[i]);
    for (int i = 0; i <= n + 1; i++)
        R[i] = (int*) calloc(sizeof(int), (n + 1));
    A = (float**) calloc(sizeof(float*), (n + 2));
    for (int i = 0; i <= n + 1; i++)   
       A[i] = (float*) calloc(sizeof(float), (n + 1));
    optsearchtree(n, p, &minavg, R);
    printf("%f", minavg);
}

void optsearchtree(int n, const float *p, float* minavg, int** R)
{
    int j;
    float mink;

    for (int i = 1; i <= n; i++)
    {
        A[i][i-1] = 0;
        A[i][i]= p[i];
        R[i][i] = i;
        R[i][i - 1] = 0;
    }
    A[n + 1][n] = 0;
    R[n + 1][n] = 0;
    for (int diagonal = 1; diagonal <= n - 1; diagonal++)
    {
        for (int i = 1; i <= n - diagonal; i++)
        {  
            j = i + diagonal;
            A[i][j] = minimum(p, i, j, &mink);
            R[i][j] = mink;
        }
    }
    *minavg = A[1][n];
}

float minimum(const float* p, int i, int j, float* mink)
{
    float minvalue = INF;
    float sum;

    *mink = 0;
    for (int k = i; k <= j; k++)
    {
        sum = A[i][k - 1] + A[k + 1][j];
        for (int m = i; m <= j; m++)
            sum+= p[m];        
        if (minvalue > sum)
        {
            minvalue = sum;
            *mink = k;
        }
    }
    return (minvalue);
}
