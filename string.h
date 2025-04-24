#pragma once
#include "stdafx.h"

class string
{
private:
	char* pStr;
	int tam;

public:
	string(const char* str="");
	~string();
	const char* getpStr();
	int getTam();
	void setStr(const char* str);

	void operator = (const char* s);
	void operator = (string& s);

	bool operator == (const char* s);
	bool operator == (string& s);
	bool operator != (const char* s);
	bool operator != (string& s);

	void operator += (const char* s);
	void operator += (string& s);

	string operator + (const char* s);
	string operator + (string& s);

	string operator - (const char* s);
	string operator - (string& s);

	char operator [] (int i);

	void copia(char* Str, const char* str);
private:
	void inicializa(const char* str);
	int calcTam(const char* str);
	void destroi();

};

//ostream& operator << (ostream& saida, string& s);

