#pragma once
//#include <iostream>
#include "string.h"


class Poder
{
private:
	//char nome[20];
	string nome;
	int dano;
	int custo;
	int cura;
	//char descricao[50];
	string descricao;

public:
	Poder(string = "sem poder", int d = -1, int c = -1,
		int h=-1,string="sem descricao");
	~Poder();
	
	void setNome(string n);
	string getNome();
	void setDano(int d);
	int getDano();
	void setCusto(int c);
	int getCusto();
	void setCura(int h);
	int getCura();
	void setDescricao(string n);
	string getDescricao();

	void printAll();
};

