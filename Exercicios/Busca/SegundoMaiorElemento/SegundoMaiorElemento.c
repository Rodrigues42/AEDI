#include<stdio.h>
#include<limits.h>

int main()
{
    int n;
    scanf("%d", &n);  

    int vetor[n];
    int maior = INT_MIN, segundoMaior = INT_MIN;
    int indiceMaior = 0, indiceSegundoMaior = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
        if (vetor[i] > maior)
        {
            segundoMaior = maior;
            indiceSegundoMaior = indiceMaior;
            maior = vetor[i];
            indiceMaior = i;
        } else if (vetor[i] > segundoMaior && vetor[i] <= maior)
        {
            segundoMaior = vetor[i];
            indiceSegundoMaior = i;
        }
    }

    printf("%d %d\n", indiceSegundoMaior, segundoMaior);

    return 0;
}