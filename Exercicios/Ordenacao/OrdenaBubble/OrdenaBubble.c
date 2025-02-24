#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *vetor, int n, int *troca);
int imprimirVetor(int *vetor, int inicio, int fim);

int main()
{
    int n, troca = 0;
    scanf("%d", &n);

    int *vetor;
    vetor = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    imprimirVetor(vetor, 0, n-1);
    bubbleSort(vetor, n, &troca);
    imprimirVetor(vetor, 0, n-1);
    printf("Trocas: %d\n", troca);

    return 0;
}

int bubbleSort(int *vetor, int n, int *troca)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                *troca += 1;

                imprimirVetor(vetor, 0, n-1);
            }
        }
    }
}

int imprimirVetor(int *vetor, int inicio, int fim)
{
    for(int i = inicio; i <= fim; i++)
    {
        if (i == fim)
        {
            printf("%d\n", vetor[i]);
        } 
        else
        {
            printf("%d ", vetor[i]);
        }
    }
}