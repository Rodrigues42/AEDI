#include<stdio.h>
#include<stdlib.h>

void quickSort(int *v, int e, int d);
int particiona(int *vetor, int e, int d);
void imprimirVetor(int *vetor, int e, int d);

int main()
{
    int n;
    scanf("%d", &n);
    int *vetor = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    imprimirVetor(vetor, 0, 10);
    quickSort(vetor, 0, n);
    imprimirVetor(vetor, 0, 10);

    return 0;
}

void quickSort(int *vetor, int e, int d) 
{    
    int p;
    if(e < d)
    {
        p = particiona(vetor, e, d);
        quickSort(vetor, e, p);
        quickSort(vetor, p+1, d);
    }
}

int particiona(int *vetor, int e, int d)
{
    int pm = e-1;
    int i = e;
    for (i; i < d; i++)
    {
        if (vetor[i] <= vetor[d-1])
        {     
            pm++;
            int aux = vetor[i];
            vetor[i] = vetor[pm];
            vetor[pm] = aux;  
        }

        if (d - e > 1)
        {
            imprimirVetor(vetor, 0, 10);
        }
    }

    return  pm;
}

void imprimirVetor(int *vetor, int e, int d)
{
    for (int i = e; i < d; i++)
    {
        printf("%d%s", vetor[i], i<d-1?" ":"\n");
    }
}