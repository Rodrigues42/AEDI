#include<stdio.h>
#include<stdlib.h>

struct tHeap
{
    int *itens;
    int tamanho;
    int quantidade;
};

struct tHeap criarHeap(int n)
{
    struct tHeap h;
    h.itens = (int*) malloc(n * sizeof(int));
    h.tamanho = n;
    h.quantidade = 0;
    return h;
}

int filhoEsquerda(int p)
{
    return (2 * p) + 1;
}

int filhoDireita(int p)
{
    return (2 * p) + 2;
}

int pai(int f)
{
    return (f - 1) / 2;
}

int ultimoPai(int n)
{
    return (n / 2) - 1;
}

void peneirar(struct tHeap *h, int p)
{
    int maior = p, aux;
    if(filhoEsquerda(p) < h->quantidade && h->itens[filhoEsquerda(p)] > h->itens[maior])
    {
        maior = filhoEsquerda(p);
    }
    if(filhoDireita(p) < h->quantidade && h->itens[filhoDireita(p)] > h->itens[maior])
    {
        maior = filhoDireita(p);
    }
    if(maior != p)
    {
        aux = h->itens[maior];
        h->itens[maior] = h->itens[p];
        h->itens[p] = aux;
        peneirar(h, maior);
    }
}

void construirHeap(struct tHeap *h)
{
    int i;
    for(i = ultimoPai(h->quantidade); i>=0; i--)
    {
        peneirar(h, i);
    }
}

void inserirHeap(struct tHeap *h, int chave)
{
    int indNovo = h->quantidade;
    if(h->quantidade < h->tamanho)
    {
        h->itens[indNovo] = chave;
        h->quantidade += 1;
    }
}

void mostrarHeap(struct tHeap h)
{
    int i;
    for(i=0; i<h.quantidade; i++)
    {
        printf("%d%s", h.itens[i], i<h.quantidade-1?" ":"\n");
    }
}

int main()
{
    int n, j;
    do
    {
        scanf("%d", &n);

        struct tHeap heap = criarHeap(n);
    
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &j);
            inserirHeap(&heap, j);
        }
        
        construirHeap(&heap);
        mostrarHeap(heap);

        free(heap.itens);
    } while (n != 0);

    return 0;
}