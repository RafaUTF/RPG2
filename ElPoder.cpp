#include "ElPoder.h"

ElPoder::ElPoder(Poder* ppod) {
	pAnte = NULL;
	pProx = NULL;
	pPod = ppod;
}
ElPoder::~ElPoder() {
	pAnte = NULL;
	pProx = NULL;
	pPod = NULL;
}

void ElPoder::setpAnte(ElPoder* pa) { pAnte = pa; }
ElPoder* ElPoder::getpAnte() { return pAnte; }
void ElPoder::setpProx(ElPoder* pp) { pProx = pp; }
ElPoder* ElPoder::getpProx() { return pProx; }

void ElPoder::setpPod(Poder* ppod) { pPod = ppod; }
Poder* ElPoder::getpPod() { return pPod; }
