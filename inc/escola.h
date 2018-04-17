#ifndef ESCOLA_H
    #define ESCOLA_H
        typedef struct t_escola ESCOLA;

        ESCOLA *escola_create();
        void escola_set_codigo(ESCOLA *e, int cod);
        void escola_set_data_ativacao(ESCOLA *e, const char *data);
        void escola_set_uf(ESCOLA *e, const char *uf);
        void escola_set_nome_escola(ESCOLA *e, const char *nome);
        void escola_set_municipio(ESCOLA *e, const char *municipio);
        void escola_set_prestadora(ESCOLA *e, const char *prestadora);
        void escola_print(ESCOLA *e);
        void escola_delete(ESCOLA **e);
#endif
