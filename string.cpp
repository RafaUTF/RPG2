#include "string.h"
//#include <ostream>

string::string(const char* str) { inicializa(str); }
//string::string(const char &str) { inicializa(str); }
void string::inicializa(const char* str) {
	tam = calcTam(str);
	pStr = new char[tam + 1];
	copia(pStr, str);
}

string::~string() { 
	//destroi(); NAO POSSO DESTRUIR TEMPORARIOS(ACHO)!
}

void string::destroi() {
	if (pStr != NULL) {//se nao e null eh pq esta alocada
		delete[]pStr;
		pStr = NULL;
	}
}

const char* string::getpStr() { return pStr; }

int string::getTam() { return tam; }

int string::calcTam(const char* str){
	if (str == NULL)
		return -1;
	int i;
	for (i = 0;str[i] != '\0';i++);
	return i;
}

void string::copia(char* Str, const char* str) {
	int i;
	for (i = 0;i < tam;i++)
		Str[i] = str[i];
	Str[i] = '\0';
}

void string::setStr(const char* str){
	destroi();
	inicializa(str);
}
void string::setStr(string s) { setStr(s.getpStr()); }

void string::operator = (const char* s) {
	if (pStr != NULL)
		destroi();
	inicializa(s);
}
/*
void string::operator = (string* s) {
	operator = (s->getpStr());
}
*/
void string::operator = (string& s) {
	operator = (s.getpStr());
}
bool string::operator == (const char* s) {
	int i;
	for (i = 0;i < tam && s[i] != '\0';i++)
		if (pStr[i] != s[i])
			return false;
	if (i == tam && s[i] == '\0')
		return true;
	return false;
}
bool string::operator == (string& s) {
	return operator == (s.getpStr());
}

bool string::operator != (const char* s) {
	int i;
	for (i = 0;i < tam && s[i] != '\0';i++)
		if (pStr[i] != s[i])
			return true;
	if (i == tam && s[i] == '\0')
		return false;
	return true;
}
bool string::operator != (string& s) {
	return operator != (s.getpStr());
}
/*
ostream& operator << (ostream& saida, string& s) {
	saida << s.getpStr();
	return saida;
}*/

void string::operator += (const char* s) {
	int tam2 = calcTam(s);
	char* p3 = new char[tam + tam2 + 2];
	int i;
	for (i = 0;i < tam;i++)
		p3[i] = pStr[i];
	p3[i] = ' ';//i==tam
	for (i = 0;i<tam2;i++)
		p3[tam+1+i] = s[i];
	p3[tam + 1 + i] = '\0';//i==tam2
	destroi();
	pStr = p3;
	tam = tam + tam2 + 1;
}
void string::operator += (string& s) {
	operator += (s.getpStr());
}

string string::operator + (const char* s) {
	int tam2 = calcTam(s);
	char* p3 = new char[tam + tam2 + 2];
	int i;
	for (i = 0;i < tam;i++)
		p3[i] = pStr[i];
	p3[i] = ' ';//i==tam
	for (i = 0;i < tam2;i++)
		p3[tam + 1 + i] = s[i];
	p3[tam + 1 + i] = '\0';//i==tam2
	string Str(p3);
	return Str;
}
string string::operator + (string& s){
	return operator + (s.getpStr());
}

string string::operator - (const char* s) {
	int i,j,k,inicio;
	for (i = 0, j = 0;i < tam && s[j] != '\0';i++) {
		if (pStr[i] == s[j]) {
			if (j == 0)
				inicio = i;
			j++;
		}
		else if(j!=0)
			j = 0;
	}

	if (s[j] != '\0') {
		string r(pStr);
		return r;
	}
		//return *this;
	
	if (pStr[i] == ' ')
		i = 1;
	else
		i = 0;
	char* p3 = new char[tam - j - i];

	for (k = 0;k < inicio;k++)
		p3[k] = pStr[k];
	//k==inicio
	for (;k+j+i < tam;k++)
		p3[k] = pStr[k+j+i];
	p3[k] = '\0';
	string Str(p3);
	return Str;
}

string string::operator - (string& s) {
	return operator - (s.getpStr());
}

char string::operator [] (int i){
	return pStr[i];
}

void string::print() {
	cout << pStr << endl;
}