#include "Poder.h"

Poder::Poder(string n, int d, int c, int h, string des):
dano(d),custo(c),cura(h),nome(n),descricao(des){}

Poder::~Poder(){}
void Poder::setNome(string n){ nome.setStr(n);}
string Poder::getNome() { return nome; }
void Poder::setDano(int d) { dano = d; }
int Poder::getDano() { return dano; }
void Poder::setCusto(int c) { custo = c; }
int Poder::getCusto() { return custo; }
void Poder::setCura(int h) { cura = h; }
int Poder::getCura() { return cura; }
void Poder::setDescricao(string n) { descricao.setStr(n); }
string Poder::getDescricao() { return descricao; }

void Poder::printAll(){
	cout << "nome: " << nome.getpStr() << endl <<
		"dano: " << dano << endl <<
		"cura: " << cura << endl <<
		"custo: " << custo << endl <<
		"DESCRICAO: " <<endl << descricao.getpStr() << endl;
}