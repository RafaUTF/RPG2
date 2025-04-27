#include "Principal.h"
//#include "Personagem.h"

Principal::Principal() {
}
Principal::~Principal() {
}
void Principal::executar() {
	Menu();
}


void Principal::Menu() {
	int a = -1;
	while (a != 5) {
		system("cls");
		cout << "RPG2" << endl <<endl<<
			"1. Cadastrar" << endl <<
			"2. Executar" << endl <<
			"3. Gravar" << endl <<
			"4. Recuperar" << endl <<
			"5. Sair" << endl<<endl;
		cin >> a;
		switch (a) {
		case 1: { MenuCad(); }break;
		case 2: { MenuExe(); }break;
		case 3: { MenuGravar(); }break;
		case 4: { MenuRecuperar(); }break;
		case 5: { cout << "FIM" << endl; }break;
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}

}
void Principal::MenuCad() {
	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Menu Cadastrar" << endl <<endl<<
			"1. Cadastrar personagens" << endl <<
			"2. Cadastrar poderes" << endl <<
			"3. Voltar" << endl<<endl;
		cin >> a;
		switch (a) {
		case 1: { CadPersonagens();}break;
		case 2: { CadPoderes();}break;
		case 3: { }break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::MenuExe() {
	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Menu Executar" << endl <<
			"1. Listar personagens" << endl <<
			"2. Listar poderes" << endl <<
			"3. Voltar" << endl<<endl;
		cin >> a;
		switch (a) {
		case 1: { Lpers.listar(); system("Pause");}break;
		case 2: { CadPoderes(); system("Pause");}break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::CadPersonagens() {
	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Cadastrar Personagens" << endl << endl <<
			"1. Novo personagem" << endl <<
			"2. Editar personagem" << endl <<
			"3. Voltar" << endl<<endl;
		cin >> a;
		switch (a) {
		case 1: { NovoPersonagem(); system("Pause"); }break;
		case 2: { EditarPersonagem(); system("Pause");}break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::CadPoderes() {
	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Cadastrar Poderes" << endl << endl <<
			"1. Novo poder" << endl <<
			"2. Editar poder" << endl <<
			"3. Voltar" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { NovoPoder(); system("Pause"); }break;
		case 2: { EditarPoder(); system("Pause"); }break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::NovoPersonagem(){
	char nome[20];
	cout << "nome: ";
	cin >> nome;
	Personagem* pPer = Lpers.localiza(nome);
	if (pPer != NULL) {
		cout << "personagem ja cadastrado" << endl;
		return;
	}
	pPer = new Personagem;
	pPer->setNome(nome);
	pPer->printAll();
	system("Pause");
	Lpers.novoPer(pPer);
	Lpers.listar();
	Lpers.listarNomes();
	system("Pause");

	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Personagem " << nome <<" // " << pPer->getNome().getpStr() << endl << endl <<
			"1. Adicionar status" << endl <<
			"2. Adicionar poderes" << endl <<
			"3. Voltar" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { MenuStatusPer(pPer); system("Pause"); }break;
		case 2: { NovoPoder(pPer); system("Pause"); }break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::MenuStatusPer(Personagem* pp) {
	int a = -1, b = -1;
	while (a != 4) {
		system("cls");
		cout << "Personagem  "<<pp->getNome().getpStr() << endl << endl <<
			"1. Vida: " << pp->getVida() << endl <<
			"2. Energia: " << pp->getEner() << endl <<
			"3. Destreza: " << pp->getDex() << endl <<
			"4. Voltar" << endl << endl <<
			"SELECIONE UMA OPCAO" << endl << endl;
		cin >> a;
		if (a != 4) {
			cout << "Novo valor: ";
			cin >> b;
		}
		switch (a) {
		case 1: { pp->setVida(b);system("Pause"); }break;
		case 2: { pp->setEner(b); system("Pause"); }break;
		case 3: { pp->setDex(b); system("Pause"); }break;
		case 4: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::MenuStatusPod(Poder* pp) {
	int a = -1, b = -1;
	while (a != 4) {
		system("cls");
		cout << pp->getNome().getpStr() << endl << endl <<
			"1. Dano: " << pp->getDano() << endl <<
			"2. Cura: " << pp->getCura() << endl <<
			"3. Custo: " << pp->getCusto() << endl <<
			"4. Voltar" << endl << endl;
		cin >> a;
		if (a != 4) {
			cout << "Novo valor: ";
			cin >> b;
		}
		switch (a) {
		case 1: { pp->setDano(b);system("Pause"); }break;
		case 2: { pp->setCura(b); system("Pause"); }break;
		case 3: { pp->setCusto(b); system("Pause"); }break;
		case 4: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::EditarPersonagem() {
	if (Lpers.vazia()) {
		cout << "nao ha personagens cadastrados no programa para serem editados!" << endl;
		return;
	}
	char nome[20];
	int a = -1;
	Lpers.listarNomes();
	cout << endl << "qual personagem? " << endl;
	cin >> nome;
	Personagem* pp = Lpers.localiza(nome);
	if (pp == NULL) {
		//cout << "personagem nao encontrado! " << endl;
		while (a != 2) {
			system("cls");
			cout << "personagem nao encontrado! " << endl << endl <<
				"1. Tentar novamente" << endl <<
				"2. Voltar" << endl << endl;
			cin >> a;
			switch (a) {
			case 1: { EditarPersonagem(); system("Pause"); }break;
			case 2: {}break;//voltar
			default: { cout << "opcao invalida, tente novamente!" << endl; }break;
			}
		}
	}
	else
		MenuStatusPer(pp);
}

void Principal::NovoPoder(Personagem* pp){
	char nome[20];
	cout << "nome: ";
	cin >> nome;
	Poder* pPod = pp->localizaNomeLista(nome);
	
	if (pPod != NULL) {
		cout << "personagem ja cadastrado" << endl;
		return;
	}
	pPod = new Poder(nome);
	Lpods.novoPod(pPod);

	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Poder " << nome << endl << endl <<
			"1. Adicionar status" << endl <<
			"2. Adicionar descricao" << endl <<
			"3. Voltar" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { MenuStatusPod(pPod); system("Pause"); }break;
		case 2: {
			cout << "Descricao: ";
			char des[50];
			cin >> des;
			pPod->setDescricao(des);
			cout << "descricao adicionada com sucesso!" << endl;
			system("Pause"); }break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::NovoPoder() {
	char nome[20];
	cout << "nome: ";
	cin >> nome;
	Poder* pPod = Lpods.localiza(nome);

	if (pPod != NULL) {
		cout << "poder ja cadastrado" << endl;
		return;
	}
	pPod = new Poder(nome);
	Lpods.novoPod(pPod);
	char des[50];
	int a = -1;
	while (a != 3) {//LOOP INFINITO!
		system("cls");
		cout << "Poder " << nome << endl << endl <<
			"1. Adicionar status" << endl <<
			"2. Adicionar descricao" << endl <<
			"3. Voltar" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { MenuStatusPod(pPod); system("Pause"); }break;
		case 2: { cin >> des;pPod->setDescricao(nome); system("Pause"); }break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::EditarPoder() {
	if (Lpods.vazia()) {
		cout << "nao ha poderes cadastrados no programa para serem editados!" << endl;
		return;
	}
	char nome[20];
	int a = -1;
	Lpods.listarNomes();
	cout << endl << "qual poder? " << endl;
	cin >> nome;
	Poder* pp = Lpods.localiza(nome);
	if (pp == NULL) {
		while (a != 2) {
			system("cls");
			cout << "poder nao encontrado! " << endl << endl <<
				"1. Tentar novamente" << endl <<
				"2. Voltar" << endl << endl;
			cin >> a;
			switch (a) {
			case 1: { EditarPoder(); system("Pause"); }break;
			case 2: {}break;//voltar
			default: { cout << "opcao invalida, tente novamente!" << endl; }break;
			}
		}
	}
	else 
		MenuStatusPod(pp);
}


void Principal::MenuGravar(){
	int a = -1;
	while (a != 5) {
		system("cls");
		cout << "MENU GRAVAR" << endl << endl <<
			"1. Gravar tudo" << endl <<
			"2. Gravar personagens" << endl <<
			"3. Gravar poderes" << endl <<
			"4. Sair" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { GravarTudo(); }break;
		case 2: { GravarPer(); }break;
		case 3: { GravarPod(); }break;
		case 4: { cout << "FIM" << endl; }break;
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}
void Principal::MenuRecuperar(){
	int a = -1;
	while (a != 5) {
		system("cls");
		cout << "MENU RECUPERAR" << endl << endl <<
			"1. Recuperar tudo" << endl <<
			"2. Recuperar personagens" << endl <<
			"3. Recuperar poderes" << endl <<
			"4. Sair" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { RecuperarTudo(); }break;
		case 2: { RecuperarPer(); }break;
		case 3: { RecuperarPod(); }break;
		case 4: { cout << "FIM" << endl; }break;
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::GravarTudo(){}
void Principal::GravarPer() { Lpers.Gravar(); }
void Principal::GravarPod(){ Lpods.Gravar(); }

void Principal::RecuperarTudo() {}
void Principal::RecuperarPer() { Lpers.Recuperar(); }
void Principal::RecuperarPod() { Lpods.Recuperar(); }