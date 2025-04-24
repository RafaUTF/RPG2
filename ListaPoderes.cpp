#include "ListaPoderes.h"

ListaPoderes::ListaPoderes() {
	pInicio = NULL;
	pAtual = NULL;
	pPer = NULL;
}
ListaPoderes::~ListaPoderes() {
	pInicio = NULL;
	pAtual = NULL;
	pPer = NULL;
}
Poder* ListaPoderes::localiza(const char* n) {
	for (ElPoder* pex = pInicio;pex != NULL;pex = pex->getpProx())
		if (pex->getpPod()->getNome() == n)
			return pex->getpPod();
	return NULL;
}
void ListaPoderes::novoPod(Poder * pp) {
	ElPoder* pex = new ElPoder;
	if (pInicio == NULL) {
		pInicio = pex;
		pAtual = pex;
	}
	else {
		pex->setpAnte(pAtual);
		pAtual->setpProx(pex);
		pAtual = pex;
	}
	pex->setpPod(pp);
	cout << "poder " << pp->getNome().getpStr() << " incluido com sucesso!" << endl;
}
void ListaPoderes::listar() {
	for (ElPoder* pex = pInicio;pex != NULL;pex = pex->getpProx())
		pex->getpPod()->printAll();
}
void ListaPoderes::listarNomes() {
	for (ElPoder* pex = pInicio;pex != NULL;pex = pex->getpProx())
		cout << pex->getpPod()->getNome().getpStr() << endl;
}