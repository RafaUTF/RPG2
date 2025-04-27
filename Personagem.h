#pragma once
#include "ListaPoderes.h"
//#include "string.h"

class Personagem
{
private:
	string nome;
	int vida;
	int energia;
	int destreza;
	ListaPoderes habilidades;

public:
	Personagem(const char* n="noname",int v=-1, int e=-1, int d=-1);
	~Personagem();

	void setNome(const char* n);
	string getNome();
	void setVida(int v);
	int getVida();
	void setEner(int e);
	int getEner();
	void setDex(int d);
	int getDex();

	ListaPoderes* getLista();

	Poder* localizaNomeLista(const char* n);

	void printAll();
};

