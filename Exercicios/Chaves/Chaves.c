#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Chaves
{
    char linha[100];
};

int* buscarChaves(char* linha, char simbolo)
{

    int indices[100];
    int tamanho = 0;

    for (int i = 0; i < sizeof(linha); i++)
    {
        if (strcmp(linha[i], simbolo) == 0)
        {
            indices[tamanho] = i;
            tamanho++;
        }
    }

    return indices;
}

int main()
{
    int n;
    struct Chaves *linhas;
    char chavesAberta[100];

    scanf("%d", &n);
    getchar();
    linhas = (struct Chaves *) malloc(n * sizeof(struct Chaves *));

    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]", linhas[i].linha);
        getchar();
    }

    chavesAberta = buscarChaves(char *linha, '{');
    for (int i = 0; i < sizeof(chavesAberta); i++)
    {
        printf("%s\n", linhas[chavesAberta[i]].linha);
    }
    

    return 0;
}