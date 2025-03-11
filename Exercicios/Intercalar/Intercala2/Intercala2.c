#include<stdio.h>
#include<stdlib.h>

int main()
{
    long int i, q1, q2;
    long int *v, *vResultante;

    scanf("%ld\n%ld", &q1, &q2);
    v = (long int *) malloc((q1 + q2 + 2 )* sizeof(long int *));
    vResultante = (long int *) malloc( (q1 + q2 + 2) * sizeof(long int *));

    for (int j = 0; j < q1 + q2; j++)
    {
        scanf("%ld", &v[j]);
    }

    int aux1=0;
    int aux2=q1;

    for (i = 0; aux1 < q1 && aux2 < q1 + q2; i++)
    {
        if(v[aux1] < v[aux2])
        {
            vResultante[i] = v[aux1];
            aux1++;
        } else
        {
            vResultante[i] = v[aux2];
            aux2++;
        }
    }
    
    
    if (q1 > q2 && aux1 < q1)
    {
        for (int j = aux1; j < q1; j++)
        {
            vResultante[i] = v[j];
            i++;
        }
    } else if (q2 > q1 && aux2 < q1 + q2)
    {
        for (int j = aux2; j < q1 + q2; j++)
        {
            vResultante[i] = v[j];
            i++;
        }
    } else
    {
        if (aux1 == q1)
        {
            for (int j = aux2; j < q1 + q2; j++)
            {
                vResultante[i] = v[j];
                i++;
            }
        } else
        {
            for (int j = aux1; j < q1; j++)
            {
                vResultante[i] = v[j];
                i++;
            }
        }   
    }
    
    for (int k = 0; k < q1 + q2; k++)
    {
        printf("%ld\n", vResultante[k]);
    }

    free(v);
    free(vResultante);
    return 0;
}
