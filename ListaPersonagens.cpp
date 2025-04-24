#include "ListaPersonagens.h"
#include <string.h>
ListaPersonagens::ListaPersonagens() {
	pInicio = NULL;
	pAtual = NULL;
}
ListaPersonagens::~ListaPersonagens() {

	pInicio = NULL;
	pAtual = NULL;
}

void ListaPersonagens::novoPer(Personagem* pp) {
	/*
	ElPersonagem* pex;
	for (pex = pInicio;pex != NULL;pex = pex->getpProx())
		if (strcmp(pex->getpPer()->getNome(),n)==0) {
			cout << "personagem ja cadastrado" << endl;
			return;
		}
	*/
	ElPersonagem* pex = new ElPersonagem;
	if (pInicio == NULL) {
		pInicio = pex;
		pAtual = pex;
	}
	else {
		pex->setpAnte(pAtual);
		pAtual->setpProx(pex);
		pAtual = pex;
	}
	pex->setpPer(pp);
	cout << "personagem " << pp->getNome().getpStr() << " incluido com sucesso!" << endl;
}

void ListaPersonagens::listar() {
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx())
		pex->getpPer()->printAll();
}

void ListaPersonagens::listarNomes() {
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx())
		cout << pex->getpPer()->getNome().getpStr() << endl;
}

Personagem* ListaPersonagens::localiza(const char* n) {
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx())
		if(pex->getpPer()->getNome()==n)
			return pex->getpPer();
	return NULL;

}
