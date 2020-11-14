#include "Utils.h"

string charToString( char c ){
	char b[2];
	b[0] = c;
	b[1] = '\0';
	return b;
}

bool isChar( char c ){
	return c >= 'a' && c <= '}';
	// Favor consultar tabela ascii
}

bool isLetter( char c ){
	return ( c >= 'a' && c <= 'z' )
		|| ( c >= 'A' && c <= 'Z' );
}

bool isDigit( char c ){
	return c >= '0' && c <= '9';
}

bool isSpecialChar( char c ){
	switch( c ){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case ';':
		case '=':
			return true;
	}
	return false;
}

bool isBlank( char c ){
	switch( c ){
		case ' ':
		case '\t':
		case '\n':
		case '\r':
			return true;
	}
	return false;
}
