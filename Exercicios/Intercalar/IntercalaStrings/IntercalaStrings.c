#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n1, n2, aux1=0, aux2=0;
    char *s1, *s2, *sr;

    scanf("%d", &n1);
    s1 = (char *) malloc(n1 + 2 * sizeof(char *));
    scanf("%s", s1);

    scanf("%d", &n2);
    s2 = (char *) malloc(n2 + 2 * sizeof(char *));
    scanf("%s", s2);

    sr = (char *) malloc((n1 + n2 + 2) * sizeof(char *));

    for (i=0; aux1 < n1 && aux2 < n2; i++)
    {
        if(s1[aux1] < s2[aux2])
        {
            sr[i] = s1[aux1];
            aux1++;
        } else
        {
            if (s1[aux1] >= s2[aux2])
            {
                sr[i] = s2[aux2];
                aux2++;
            }
        }
    }

    if (n1 > n2 && aux1 < n1)
    {
        for (int j = aux1; j < n1; j++)
        {
            sr[i] = s1[j];
            i++;
        }
    } else if (n2 > n1 && aux2 < n2)
    {
        for (int j = aux2; j < n2; j++)
        {
            sr[i] = s2[j];
            i++;
        }
    } else
    {
        if (aux1 == n1)
        {
            for (int j = aux2; j < n2; j++)
            {
                sr[i] = s2[j];
                i++;
            }
        } else
        {
            for (int j = aux1; j < n1; j++)
            {
                sr[i] = s1[j];
                i++;
            }
        }   
    }

    printf("%s\n", sr);

    free(s1);
    free(s2);
    free(sr);
    return 0;
}