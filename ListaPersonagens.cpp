#include "ListaPersonagens.h"

ListaPersonagens::ListaPersonagens() {
	pInicio = NULL;
	pAtual = NULL;
}
ListaPersonagens::~ListaPersonagens() {
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx())
		pex->getpPer()->getNome().destroi();
	pInicio = NULL;
	pAtual = NULL;
}

void ListaPersonagens::incluirPer(Personagem* pp) {
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
	cout << "personagem " << pex->getpPer()->getNome().getpStr() << " incluido com sucesso!" << endl;
}

void ListaPersonagens::listar() {
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx())
		pex->getpPer()->printAll();
}

void ListaPersonagens::listarNomes() {
	cout << "Personagens: " << endl;
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx()) {
		cout << pex->getpPer()->getNome().getpStr() << endl;
		//pex->getpPer()->getNome().print();
		//pex->printNome();
	}
}

Personagem* ListaPersonagens::localiza(const char* n) {
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx())
		if(pex->getpPer()->getNome()==n)
			return pex->getpPer();
	return NULL;

}

bool ListaPersonagens::vazia() {
	return pInicio == NULL ? true : false;
}

using namespace std;

void ListaPersonagens::Gravar(){
	ofsteam GravadorPer("Personagens.dat", ios::out);
	if (!GravadorPer) {
		cerr << "ARQUIVO PERSONAGENS NAO PODE SER ABERTO PARA GRAVAR" << endl;
		fflush(stdin);
		getchar();
		return;
	}
	Personagem* px=NULL;
	for (ElPersonagem* pex = pInicio;pex != NULL;pex = pex->getpProx()) {
		px = pex->getpPer();
		GravadorPer << px->getNome().getpStr() << ' ' << 
			px->getVida() << ' ' <<
			px->getEner() << ' ' <<
			px->getDex() << endl;
	}
	GravadorPer.close();
}

void ListaPersonagens::Recuperar() {
	ifsteam RecuperadorPer("Personagens.dat", ios::in);
	if (!RecuperadorPer) {
		cerr << "ARQUIVO PERSONAGENS NAO PODE SER ABERTO PARA RECUPERAR" << endl;
		fflush(stdin);
		getchar();
		return;
	}
	limpaLista();
	Personagem* px = NULL;
	int v, e, d;
	char nome[20];
	string null;//gambiarra
	while (RecuperadorPer >> nome >> v >> e >> d) {
		if (null != nome) {
			px = new Personagem;
			px->setNome(nome);
			px->setVida(v);
			px->setEner(e);
			px->setDex(d);
			incluirPer(px);
		}
	}
	RecuperadorPer.close();
}



void ListaPersonagens::limpaLista() {
	for (ElPersonagem* pex = pInicio, *lixo=NULL;pex != NULL;lixo=pex, pex = pex->getpProx()) {
		
	}

	pInicio = NULL;
	pAtual = NULL;
}

void ListaPersonagens::limpaLista() {
	if (pInicio == NULL)
		return;
	ElPersonagem* lixo = pInicio, * pex = lixo->getpProx();
	for (;pex != NULL;lixo = pex, pex = pex->getpProx()) {
		delete lixo;
	}
	delete lixo;
	pInicio = NULL;
	pAtual = NULL;
}
