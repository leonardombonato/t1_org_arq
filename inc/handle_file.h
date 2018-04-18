#ifndef HANDLE_FILE_H
    #define HANDLE_FILE_H
        #include "escola.h"

        void file_read_csv_write_binary(const char *nome_arq_dados, const char *nome_arq_binario);
        void file_delete_record(const char *nome_arq_binario, int rrn);
        void file_print_stack(const char *nome_arq_binario);
        ESCOLA *file_read_binary_rrn(const char *nome_arq_binario, const int rrn);
        ESCOLA *file_read_all_binary(const char *nome_arq_binario);
#endif
