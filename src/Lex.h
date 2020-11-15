#ifndef LEX_H
#define LEX_H

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <regex>

#include <iostream>

#include "Utils.h"
#include "SymbolTable.h"
#include "Buffer.h"
#include "Symbol.h"

using namespace std;

class Lex{
public:
	Lex( string fileName );
	virtual ~Lex();
	
	Symbol nextToken();
	bool hasNextToken();
	
	int getCurrentLine();
	int getCurrentColumn();

private:
	bool hasNext = true;
	int currentLine = 1;
	int currentColumn = 0;
	string aux;
	Buffer * buffer = 0;
	
	Symbol symbolize( string token );
};

#endif
