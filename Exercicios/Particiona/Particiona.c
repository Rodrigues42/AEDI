#include<stdio.h>
#include<stdlib.h>

int main()
{
    int q, p;
    scanf("%d %d", &q, &p);
    int *vetor = (int *) malloc((q + 2) * sizeof(int));
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &vetor[i]);
    }

    int aux = vetor[p];
    vetor[p] = vetor[q-1];
    vetor[q-1] = aux;

    int pm = -1, i = 0;

    for (i = 0; i < q; i++)
    {
        if (vetor[i] <= vetor[q-1])
        {                                                
            pm++;
            int aux = vetor[i];
            vetor[i] = vetor[pm];
            vetor[pm] = aux;  
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}