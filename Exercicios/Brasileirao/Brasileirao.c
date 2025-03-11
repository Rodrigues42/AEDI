#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct ResultadoPartida
{
    char equipeMandante[100];
    int golsEquipeMandante;
    char equipeVisitante[100];
    int golsEquipeVisitante;
};

struct Tabela
{
    char equipe[100];
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int saldoGols;
    int golsPro;
    int golsContra;
};

int retornarIndiceTime(struct Tabela *tabela, int n, char *time)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(tabela[i].equipe, time) == 0)
        {
            return i;
        }        
    }

    return -1;
}

void imprimirTabela(struct Tabela *tabela, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        printf("%s %d %d %d %d %d %d %d\n", tabela[i].equipe, tabela[i].pontos, tabela[i].vitorias, tabela[i].empates, tabela[i].derrotas, tabela[i].saldoGols, tabela[i].golsPro, tabela[i].golsContra);
    }
}

void calcularPartidas(struct Tabela *tabela, struct ResultadoPartida *partidas, int n)
{
    for (int i = 0; i < (n * (n-1)); i++)
    {
        int indiceTimeMandante = retornarIndiceTime(tabela, n, partidas[i].equipeMandante);
        int indiceTimeVisitante = retornarIndiceTime(tabela, n, partidas[i].equipeVisitante);

        if (partidas[i].golsEquipeMandante > partidas[i].golsEquipeVisitante)
        {
            tabela[indiceTimeMandante].pontos += 3;
            tabela[indiceTimeMandante].vitorias += 1;
            tabela[indiceTimeMandante].golsPro += partidas[i].golsEquipeMandante;
            tabela[indiceTimeMandante].golsContra += partidas[i].golsEquipeVisitante;
            tabela[indiceTimeMandante].saldoGols += (partidas[i].golsEquipeMandante - partidas[i].golsEquipeVisitante);

            tabela[indiceTimeVisitante].derrotas += 1;
            tabela[indiceTimeVisitante].golsPro += partidas[i].golsEquipeVisitante;
            tabela[indiceTimeVisitante].golsContra += partidas[i].golsEquipeMandante;
            tabela[indiceTimeVisitante].saldoGols += (partidas[i].golsEquipeVisitante - partidas[i].golsEquipeMandante);

        } else if (partidas[i].golsEquipeMandante < partidas[i].golsEquipeVisitante)
        {
            tabela[indiceTimeVisitante].pontos += 3;
            tabela[indiceTimeVisitante].vitorias += 1;
            tabela[indiceTimeVisitante].golsPro += partidas[i].golsEquipeVisitante;
            tabela[indiceTimeVisitante].golsContra += partidas[i].golsEquipeMandante;
            tabela[indiceTimeVisitante].saldoGols += (partidas[i].golsEquipeVisitante - partidas[i].golsEquipeMandante);

            tabela[indiceTimeMandante].derrotas += 1;
            tabela[indiceTimeMandante].golsPro += partidas[i].golsEquipeMandante;
            tabela[indiceTimeMandante].golsContra += partidas[i].golsEquipeVisitante;
            tabela[indiceTimeMandante].saldoGols += (partidas[i].golsEquipeMandante - partidas[i].golsEquipeVisitante);

        } else
        {
            tabela[indiceTimeMandante].pontos += 1;
            tabela[indiceTimeMandante].empates += 1;
            tabela[indiceTimeMandante].golsPro += partidas[i].golsEquipeMandante;
            tabela[indiceTimeMandante].golsContra += partidas[i].golsEquipeVisitante;
            tabela[indiceTimeMandante].saldoGols += (partidas[i].golsEquipeMandante - partidas[i].golsEquipeVisitante);
            
            tabela[indiceTimeVisitante].pontos += 1;
            tabela[indiceTimeVisitante].empates += 1;
            tabela[indiceTimeVisitante].golsPro += partidas[i].golsEquipeVisitante;
            tabela[indiceTimeVisitante].golsContra += partidas[i].golsEquipeMandante;
            tabela[indiceTimeVisitante].saldoGols += (partidas[i].golsEquipeVisitante - partidas[i].golsEquipeMandante);
        }
    }
}

void ordenarTabela(struct Tabela *tabela, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (tabela[j].vitorias > tabela[j+1].vitorias)
            {
                struct Tabela temp = tabela[j];
                tabela[j] = tabela[j+1];
                tabela[j+1] = temp;
            } else if (tabela[j].vitorias == tabela[j+1].vitorias)
            {
                if (tabela[j].saldoGols > tabela[j+1].saldoGols)
                {
                    struct Tabela temp = tabela[j];
                    tabela[j] = tabela[j+1];
                    tabela[j+1] = temp;
                } else if (tabela[j].saldoGols == tabela[j+1].saldoGols)
                {
                    if (tabela[j].golsPro > tabela[j+1].golsPro)
                    {
                        struct Tabela temp = tabela[j];
                        tabela[j] = tabela[j+1];
                        tabela[j+1] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Tabela *tabela;
    tabela = (struct Tabela *) malloc(n * sizeof(struct Tabela)); 
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tabela[i].equipe);
    }

    struct ResultadoPartida *partidas;
    partidas = (struct ResultadoPartida *) malloc((n*(n-1)) * sizeof(struct ResultadoPartida)); 
    for (int i = 0; i < n*(n-1); i++)
    {
        scanf("%s %d x %d %s", partidas[i].equipeMandante, &partidas[i].golsEquipeMandante, &partidas[i].golsEquipeVisitante, partidas[i].equipeVisitante);
    }

    calcularPartidas(tabela, partidas, n);
    ordenarTabela(tabela, n);

    printf("CAMPEAO: %s\n", tabela[n-1].equipe);
    printf("VICE-CAMPEAO: %s\n", tabela[n-2].equipe);
    printf("REBAIXADOS: %s, %s, %s e %s\n", tabela[0].equipe, tabela[1].equipe, tabela[2].equipe, tabela[3].equipe);
    printf("TABELA FINAL:\n");
    imprimirTabela(tabela, n);
    
    free(partidas);
    free(tabela);
    return 0;
}