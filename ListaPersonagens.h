#pragma once
#include "ElPersonagem.h"

class ListaPersonagens
{
private:
	ElPersonagem* pInicio;
	ElPersonagem* pAtual;
	//Principal* pPrincipal;
public:
	ListaPersonagens();
	~ListaPersonagens();

	Personagem* localiza(const char* n);
	void incluirPer(Personagem* pp);
	void listar();
	void listarNomes();

	bool vazia();

	void Gravar();
	void Recuperar();

	void limpaLista();
};

