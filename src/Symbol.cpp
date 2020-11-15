#include "Symbol.h"

Symbol::Symbol( TOKEN_TYPE type, string token ){
	this->type = type;
	this->token = token;
}

string Symbol::getToken(){
	return this->token;
}

Symbol::TOKEN_TYPE Symbol::getType(){
	return this->type;
}

ostream &operator<<( ostream &output, const Symbol &symbol ){
	string s = "";
	if( symbol.type == Symbol::TOKEN_TYPE::ID ){
		s = "ID";
	}else if( symbol.type == Symbol::TOKEN_TYPE::NUMBER ){
		s = "NUMBER";
	}else if( symbol.type == Symbol::TOKEN_TYPE::OPERATOR ){
		s = "OPERATOR";
	}else if( symbol.type == Symbol::TOKEN_TYPE::MATH_OPERATOR ){
		s = "MATH_OPERATOR";
	}else if( symbol.type == Symbol::TOKEN_TYPE::KEYWORD ){
		s = "KEYWORD";
	}else if( symbol.type == Symbol::TOKEN_TYPE::SEPARATOR ){
		s = "SEPARATOR";
	}else if( symbol.type == Symbol::TOKEN_TYPE::CHARACTERS ){
		s = "CHARACTERS";
	}else {
		s = "INDEFINED";
	}
	output << string( "Symbol[" );
	output << s;
	output << string( "," );
	output << symbol.token;
	output << string( "]" );
	return output;
}
