#include<stdio.h>
#include<stdlib.h>

void merge(int *vetor, int inicio, int fim, int n);
void imprimirVetor(int *vetor, int n);
void intercala(int *v, int q1, int meio, int q2);

int main()
{
    int n;
    scanf("%d", &n);
    int *vetor = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    imprimirVetor(vetor, n);
    merge(vetor, 0, n, n);
    imprimirVetor(vetor, n);

    free(vetor);
    return 0;
}

void merge(int *vetor, int inicio, int fim, int n)
{
    int meio;
    if (inicio < fim)
    {
        meio = (fim + inicio) / 2;
        merge(vetor, inicio, meio, n);
        merge(vetor, meio + 1, fim, n);
        imprimirVetor(vetor, n);
        intercala(vetor, inicio, meio, fim);
    }
}

void intercala(int *v,int esquerda, int meio, int direita)
{
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *vetorEsquedo = (int *)malloc(n1 * sizeof(int));
    int *vetorDireito = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        vetorEsquedo[i] = v[esquerda + i];

    for (int i = 0; i < n2; i++)
        vetorDireito[i] = v[meio + 1 + i];

    int i = 0, j = 0, k = esquerda;

    while (i < n1 && j < n2) {
        if (vetorEsquedo[i] <= vetorDireito[j]) {
            v[k] = vetorEsquedo[i];
            i++;
        } else {
            v[k] = vetorDireito[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = vetorEsquedo[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = vetorDireito[j];
        j++;
        k++;
    }

    free(vetorEsquedo);
    free(vetorDireito);
}

void imprimirVetor(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", vetor[i], i<n-1?" ":"\n");
    }
}