#include<stdio.h>
#include<stdlib.h>

struct tLista
{
    char *itens;
    int tamanho;
    int quantidade;
};

struct tLista criarLista(int n)
{
    struct tLista l;
    l.itens = (char *) malloc(n * sizeof(char));
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
        printf("%c%s", l.itens[i], i<l.quantidade-1?" ":"\n");
    }
}

int buscaLista(struct tLista l, char chave)
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

void inserir(struct tLista *l, char chave)
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

void remover(struct tLista *l, char iRem)
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
    int iChave, n, j = 0;
    char opc = 'M', chave;
    struct tLista lista;

    scanf("%d", &n);
    getchar();
    lista = criarLista(n);
    
    do
    {   
        if (opc == 'M')
        {
            j++;
            if(j > 1)
            {
                getchar();
            }
            
        } else
        {
            getchar();
            scanf("%c", &chave);
            getchar();
        }

        switch(opc)
        {
            case 'I': inserir(&lista, chave);
                    break;
            case 'M': mostrarLista(lista);
                    break;
            case 'B': iChave = buscaLista(lista, chave);
                    if(iChave != -1)
                    {
                        printf("SIM\n");
                    }
                    else
                    {
                        printf("NAO\n");
                    }
                    break;
            case 'R': remover(&lista, buscaLista(lista, chave));
        }
    } while(scanf("%c", &opc) != EOF);

    return 0;
}