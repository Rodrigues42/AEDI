#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);  

    while (n != 0)
    {
        int vetor[n];
        int maior = 0;
        int indiceMaior = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vetor[i]);
            if (vetor[i] > maior)
            {
                maior = vetor[i];
                indiceMaior = i;
            }
        }

        printf("%d %d\n", indiceMaior, maior);

        scanf("%d", &n);  
    }

    return 0;
}