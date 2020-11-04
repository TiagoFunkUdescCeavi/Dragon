#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <map>

#include "Symbol.h"

using namespace std;

class SymbolTable{
private:
	typedef map< string, Symbol, less< string > > Map;
	Map mapSymbols;
	
	SymbolTable * _instance = 0;
	
	void initializeReservedWords(){
		
	}
	
protected:
	SymbolTable(){
		initializeReservedWords();
	}
	
public:
	SymbolTable * getInstance(){
		if( _instance == 0 ){
			_instance = new SymbolTable();
		}
		return this->_instance;
	}
	
	bool insertSymbol( Symbol s ){
		if( !containsSymbol( s.getToken() ) ){
			mapSymbols.insert( Map::value_type( s.getToken(), s ) );
			return true;
		}
		return false;
	}
	
	bool containsSymbol( string key ){
		return mapSymbols.find( key ) != mapSymbols.end();
	}

};
#endif