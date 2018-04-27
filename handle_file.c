#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/handle_file.h"

// Constantes de pré-processamento
#define IN_DISK_REG_SIZE 87
#define IN_DISK_HEADER_SIZE 5

typedef struct t_header
{
	int topoPilha;
	char status;
} HEADER;

void file_read_csv_write_binary(const char *nome_arq_dados, const char *nome_arq_binario)
{
	if(nome_arq_dados != NULL)
	{
		int codigoINEP = 0, escola_size = 0, cidade_size = 0, prestadora_size = 0, total_bytes = 0;
		char byte_padding = '0', prestadora[10], data[11], escola[50], cidade[70], uf[3], line[300], *tokken = NULL;
		HEADER binario_h;
		FILE *csv = NULL, *binario = NULL;
		binario_h.topoPilha = -1;
		binario_h.status = '0';
		csv = fopen(nome_arq_dados, "r");
		binario = fopen(nome_arq_binario, "wb");
		fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
		fwrite(&binario_h.topoPilha, sizeof(binario_h.topoPilha), 1, binario);
		while(1)
		{
			strcpy(uf, "00");
			strcpy(data, "0000000000");
			strcpy(escola, "");
			strcpy(cidade, "");
			strcpy(prestadora, "");
			fgets(line, sizeof(line), csv);
			tokken = line;
			if(feof(csv) == 0) // Se o fim do arquivo nao foi setado
			{
				if(tokken[0] != ';')
				{
					sscanf(tokken, " %10[^;]", prestadora);
					printf("%s ", prestadora);
					prestadora_size = strlen(prestadora);
					tokken = strchr(tokken, ';');
				}
				else
				{
					prestadora_size = 0;
				}
				++tokken;
				if(tokken[0] != ';')
				{
					sscanf(tokken, " %10[^;]", data);
					tokken = strchr(tokken, ';');
				}
				printf("%s ", data);
				++tokken;
				sscanf(tokken, "%d", &codigoINEP);
				printf("%d ", codigoINEP);
				tokken = strchr(tokken, ';');
				++tokken;
				if(tokken[0] != ';')
				{
					sscanf(tokken, " %50[^;\n]", escola);
					printf("%s ", escola);
					escola_size = strlen(escola);
					tokken = strchr(tokken, ';');
				}
				else
				{
					escola_size = 0;
				}
				++tokken;
				if(tokken[0] != ';')
				{
					sscanf(tokken, " %70[^;\n]", cidade);
					printf("%s ", cidade);
					cidade_size = strlen(cidade);
					tokken = strchr(tokken, ';');
				}
				else
				{
					cidade_size = 0;
				}
				++tokken;
				if(tokken[0] != ';')
				{
					sscanf(tokken, " %s", uf);
					printf("%s\n", uf);
				}
				fwrite(&codigoINEP, sizeof(codigoINEP), 1, binario);
				fwrite(data, strlen(data), 1, binario);
				fwrite(uf, strlen(uf), 1, binario);
				fwrite(&escola_size, sizeof(int), 1, binario);
				if(escola_size > 0)
				{
					fwrite(escola, escola_size, 1, binario);
				}
				fwrite(&cidade_size, sizeof(int), 1, binario);
				if(cidade_size > 0)
				{
					fwrite(cidade, cidade_size, 1, binario);
				}
				fwrite(&prestadora_size, sizeof(int), 1, binario);
				if(prestadora_size > 0)
				{
					fwrite(prestadora, prestadora_size, 1, binario);
				}
				total_bytes = 28 + escola_size + prestadora_size + cidade_size;
				if(total_bytes < IN_DISK_REG_SIZE)
				{
					fwrite(&byte_padding, (IN_DISK_REG_SIZE - total_bytes), 1, binario);
				}
			}
			else
			{
				break;
			}
		}
		rewind(binario);
		binario_h.status = '1';
		fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
		fclose(binario);
		fclose(csv);
		printf("Arquivo carregado.\n");
	}
	else
	{
		printf("Falha no carregamento do arquivo.\n");
	}
}

ESCOLA *file_read_all_binary(const char *nome_arq_binario)
{
	ESCOLA *e = NULL;
	if(nome_arq_binario != NULL)
	{

	}
	return e;
}

