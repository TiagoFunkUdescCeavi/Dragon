#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <map>

#include "Symbol.h"

using namespace std;

class SymbolTable{
public:
	static SymbolTable * getInstance();

	bool insertSymbol( Symbol s );
	bool containsSymbol( string key );

protected:
	SymbolTable();

private:
	typedef map< string, Symbol, less< string > > Map;
	Map mapSymbols;
	
	static SymbolTable * _instance;
	
	void initializeReservedWords();

};
#endif
