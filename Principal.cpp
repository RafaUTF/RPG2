#include "Principal.h"
#include "Personagem.h"

Principal::Principal() {
}
Principal::~Principal() {
}
void Principal::executar() {
	Menu();
}


void Principal::Menu() {
	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "RPG2" << endl <<endl<<
			"1. Cadastrar" << endl <<
			"2. Executar" << endl <<
			"3. Sair" << endl<<endl;
		cin >> a;
		switch (a) {
		case 1: { MenuCad(); }break;
		case 2: { MenuExe(); }break;
		case 3: { cout << "FIM" << endl; }break;
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
	pPer = new Personagem(nome);
	Lpers.novoPer(pPer);

	int a = -1;
	while (a != 3) {
		system("cls");
		cout << "Personagem " << nome <<endl << endl <<
			"1. Adicionar status" << endl <<
			"2. Adicionar poderes" << endl <<
			"3. Voltar" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { MenuStatus(pPer); system("Pause"); }break;
		case 2: { NovoPoder(pPer); system("Pause"); }break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::MenuStatus(Personagem* pp) {
	int a=-1,b=-1;
	while (a!=4) {
		system("cls");
		cout << pp->getNome().getpStr() << endl << endl <<
			"1. Vida: " << pp->getVida()<<endl <<
			"2. Energia: " << pp->getEner() << endl <<
			"3. Destreza: " << pp->getDex() << endl <<
			"4. Voltar" << endl << endl;
		cin >> a;
		cout << "Novo valor: ";
		cin >> b;
		switch (a) {
		case 1: { pp->setVida(b);system("Pause"); }break;
		case 2: { pp->setEner(b); system("Pause"); }break;
		case 3: { pp->setDex(b); system("Pause"); }break;
		case 4: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
}

	void Principal::MenuStatus(Poder* pp) {
		int a = -1, b = -1;
		while (a != 4) {
			system("cls");
			cout << pp->getNome().getpStr() << endl << endl <<
				"1. Dano: " << pp->getDano() << endl <<
				"2. Cura: " << pp->getCura() << endl <<
				"3. Custo: " << pp->getCusto() << endl <<
				"4. Voltar" << endl << endl;
			cin >> a;
			cout << "Novo valor: ";
			cin >> b;
			switch (a) {
			case 1: { pp->setDano(b);system("Pause"); }break;
			case 2: { pp->setCura(b); system("Pause"); }break;
			case 3: { pp->setCusto(b); system("Pause"); }break;
			case 4: {}break;//voltar
			default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
			}
		}

void Principal::EditarPersonagem() {
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
			cout << "personagem nao encontrado! " << endl << endl<<
				"1. Tentar novamente" << endl <<
				"2. Voltar" << endl << endl;
			cin >> a;
			switch (a) {
			case 1: { EditarPersonagem(); system("Pause");}break;
			case 2: {}break;//voltar
			default: { cout << "opcao invalida, tente novamente!" << endl; }break;
			}
		}
	}
	else {
		cout << "vida: ";
		cin >> a;
		pp->setVida(a);
		cout << "energia: ";
		cin >> a;
		pp->setEner(a);
		cout << "Destreza: ";
		cin >> a;
		pp->setDex(a);
		cout << "personagem editado com sucesso!" << endl;
	}
}

void Principal::NovoPoder(Personagem* pp){
	char nome[20];
	cout << "nome: ";
	cin >> nome;
	Poder* pPod = pp->getLista().localiza(nome);
	
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
		case 1: { MenuStatus(pPod); system("Pause"); }break;
		case 2: {
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
	while (a != 3) {
		system("cls");
		cout << "Poder " << nome << endl << endl <<
			"1. Adicionar status" << endl <<
			"2. Adicionar descricao" << endl <<
			"3. Voltar" << endl << endl;
		cin >> a;
		switch (a) {
		case 1: { MenuStatus(pPod); system("Pause"); }break;
		case 2: { cin >> des;pPod->setDescricao(nome); system("Pause"); }break;
		case 3: {}break;//voltar
		default: { cout << "opcao invalida, tente novamente!" << endl; system("Pause"); }break;
		}
	}
}

void Principal::EditarPoder() {
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
	else {
		cout << "vida: ";
		cin >> a;
		pp->setVida(a);
		cout << "energia: ";
		cin >> a;
		pp->setEner(a);
		cout << "Destreza: ";
		cin >> a;
		pp->setDex(a);
		cout << "personagem editado com sucesso!" << endl;
	}
}

void Principal::MenuStatus(Poder* pp) {}

void Principal::MenuStatus(Personagem* pp) {}