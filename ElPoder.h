#pragma once
#include "Poder.h"

class ElPoder
{
private:
	ElPoder* pAnte;
	ElPoder* pProx;
	Poder* pPod;
public:
	ElPoder(Poder* ppod = NULL);
	~ElPoder();

	void setpAnte(ElPoder* pa);
	ElPoder* getpAnte();
	void setpProx(ElPoder* pp);
	ElPoder* getpProx();

	void setpPod(Poder* ppod);
	Poder* getpPod();
};



