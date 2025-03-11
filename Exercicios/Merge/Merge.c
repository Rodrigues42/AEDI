#include<stdio.h>
#include<stdlib.h>

void merge(int *vetor, int *vResultante, int inicio, int fim, int n);
void imprimirVetor(int *vetor, int n);
void intercala(int *v, int *vResultante, int q1, int meio, int q2);

int main()
{
    int n;
    scanf("%d", &n);
    int *vetor = (int *) malloc(n * sizeof(int));
    int *vResultante = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
        vResultante[i] = vetor[i];
    }

    merge(vetor, vResultante, 0, n, n);
    imprimirVetor(vResultante, n);

    return 0;
}

void merge(int *vetor, int *vResultante, int inicio, int fim, int n)
{
    int meio;
    if (inicio < fim)
    {
        meio = (fim + inicio) / 2;
        merge(vetor, vResultante, inicio, meio, n);
        merge(vetor, vResultante, meio + 1, fim, n);
        imprimirVetor(vResultante, n);
        intercala(vetor, vResultante, inicio, meio+1, fim);
    }
}

void imprimirVetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", vetor[i], i<n-1?" ":"\n");
    }
}

void intercala(int *v, int *vResultante,int esquerda, int meio, int direita)
{
    int aux1 = esquerda, aux2 = meio;
    for (size_t i = 0; aux1 < meio && aux2 < direita; i++)
    {
        if (v[aux1] < v[aux2])
        {
            vResultante[i] = v[aux1];
            aux1++;
        } else
        {
            vResultante[i] = v[aux2];
            aux2++;
        }
    }
}