#include "Lex.h"

Lex::Lex( string fileName ){
	buffer = new Buffer( fileName );
}

Lex::~Lex(){
	delete buffer;
}

Symbol Lex::nextToken(){
	bool stop = false;
	char ch;
	aux = "";

	while( !stop ){
		ch = buffer->next();
		if( isBlank( ch ) ){
			if( aux.size() != 0 ){
				stop = true;
			}
			if( ch == '\n' ){
				currentLine++;
			}

		}else if( isSpecialChar( ch ) ){
			if( aux.size() != 0 ){
				buffer->retract( 1 );
			}else{
				aux = ch;
			}
			stop = true;
		}else{
			aux += ch;
		}
	}


	if( buffer->peek() == '\0' ){
		hasNext = false;
	}

	return symbolize( aux );
}

bool Lex::hasNextToken(){
	return hasNext;
}

int Lex::getCurrentLine(){
	return currentLine;
}

Symbol Lex::symbolize( string token ){
	 if( regex_match( token, regex("if|else|while|function|break") ) ){
		return Symbol( Symbol::TOKEN_TYPE::KEYWORD, aux );

	}else if( regex_match( token, regex("[a-zA-Z][a-zA-Z0-9]*") ) ){
		return Symbol( Symbol::TOKEN_TYPE::ID, aux );

	}else if( regex_match( token, regex("[0-9]+") ) ){
		return Symbol( Symbol::TOKEN_TYPE::NUMBER, aux );

	}else if( regex_match( token, regex("[+]|[-]|[*]|[/]|[=]|[!]") ) ){
		return Symbol( Symbol::TOKEN_TYPE::OPERATOR, aux );

	}else if( regex_match( token, regex("\"([a-zA-Z0-9])+\"") ) ){
		return Symbol( Symbol::TOKEN_TYPE::CHARACTERS, aux );

	}else if( regex_match( token, regex("[(]|[)]|;") ) ){
		return Symbol( Symbol::TOKEN_TYPE::SEPARATOR, aux );
	}

	return Symbol( Symbol::TOKEN_TYPE::INDEFINED, aux );
}
