#include<stdio.h>
#include<stdlib.h>

struct tLista
{
    float *itens;
    int tamanho;
    int quantidade;
};

struct tLista criarLista(int n)
{
    struct tLista l;
    l.itens = (float*) malloc(n * sizeof(float));
    l.tamanho = n;
    l.quantidade = 0;
    return l;
}

int listaCheia(struct tLista l)
{
    return l.quantidade == l.tamanho;
}

int listaVazia(struct tLista l)
{
    return l.quantidade == 0;
}

void mostrarLista(struct tLista l)
{
    int i;
    for(i=0; i<l.quantidade; i++)
    {
        printf("%.1f%s", l.itens[i], i<l.quantidade-1?" ":"\n");
    }
}

int buscaLista(struct tLista l, float chave)
{
    int i;
    for(i=0; i<l.quantidade; i++)
    {
        if(l.itens[i] == chave)
        {
            return i;
        }
    }
    return -1;
}

void inserir(struct tLista *l, float chave)
{    
    int i, j;
    if(!listaCheia(*l))
    {
        for(i=0; l->itens[i] < chave && i < l->quantidade; i++);
        
        if(l->itens[i] != chave)
        {
            for(j=l->quantidade-1; j>=i; j--)
            {
                l->itens[j+1] = l->itens[j];
            }
            l->itens[i] = chave;
            l->quantidade += 1;
        }
    }
}

void remover(struct tLista *l, float iRem)
{
    int i;
    if(!listaVazia(*l) && iRem != -1)
    {
        for(i=iRem; i<l->quantidade-1; i++)
        {
            l->itens[i] = l->itens[i+1];
        }
        l->quantidade -= 1;
    }
}

int main()
{
    float chave;
    int iChave, n;
    char opc, input[50];
    struct tLista lista;

    scanf("%d", &n);
    lista = criarLista(n);

    do
    {
        int hasValue = 0;
        if (opc != 'M')
        {
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n') {  // Se não for apenas Enter
                if (sscanf(input, "%f", &chave) == 1) 
                {
                    hasValue = 1;
                }
            }
        }
        
        switch(opc)
        {
            case 'I': hasValue ? inserir(&lista, chave) 
            : "";
                    break;
            case 'M': mostrarLista(lista);
                    break;
            case 'B': hasValue ? (iChave = buscaLista(lista, chave)) : (iChave = -1);
                    if(iChave != -1)
                    {
                        printf("SIM\n");
                    }
                    else
                    {
                        printf("NAO\n");
                    }
                    break;
            case 'R': hasValue ? remover(&lista, buscaLista(lista, chave)) : "";
        }
    } while(scanf(" %c", &opc) != EOF);

    return 0;
}