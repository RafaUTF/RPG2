#include "Personagem.h"
#include <string.h>
Personagem::Personagem(const char* n, int v, int e, int d):
vida(v),energia(e),destreza(d),nome(n){}
Personagem::~Personagem() {}

void Personagem::setNome(const char* n) { nome.setStr(n); }
string Personagem::getNome() { return nome; }
void Personagem::setVida(int v) { vida = v; }
int Personagem::getVida() { return vida; }
void Personagem::setEner(int e) { energia = e; }
int Personagem::getEner() { return energia; }
void Personagem::setDex(int d) { destreza = d; }
int Personagem::getDex() { return destreza; }

void Personagem::printAll() {
	cout << "nome: " << nome.getpStr() << endl <<
		"vida: " << vida << endl <<
		"energia: " << energia <<endl<<
		"destreza: " << destreza << endl;
}

ListaPoderes* Personagem::getLista() { return &habilidades; }