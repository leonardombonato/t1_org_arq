#ifndef HANDLE_FILE_H
    #define HANDLE_FILE_H
        #include "escola.h"

        void file_read_csv_write_binary(const char *nome_arq_dados, const char *nome_arq_binario); // funcao para ler do csv e escrever no arquivo em binario
        void file_delete_record(const char *nome_arq_binario, int rrn); // funcao para remover um registro dado seu RRN
        void file_print_stack(const char *nome_arq_binario); // funcao para imprimir a pilha
        ESCOLA *file_read_binary_rrn(const char *nome_arq_binario, const int rrn); // funcao para buscar um registro dado seu RRN
        ESCOLA *file_read_all_binary(const char *nome_arq_binario); // funcao para recuperar todos os registros do arquivo binario
#endif
