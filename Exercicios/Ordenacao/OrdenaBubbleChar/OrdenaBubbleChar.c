#include<stdio.h>
#include<stdlib.h>

int bubbleSortChar(char *vetor, int n, int *troca);
int imprimirVetor(char *vetor, int inicio, int fim);

int main()
{
    int n, qtdTroca = 0;
    scanf("%d", &n);

    char *vetor;
    vetor = (char *) malloc(n * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &vetor[i]);
    }
    
    imprimirVetor(vetor, 0, n-1);
    bubbleSortChar(vetor, n, &qtdTroca);
    imprimirVetor(vetor, 0, n-1);
    printf("Trocas: %d\n", qtdTroca);

    return 0;
}

int bubbleSortChar(char *vetor, int n, int *qtdTroca)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                char temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                *qtdTroca += 1;

                imprimirVetor(vetor, 0, n-1);
            }
        }
    }
}

int imprimirVetor(char *vetor, int inicio, int fim)
{
    for(int i = inicio; i <= fim; i++)
    {
        if (i == fim)
        {
            printf("%c\n", vetor[i]);
        } 
        else
        {
            printf("%c ", vetor[i]);
        }
    }
}
