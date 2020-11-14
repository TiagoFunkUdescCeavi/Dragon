#include "SymbolTable.h"

SymbolTable * SymbolTable::_instance = 0;

SymbolTable * SymbolTable::getInstance(){
	if( _instance == 0 ){
		_instance = new SymbolTable;
	}
	return _instance;
}

void SymbolTable::initializeReservedWords(){
	insertSymbol( Symbol( Symbol::KEYWORD, "if") );
	insertSymbol( Symbol( Symbol::KEYWORD, "else") );
	insertSymbol( Symbol( Symbol::KEYWORD, "function") );
	insertSymbol( Symbol( Symbol::KEYWORD, "break") );
}

SymbolTable::SymbolTable(){
	initializeReservedWords();
}

bool SymbolTable::insertSymbol( Symbol s ){
	if( !containsSymbol( s.getToken() ) ){
		mapSymbols.insert( Map::value_type( s.getToken(), s ) );
		return true;
	}
	return false;
}

bool SymbolTable::containsSymbol( string key ){
	return mapSymbols.find( key ) != mapSymbols.end();
}