ESCOLA *file_read_binary_rrn(const char *nome_arq_binario, const int rrn)
{
	ESCOLA *e = NULL;
	if(nome_arq_binario != NULL)
	{
		FILE *binario = NULL;
		HEADER binario_h;
		binario_h.status = '0';
		int campos_variaveis_size = 0, codigoINEP = 0;
		char prestadora[10], data[11], escola[50], cidade[70], uf[3];
		memset(prestadora, 0x00, sizeof(prestadora));
		memset(prestadora, 0x00, sizeof(escola));
		memset(prestadora, 0x00, sizeof(cidade));
		binario = fopen(nome_arq_binario, "r+b");
		if(binario != NULL)
		{
			fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
			fseek(binario, (IN_DISK_REG_SIZE * (rrn - 1)) + (IN_DISK_HEADER_SIZE - 1), SEEK_CUR);
			if(fread(&codigoINEP, sizeof(codigoINEP), 1, binario) > 0)
			{
				if(codigoINEP != -1)
				{
					printf("%d ", codigoINEP);
					fread(data, (sizeof(data) - 1), 1, binario);
					if(data[0] != '0')
					{
						printf("%s ", data);
					}
					fread(uf, (sizeof(uf) - 1), 1, binario);
					if(uf[0] != '0')
					{
						printf("%s ", uf);
					}
					fread(&campos_variaveis_size, sizeof(int), 1, binario);
					printf("%d ", campos_variaveis_size);
					if(campos_variaveis_size > 0)
					{
						fread(escola, campos_variaveis_size, 1, binario);
						printf("%s ", escola);
					}
					fread(&campos_variaveis_size, sizeof(int), 1, binario);
					printf("%d ", campos_variaveis_size);
					if(campos_variaveis_size > 0)
					{
						fread(cidade, campos_variaveis_size, 1, binario);
						printf("%s ", cidade);
					}
					fread(&campos_variaveis_size, sizeof(int), 1, binario);
					printf("%d ", campos_variaveis_size);
					if(campos_variaveis_size > 0)
					{
						fread(prestadora, campos_variaveis_size, 1, binario);
						printf("%s", prestadora);
					}
					printf("\n");
				}
				else
				{
					printf("Registro inexistente.\n");
				}
			}
			else
			{
				printf("Registro inexistente.\n");
			}
			rewind(binario);
			binario_h.status = '1';
			fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
			fclose(binario);
		}
		else
		{
			printf("Falha no processamento do arquivo.\n");
		}
	}
	else
	{
		printf("Falha no processamento do arquivo.\n");
	}
	return e;
}

void file_delete_record(const char *nome_arq_binario, int rrn)
{
	if(nome_arq_binario != NULL)
	{
		HEADER binario_h;
		FILE *binario = NULL;
		int codigoINEP = 0, marca = -1;
		binario = fopen(nome_arq_binario, "r+b");
		if(binario != NULL)
		{
			binario_h.status = '0';
			fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
			fread(&binario_h.topoPilha, sizeof(binario_h.topoPilha), 1, binario);
			fseek(binario, (rrn - 1) * IN_DISK_REG_SIZE, SEEK_CUR);
			if(fread(&codigoINEP, sizeof(codigoINEP), 1, binario) > 0)
			{
				fseek(binario, -sizeof(codigoINEP), SEEK_CUR);
				fwrite(&marca, sizeof(marca), 1, binario);
				fwrite(&binario_h.topoPilha, sizeof(binario_h.topoPilha), 1, binario);
				binario_h.topoPilha = rrn;
			}
			else
			{
				printf("Registro inexistente.\n");
			}
			binario_h.status = '1';
			rewind(binario);
			fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
			fwrite(&binario_h.topoPilha, sizeof(binario_h.topoPilha), 1, binario);
			fclose(binario);
		}
		else
		{
			printf("Falha no processamento do arquivo.\n");
		}
	}
	else
	{
		printf("Falha no processamento do arquivo.\n");
	}
}

void file_print_stack(const char *nome_arq_binario)
{
	if(nome_arq_binario != NULL)
	{
		HEADER binario_h;
		FILE *binario = NULL;
		int tmp_pilha = -1;
		char marca = 0x00;
		binario = fopen(nome_arq_binario, "r+b");
		if(binario != NULL)
		{
			binario_h.status = '0';
			fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
			fread(&binario_h.topoPilha, sizeof(binario_h.topoPilha), 1, binario);
			tmp_pilha = binario_h.topoPilha;
			if(tmp_pilha != -1)
			{
				while(tmp_pilha != -1)
				{
					printf("%d ", tmp_pilha);
					fseek(binario, ((tmp_pilha - 1) * IN_DISK_REG_SIZE) + IN_DISK_HEADER_SIZE, SEEK_SET);
					fread(&marca, sizeof(marca), 1, binario);
					fread(&tmp_pilha, sizeof(tmp_pilha), 1, binario);
				}
			}
			else
			{
				printf("Pilha vazia.");
			}
			printf("\n");
			binario_h.status = '1';
			rewind(binario);
			fwrite(&binario_h.status, sizeof(binario_h.status), 1, binario);
			fwrite(&binario_h.topoPilha, sizeof(binario_h.topoPilha), 1, binario);
			fclose(binario);
		}
		else
		{
			printf("Falha no processamento do arquivo.\n");
		}
	}
	else
	{
		printf("Falha no processamento do arquivo.\n");
	}
}
