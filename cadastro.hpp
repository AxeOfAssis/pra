#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
class Data {
public:
	int dia = 0;
	int mes = 0;
	int ano = 0;
};

class Cadastro
{
public:
	Cadastro();
	~Cadastro();

	char nome_paciente[50] = "";
	char nome_medico[50] = "";
	int codigo_operacao = 0; //1 - 100
	int codigo_controle = 0; //1 - x
	char sintomas[50] = "";
	Data data_internacao;
};

class Auxiliar
{
public:
	Auxiliar();
	~Auxiliar();
	char *gerar_string_aleatoria();
	int arquivo_vazio(FILE *arquivo);
	void procurar_registro(std::vector<Cadastro> v,int codigo);
	Cadastro aleatorio(int chave);

private:

};

