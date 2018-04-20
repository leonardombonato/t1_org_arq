/*
	Nome: Andre Luis Storino Junior, N USP: 9293668
	Nome: Francisco, Nº USP:
	Nome: Leonardo, Nº USP:
	Nome: Paulo Ricardo J. Miranda, N USP: 10133456
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inc/escola.h"
#include "inc/handle_file.h"

int main(int argc, char *argv[])
{
	char op;	//Codigo da operacao a ser realizada
	
	if(argc < 2 || strlen(argv[1]) != 1 || (argv[1][0] >= '0' && argv[1][0] <= '9')) {
		printf("Erro na entrada de parametros para o programa.\n");
		printf("Uso: ./programaTrab1 CodOp[0-9] +parametros dependentes da operação\n");
		printf("Verifique a documentacao externa para a especificacao de cada operacao\n");
		exit(EXIT_FAILURE);
	}
	else op = argv[1][0];
	
	switch (op){
		case '1':
			if(argc != 3){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 1 'arquivo.csv'\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '2':
			if(argc != 2){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 2\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '3':
			if(argc != 4){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 3 'NomeDoCampo' valor\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '4':
			if(argc != 3){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 4 RRN\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '5':
			if(argc != 3){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 5 RRN\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '6':
			if(argc != 8){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 6 valorCampo1 valorCampo2 valorCampo3 valorCampo4 valorCampo5 valorCampo6\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '7':
			if(argc != 9){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 7 RRN valorCampo1 valorCampo2 valorCampo3 valorCampo4 valorCampo5 valorCampo6\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '8':
			if(argc != 2){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 8\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		case '9':
			if(argc != 2){
				printf("Erro na entrada de parametros para o programa.\n");
				printf("Uso: ./programaTrab1 9\n");
				exit(EXIT_FAILURE);
			}
			else{
				
			}
			break;
		default:
			exit(EXIT_FAILURE);
			break;
	}
	
	return 0;
}
