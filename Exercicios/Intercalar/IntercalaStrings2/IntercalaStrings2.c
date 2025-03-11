#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, m;
    char su[20002], *suResultante;

    scanf("%s", su);
    scanf("%d %d", &n, &m);
    suResultante = (char *) malloc((n + m + 2) * sizeof(char *));

    int auxN = 0;
    int auxM = n;

    for (i=0; auxN < n && auxM < n + m; i++)
    {
        if(su[auxN] < su[auxM])
        {
            suResultante[i] = su[auxN];
            auxN++;
        } else
        {
            if (su[auxN] >= su[auxM])
            {
                suResultante[i] = su[auxM];
                auxM++;
            }
        }
    }

    
    if (n > m && auxN < n)
    {
        for (int j = auxN; j < n; j++)
        {
            suResultante[i] = su[j];
            i++;
        }
    } else if (m > n && auxM < n + m)
    {
        for (int j = auxM; j < n + m; j++)
        {
            suResultante[i] = su[j];
            i++;
        }
    } else
    {
        if (auxN == n)
        {
            for (int j = auxM; j < n + m; j++)
            {
                suResultante[i] = su[j];
                i++;
            }
        } else
        {
            for (int j = auxN; j < n; j++)
            {
                suResultante[i] = su[j];
                i++;
            }
        }   
    }

    printf("%s\n", suResultante);

    free(suResultante);
    return 0;
}