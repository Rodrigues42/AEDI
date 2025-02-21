#include<stdio.h>

int main()
{
    char u[51];
    int a;

    printf("Onde voce estuda: ");
    scanf("%s", u);

    printf("Quanto tempo: ");
    scanf("%d", &a);

    printf("Voce estuda na %s ha %d anos.\n", u, a);

    return 0;
}