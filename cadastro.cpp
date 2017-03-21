#include "cadastro.hpp"
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


Auxiliar::Auxiliar()
{
}

Auxiliar::~Auxiliar()
{
}

Cadastro::Cadastro() {

}

Cadastro::~Cadastro() {

}

char *Auxiliar::gerar_string_aleatoria() {
	char valores[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *ret_val = (char*)malloc(sizeof(char) * 50);
	
	for (int i = 0; i < 49; i++)
	{
		ret_val[i] = 1 + valores[rand() % 49];
	}
	
	ret_val[49] = '\0';

	return ret_val;
}

int Auxiliar::arquivo_vazio(FILE *arquivo)
{
	fseek(arquivo, 0, SEEK_END);
	if (ftell(arquivo) == 0) return 1;
	return 0;
}

void Auxiliar::procurar_registro(std::vector<Cadastro> v,int codigo)
{
	std::vector<Cadastro>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
	{
		if (it->codigo_controle == codigo) {
			std::cout << it->data_internacao.dia << "/"<< it->data_internacao.mes <<"/"
			<< it->data_internacao.ano << std::endl;
			return;
		}
	}
	std::cout << "Registro não encontrado" << std::endl;
}

Cadastro Auxiliar::aleatorio(int chave)
{
	Cadastro registro_aleatorio;
	
	registro_aleatorio.codigo_controle = chave + 1;
	registro_aleatorio.codigo_operacao = 1 + rand() % 100;
	registro_aleatorio.data_internacao.ano = 1980 + rand() % 37;
	registro_aleatorio.data_internacao.mes = 1 + rand() % 12;
	registro_aleatorio.data_internacao.dia = 1 + rand() % 30;


	strcpy(registro_aleatorio.nome_medico, Auxiliar::gerar_string_aleatoria());
	strcpy(registro_aleatorio.sintomas, Auxiliar::gerar_string_aleatoria());
	strcpy(registro_aleatorio.nome_paciente, Auxiliar::gerar_string_aleatoria());
	
	return registro_aleatorio;	
}
