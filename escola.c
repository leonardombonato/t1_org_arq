#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/escola.h"

struct t_escola
{
    int codINEP;
    char dataAtiv[11], uf[2], *nomeEscola, *municipio, *prestadora;
};

ESCOLA *escola_create()
{
    ESCOLA *new = NULL;
    new = (ESCOLA *) malloc(sizeof(ESCOLA));
    if(new != NULL)
    {
        new->codINEP;
        new->nomeEscola = NULL;
        new->municipio = NULL;
        new->prestadora = NULL;
        memset(new->dataAtiv, 0, sizeof(new->dataAtiv));
        memset(new->uf, 0, sizeof(new->uf));
    }

    return new;
}

void escola_set_codigo(ESCOLA *e, int cod)
{
    if(e != NULL)
    {
        e->codINEP = cod;
    }
}

void escola_set_data_ativacao(ESCOLA *e, const char *data)
{
    if(e != NULL)
    {
        strcpy(e->dataAtiv, data);
    }
}

void escola_set_uf(ESCOLA *e, const char *uf)
{
    if(e != NULL)
    {
        strcpy(e->uf, uf);
    }
}

void escola_set_nome_escola(ESCOLA *e, const char *nome)
{
    if(e != NULL)
    {
        e->nomeEscola = (char *) malloc(strlen(nome) + 1);
        strcpy(e->nomeEscola, nome);
    }
}

void escola_set_municipio(ESCOLA *e, const char *municipio)
{
    if(e != NULL)
    {
        e->municipio = (char *) malloc(strlen(municipio) + 1);
        strcpy(e->municipio, municipio);
    }
}

void escola_set_prestadora(ESCOLA *e, const char *prestadora)
{
    if(e != NULL)
    {
        e->prestadora = (char *) malloc(strlen(prestadora) + 1);
        strcpy(e->prestadora, prestadora);
    }
}

void escola_print(ESCOLA *e)
{
    if(e != NULL)
    {
        printf("%d %s %s %d %s %d %s %d %s\n", e->codINEP, e->dataAtiv, e->uf, strlen(e->nomeEscola), e->nomeEscola, strlen(e->municipio), e->municipio, strlen(e->prestadora), e->prestadora);
    }
}

void escola_delete(ESCOLA **e)
{
    if((*e) != NULL)
    {
        free((*e)->nomeEscola);
        free((*e)->municipio);
        free((*e)->prestadora);
        free((*e));
        (*e) = NULL;
    }
}
