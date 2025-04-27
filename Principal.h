#pragma once
//#include "Personagem.h"
#include "ListaPersonagens.h"
//#include "ListaPoderes.h"
//#include "Poder.h"
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;

class Principal
{
private:
	ListaPersonagens Lpers;
	ListaPoderes Lpods;
public:
	//inicializacoes
	Principal();

	void executar();
	void Menu();
	void MenuCad();
	void MenuExe();

	void CadPersonagens();
	void NovoPersonagem();
	void EditarPersonagem();

	void CadPoderes();
	void NovoPoder(Personagem* pp);
	void NovoPoder();
	void EditarPoder();


	void MenuStatusPer(Personagem* pp);
	void MenuStatusPod(Poder* pp);
	~Principal();

	void MenuGravar();
	void MenuRecuperar();

	void GravarTudo();
	void GravarPer();
	void GravarPod();

	void RecuperarTudo();
	void RecuperarPer();
	void RecuperarPod();
};

