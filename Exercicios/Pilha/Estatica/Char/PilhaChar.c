#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tItem
{
    char valor;
};

struct tPilha
{
    struct tItem *itens;
    int tamanho;
    int topo;
};

int pilhaVazia(struct tPilha p)
{
    return p.topo == -1;
}

int pilhaCheia(struct tPilha p)
{
    return p.topo == p.tamanho-1;
}

struct tItem criarItem(char valor)
{
    struct tItem it;

    it.valor = valor;

    return it;
}

struct tPilha criarPilha(int n)
{
    struct tPilha p;
    p.itens = (struct tItem *) malloc(n * sizeof(struct tItem));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

struct tItem topo(struct tPilha p)
{
    return p.itens[p.topo];
}

void empilhar(struct tPilha *p, struct tItem novo)
{
    if(!pilhaCheia(*p))
    {
        p->itens[++p->topo] = novo;
    }
}

void desempilhar(struct tPilha *p)
{
    if(!pilhaVazia(*p))
    {
        p->topo -= 1;
    }
}

void mostrarPilhaBaseTopo(struct tPilha p)
{
    int i;
    for(i=0; i<=p.topo; i++)
    {
        printf("%c%s", p.itens[i].valor, i<p.topo?" ":"\n");
    }
}

void mostrarPilhaTopoBase(struct tPilha p)
{
    if(!pilhaVazia(p))
    {
        printf("%c%s", topo(p).valor, p.topo>0?" ":"\n");
        desempilhar(&p);
        mostrarPilhaTopoBase(p);
    }
}

int main()
{
    char opc = 'T', valor;
    int n;
    struct tPilha pilha;

    scanf("%d", &n);
    pilha = criarPilha(n);

    do
    {               
        switch(opc)
        {
            case 'E': getchar();
                    scanf("%c", &valor);
                    getchar();
                    empilhar(&pilha, criarItem(valor));
                    break;
            case 'B': mostrarPilhaBaseTopo(pilha);
                    break;
            case 'X': mostrarPilhaTopoBase(pilha);
                    break;
            case 'T': if(!pilhaVazia(pilha))
                    {
                        printf("%c\n", topo(pilha).valor);
                    }
                    break;
            case 'D': if(!pilhaVazia(pilha))
                    {
                        desempilhar(&pilha);
                    }
        }
    } while(scanf("%c", &opc) != EOF);

    return 0;
}