#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/handle_file.h"
#include "inc/escola.h"

typedef struct t_header
{
	int topoPilha;
	char status;
} HEADER;

int file_read_csv_write_binary(const char *nome_arquivo, const char *binary_file)
{
	if(nome_arquivo != NULL)
	{
		int codigo = 0, escola_size = 0, cidade_size = 0, prestadora_size = 0, total_bytes = 0;
		char byte_padding = 0x00, prestadora[10], data[11], escola[50], cidade[70], uf[3];
		HEADER binary_h;
		FILE *csv = NULL, *binary = NULL;
		binary_h.topoPilha = -1;
		binary_h.status = '0';
		csv = fopen(nome_arquivo, "r");
		binary = fopen(binary_file, "wb");
		fwrite(&binary_h.status, sizeof(binary_h.status), 1, binary);
		fwrite(&binary_h.topoPilha, sizeof(binary_h.topoPilha), 1, binary);
		while(1)
		{
			if(feof(csv) != 0)
			{
				break;
			}
			else
			{
				fscanf(csv, "%10[^;];%10[^;]; %d ;%50[^;];%70[^;];%s\n", prestadora, data, &codigo, escola, cidade, uf);
				escola_size = strlen(escola);
				cidade_size = strlen(cidade);
				prestadora_size = strlen(prestadora);
				fwrite(&codigo, sizeof(codigo), 1, binary);
				fwrite(&data, strlen(data), 1, binary);
				fwrite(&uf, strlen(uf), 1, binary);
				fwrite(&escola_size, sizeof(escola_size), 1, binary);
				fwrite(&escola, escola_size, 1, binary);
				fwrite(&cidade_size, sizeof(cidade_size), 1, binary);
				fwrite(&cidade, cidade_size, 1, binary);
				fwrite(&prestadora_size, sizeof(prestadora_size), 1, binary);
				fwrite(&prestadora, prestadora_size, 1, binary);
				total_bytes = escola_size + cidade_size + prestadora_size + sizeof(codigo) + strlen(uf) + strlen(data) + 12;
				if(total_bytes < 87)
				{
					fwrite(&byte_padding, (87 - total_bytes), 1, binary);
				}
			}
		}
		rewind(binary);
		binary_h.status = '1';
		fwrite(&binary_h.status, sizeof(binary_h.status), 1, binary);
		fclose(binary);
		fclose(csv);
	}
	else
	{
		printf("Falha no carregamento do arquivo\n");
	}
}
