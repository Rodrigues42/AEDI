#include<stdio.h>
#include<stdlib.h>

int main()
{
    long int i, q1, q2, aux1=0, aux2=0;
    int *v1, *v2, *vResultante;

    scanf("%ld\n%ld", &q1, &q2);
    v1 = (int *) malloc(q1 * sizeof(int *));
    v2 = (int *) malloc(q2 * sizeof(int *));
    vResultante = (int *) malloc( (q1 + q2) * sizeof(int *));

    for (int i = 0; i < q1; i++)
    {
        scanf("%d", &v1[i]);
    }

    for (int i = 0; i < q2; i++)
    {
        scanf("%d", &v2[i]);
    }

    for (i = 0; aux1 < q1 && aux2 < q2; i++)
    {
        if(v1[aux1] < v2[aux2])
        {
            vResultante[i] = v1[aux1];
            aux1++;
        } else
        {
            vResultante[i] = v2[aux2];
            aux2++;
        }
    }
    
    if (q1 > q2 && aux1 < q1)
    {
        for (int j = aux1; j < q1; j++)
        {
            vResultante[i] = v1[j];
            i++;
        }
    } else if (q2 > q1 && aux2 < q2)
    {
        for (int j = aux2; j < q2; j++)
        {
            vResultante[i] = v2[j];
            i++;
        }
    } else
    {
        if (aux1 == q1)
        {
            for (int j = aux2; j < q2; j++)
            {
                vResultante[i] = v2[j];
                i++;
            }
        } else
        {
            for (int j = aux1; j < q1; j++)
            {
                vResultante[i] = v1[j];
                i++;
            }
        }   
    }
    
    for (int i = 0; i < q1 + q2; i++)
    {
        printf("%d\n", vResultante[i]);
    }

    free(v1);
    free(v2);
    return 0;
}
