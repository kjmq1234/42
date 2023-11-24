#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int compare(const void* one, const void* two);
void initial(int n);

const int n;
typedef int index;
typedef index set_pointer;

typedef int bool;

typedef struct
{
    index parents;
    int depth;
} nodetype;

typedef nodetype* universe;
universe U;

typedef struct
{
    int set1;
    int set2;
    int weight;
} edge;

typedef edge* set_of_edges;

void makeset(index i)
{
    U[i].parents = i;
    U[i].depth = 0;
}

set_pointer find(index i)
{
    index j;
    j = i;
    while (U[j].parents != j)
        j = U[j].parents;
    return (j);
}

void merge(set_pointer p, set_pointer q)
{
    if (U[p].depth == U[q].depth)
    {
        U[p].depth++;
        U[q].parents = p;
    }
    else if (U[p].depth < U[q].depth)
        U[p].parents = q;
    else
        U[q].parents = p;
}

bool equal(set_pointer p, set_pointer q)
{
    if (p == q)
        return TRUE;
    return FALSE;
}

void initial(int n)
{
    index i;

    for (int i = 0; i < n; i++)
        makeset(i);
}

int compare(const void* one, const void* two)
{
    if ((((edge*) one)->weight - ((edge*)two)->weight) > 0) 
        return (1);
    else if ((((edge*) one)->weight - ((edge*)two)->weight) < 0)
        return (-1);
    else
        return (0);
}

set_of_edges F;

void kruskal(int n, int m, set_of_edges E)
{
    int cnt= 0, fidx = 0;
    int i, j;
    edge e;
    set_pointer p, q;
    
    qsort(E, m, sizeof(E[0]), compare);
    F = (edge*)calloc(sizeof(edge), n - 1);
    initial(n);
    while (fidx < n - 1){
        e = E[cnt];
        i = e.set1;
        j = e.set2;
        p = find(i);
        q = find(j);
        if (!equal(p, q))
        {
            merge(p, q);
            F[fidx++] = e;
        }
        cnt++;
    }
}

int main(void)
{
    int n, m;
    edge* graph;
    int tmp;

    scanf("%d %d", &n, &m);
    graph = (edge*) malloc(sizeof(edge) * m);
    U = (nodetype*) malloc(sizeof(nodetype) * n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &graph[i].set1, &graph[i].set2, &graph[i].weight);
    }
    kruskal(n, m, graph);
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        printf("v%d v%d %d\n", F[i].set1, F[i].set2, F[i].weight);
}