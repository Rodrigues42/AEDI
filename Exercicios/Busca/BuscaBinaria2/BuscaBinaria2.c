#include<stdio.h>
#include<stdlib.h>

int buscaBinaria(int *vetor, int inicio, int fim, int elemento);
int imprimirVetor(int *vetor, int inicio, int fim);

int main()
{
    int *vetor;
    int n, elemento;

    scanf("%d", &n);
    vetor = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    while (scanf("%d", &elemento) != EOF)
    {
        buscaBinaria(vetor, 0, n-1, elemento);
    }
}

int buscaBinaria(int *vetor, int inicio, int fim, int elemento)
{
    int meio;
    if (inicio <= fim)
    {
        meio = (fim + inicio) / 2;
        if(vetor[meio] == elemento)
        {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", elemento);
            return vetor[meio];
        } else if(vetor[meio] > elemento)
        {
            imprimirVetor(vetor, meio, fim);
            return buscaBinaria(vetor, inicio, meio-1, elemento);
        } else
        {
            imprimirVetor(vetor, inicio, meio);
            return buscaBinaria(vetor, meio+1, fim, elemento);
        }
    } else
    {
        printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", elemento);
        return -1;
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