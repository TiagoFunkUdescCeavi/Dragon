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
		Symbol s = getNextSymbol();

		if( s.getType() == Symbol::TOKEN_TYPE::ID ){
			bool result = symbolTable->insertSymbol( s );
			if( result ){
				comand();
			}else{
				throw Error(
					location( s ) +
					" Variável definida anteriormente: "
					+ s.getToken()
				);
			}
		}else{
			throw Error(
				location( s ) +
				" Comandos sempre iniciam com variáveis: "
					+ s.getToken());
		}
	}
}

Symbol Parser::getNextSymbol(){
	Symbol s = lex->nextToken();
	cout << s << endl;
	checkSymbolInvalid( s );
	return s;
}

void Parser::checkSymbolInvalid( Symbol s ){
	if( s.getType() == Symbol::TOKEN_TYPE::INDEFINED ){
		throw Error(
			location( s ) +
			" token inválido: "
				+ s.getToken()
		);
	}
}

void Parser::comand(){
	Symbol s2 = getNextSymbol();
	if( s2.getType() == Symbol::OPERATOR && s2.getToken() == "=" ){
		expression();
	}else{
		throw Error(
			location( s2 ) +
			" foi encontrado um token inesperado: "
			+ s2.getToken()
			+ "\nToken esperado: ="
		);
	}
}

void Parser::expression(){
	Symbol s2 = getNextSymbol();
	Symbol s3 = getNextSymbol();
	if( s2.getType() == Symbol::ID
			&& s3.getType() == Symbol::SEPARATOR
			&& s3.getToken() == ";" ){
		if( !symbolTable->containsSymbol( s2.getToken() ) ){
			throw Error( location( s2 ) + " variável indefinada: " + s2.getToken() );
		}

	} else if( s2.getType() == Symbol::NUMBER
			&& s3.getType() == Symbol::SEPARATOR
			&& s3.getToken() == ";" ){

	}else if( s2.getType() == Symbol::ID
			&& s3.getType() == Symbol::MATH_OPERATOR ){
		expression();

	} else if( s2.getType() == Symbol::NUMBER
			&& s3.getType() == Symbol::MATH_OPERATOR ){
		expression();
	}else{
		throw Error(
			location( s3 ) +
			" foi encontrado um token inesperado: "
			+ s3.getToken()
		);

	}
}

string Parser::location( Symbol s ){
	return "Em " + to_string( lex->getCurrentLine() ) +
			"," + to_string( lex->getCurrentColumn() - s.getToken().size() );
}
