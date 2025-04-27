#include "ElPersonagem.h"
ElPersonagem::ElPersonagem(Personagem* pper){
	pAnte = NULL;
	pProx = NULL;
	pPer = pper;
}
ElPersonagem::~ElPersonagem() {
	pAnte = NULL;
	pProx = NULL;
	pPer = NULL;
}

void ElPersonagem::setpAnte(ElPersonagem* pa) { pAnte = pa; }
ElPersonagem* ElPersonagem::getpAnte() { return pAnte; }
void ElPersonagem::setpProx(ElPersonagem* pp) { pProx = pp; }
ElPersonagem* ElPersonagem::getpProx() { return pProx; }

void ElPersonagem::setpPer(Personagem* pper) { pPer = pper; }
Personagem* ElPersonagem::getpPer() { return pPer; }

void  ElPersonagem::printNome() {
	cout << pPer->getNome().getpStr() << endl;
}