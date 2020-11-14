#include "Parser.h"

#include <iostream>

Parser::Parser( string file ) {
	lex = new Lex( file );
	symbolTable = SymbolTable::getInstance();
}

Parser::~Parser() {
	delete lex;
}

void Parser::execute(){
	while( lex->hasNextToken() ){
		Symbol s = lex->nextToken();

		checkSymbolInvalid( s );

		cout << s << endl;
	}
}

void Parser::checkSymbolInvalid( Symbol s ){
	if( s.getType() == Symbol::TOKEN_TYPE::INDEFINED ){
		throw Error(
			"Na linha " + to_string( lex->getCurrentLine() ) +
			" não foi possível encontrar o tipo do token: "
				+ s.getToken()
		);
	}
}
