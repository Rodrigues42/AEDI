#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tNo
{
    char chave;
    struct tNo * pai;
    struct tNo * direita;
    struct tNo * esquerda;
};

struct tArvore
{
    struct tNo * raiz;
};

struct tNo * criarNo(char);
struct tArvore * criarArvore();
struct tNo * raiz(struct tArvore *);
int arvoreVazia(struct tArvore *);
void preOrder(struct tNo *);
void inOrder(struct tNo *);
void postOrder(struct tNo *);
struct tNo * buscar(struct tArvore *, char);
void inserir(struct tArvore *, struct tNo *);
struct tNo * remover(struct tArvore *, char);
struct tNo * sucessor(struct tNo *);
struct tNo * removerSucessor(struct tNo *);

int main()
{
    char opc[12], chave;
    struct tNo *it;
    struct tArvore *arvore = criarArvore();

    while(scanf("%s ", opc) != EOF)
    {
        if(strcmp(opc, "insert") == 0 || strcmp(opc, "delete") == 0)
        {
            scanf("%c", &chave);

            if (strcmp(opc, "insert") == 0)
            {
                inserir(arvore, criarNo(chave));
            }
            else 
            {
                it = remover(arvore, chave);
                if(it != NULL)
                {
                    printf("%c\n", it->chave);
                    free(it);
                }
            }
        } else 
        {
            if (strcmp(opc, "pre-order") == 0)
            {
                preOrder(raiz(arvore));
            }
            else if (strcmp(opc, "in-order") == 0)
            {
                inOrder(raiz(arvore));
            }
            else if (strcmp(opc, "post-order") == 0)
            {
                postOrder(raiz(arvore));
            }
        }
    }

    return 0;
}

struct tNo * criarNo(char chave)
{
    struct tNo *no = (struct tNo *) malloc(sizeof(struct tNo));
    if(no != NULL)
    {
        no->chave = chave;
        no->pai = NULL;
        no->direita = NULL;
        no->esquerda = NULL;
    }
    return no;
}

struct tArvore * criarArvore()
{
    struct tArvore *t = (struct tArvore *) malloc(sizeof(struct tArvore));
    if(t != NULL)
    {
        t->raiz = NULL;
    }
    return t;
}

struct tNo * raiz(struct tArvore *t)
{
    return t->raiz;
}

int arvoreVazia(struct tArvore *t)
{
    return raiz(t) == NULL;
}

void preOrder(struct tNo *r)
{
    if(r != NULL)
    {
        printf("%c\n", r->chave);
        fflush(stdout);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}

void inOrder(struct tNo *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%c\n", r->chave);
        fflush(stdout);
        inOrder(r->direita);
    }
}

void postOrder(struct tNo *r)
{
    if(r != NULL)
    {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%c\n", r->chave);
        fflush(stdout);
    }
}

struct tNo * buscar(struct tArvore *t, char chave)
{
    struct tNo *no = raiz(t);

    while(no != NULL && no->chave != chave)
    {
        if(no->chave < chave)
        {
            no = no->direita;
        }
        else
        {
            no = no->esquerda;
        }
    }
    return no;
}

void inserir(struct tArvore *t, struct tNo *novo)
{
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave < novo->chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(pai != NULL) // nao eh raiz
    {
        novo->pai = pai;
        if(pai->chave < novo->chave)
        {
            pai->direita = novo;
        }
        else
        {
            pai->esquerda = novo;
        }
    }
    else // eh raiz
    {
        t->raiz = novo;
    }
}

struct tNo * remover(struct tArvore *t, char chave)
{
    struct tNo *pai = NULL, *filho = raiz(t), *subs;

    while(filho != NULL && filho->chave != chave)
    {
        pai = filho;
        if(filho->chave < chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) // encontrei
    {
        if(filho->esquerda == NULL && filho->direita == NULL) // removendo uma folha
        {
            if(pai != NULL) // nao eh raiz
            {
                if(pai->esquerda == filho)
                {
                    pai->esquerda = NULL;
                }
                else
                {
                    pai->direita = NULL;
                }
            }
            else // eh raiz
            {
                t->raiz = NULL;
            }
        }
        else if(filho->esquerda != NULL && filho->direita != NULL) // removendo um pai de dois filhos
        {
            subs = removerSucessor(sucessor(filho));

            subs->pai = pai;
            subs->esquerda = filho->esquerda;
            subs->direita = filho->direita;

            if(pai != NULL)
            {
                if(pai->esquerda == filho)
                {
                    pai->esquerda = subs;
                }
                else
                {
                    pai->direita = subs;
                }
            }
            else
            {
                t->raiz = subs;
            }

            if(filho->esquerda != NULL)
            {
                filho->esquerda->pai = subs;
            }
            if(filho->direita != NULL)
            {
                filho->direita->pai = subs;
            }
        }
        else // removendo o pai de um filho unico
        {
            if(pai != NULL) // nao eh raiz
            {
                if(pai->esquerda == filho) // no a ser removido eh filho da esquerda do pai
                {
                    if(filho->esquerda != NULL)
                    {
                        pai->esquerda = filho->esquerda;
                        filho->esquerda->pai = pai;
                    }
                    else
                    {
                        pai->esquerda = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
                else // no a ser removido eh filho da direita do pai
                {
                    if(filho->esquerda != NULL)
                    {
                        pai->direita = filho->esquerda;
                        filho->esquerda->pai = pai;
                    }
                    else
                    {
                        pai->direita = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
            }
            else // eh raiz
            {
                if(filho->esquerda != NULL)
                {
                    t->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                }
                else
                {
                    t->raiz = filho->direita;
                    filho->direita->pai = NULL;
                }
            }
        }
        filho->pai = NULL;
        filho->esquerda = NULL;
        filho->direita = NULL;
    }
    return filho;
}

struct tNo * sucessor(struct tNo *r)
{
    struct tNo * pai = NULL;
    r = r->direita;
    while(r != NULL)
    {
        pai = r;
        r = r->esquerda;
    }
    return pai;
}

struct tNo * removerSucessor(struct tNo *r)
{
    struct tNo *pai = r->pai;

    if(r->esquerda == NULL && r->direita == NULL) //eh folha
    {
        if(pai->esquerda == r)
        {
            pai->esquerda = NULL;
        }
        else
        {
            pai->direita = NULL;
        }
    }
    else // eh pai de um
    {
        if(pai->esquerda == r)
        {
            pai->esquerda = r->direita;
        }
        else
        {
            pai->direita = r->direita;
        }
        r->direita->pai = pai; // tem que ver se nao vai dar RTE
    }

    return r;
}
