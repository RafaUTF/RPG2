#pragma once
#include "Personagem.h"

class ElPersonagem
{
private:
	ElPersonagem* pAnte;
	ElPersonagem* pProx;
	Personagem* pPer;
public:
	ElPersonagem(Personagem* pper=NULL);
	~ElPersonagem();

	void setpAnte(ElPersonagem* pa);
	ElPersonagem* getpAnte();
	void setpProx(ElPersonagem* pp);
	ElPersonagem* getpProx();

	void setpPer(Personagem* pper);
	Personagem* getpPer();

	void printNome();
};

