#include <vector>
#include <iostream>
#include <string>
#include "cadastro.hpp"
#include <time.h>

using namespace std;
int main() {

	srand((unsigned)(time(NULL)));
	long int qtd = 0;
	//Criar classes
	Cadastro registro,registro_leitura;
	Auxiliar aux;
	//Criar vetores
	std::vector<Cadastro> lista;
	std::vector<Cadastro>::const_iterator i;
	//Criar arquivo;
	FILE *arquivo;
	arquivo = fopen("dados.bin", "a+b");

	if (aux.arquivo_vazio(arquivo) == 1) {
		registro.codigo_controle = 0;
	}

	else {
		fseek(arquivo, 0,SEEK_END);
		qtd = ftell(arquivo) / sizeof(Cadastro);
		registro.codigo_controle = qtd;
		
		rewind(arquivo);
		while (!feof(arquivo)) {
			fread(&registro_leitura, sizeof(Cadastro), 1, arquivo);			
			lista.push_back(registro_leitura);
			
		}
	}	
	////////////////////////////////////////////////////////////////
	/**/
	int quantidade = 0;
	cout << "Digite a quantidade de registros a serem adicionados" << endl;
	cin >> quantidade;
	

	for (int x = 0; x < quantidade; x++) {
		registro = aux.aleatorio(registro.codigo_controle);
		fwrite(&registro, sizeof(Cadastro), 1, arquivo);
		lista.push_back(registro);
	}
	
	cout << "Dados" << endl;
	
	rewind(arquivo);
	/*
	for (i = lista.begin(); i < lista.end(); i++) {
		fread(&registro_leitura,sizeof(Cadastro), 1, arquivo);
		cout << registro_leitura.codigo_controle << endl;
	}*/

	aux.procurar_registro(lista, 44);
	

	fclose(arquivo);
	system("pause");
	return 0;
}