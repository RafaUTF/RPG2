#pragma once
#include "ElPoder.h"
class Personagem;
class ListaPoderes
{
private:
	ElPoder* pInicio;
	ElPoder* pAtual;
	Personagem* pPer;
public:
	ListaPoderes();
	~ListaPoderes();
	Poder* localiza(const char* n);
	void novoPod(Poder* pp);
	void listar();
	void listarNomes();

	bool vazia();

	void Gravar();
	void Recuperar();

};

