#ifndef PARSER_H_
#define PARSER_H_

#include <string>

#include "Lex.h"
#include "SymbolTable.h"
#include "Error.h"

using std::string;

class Parser {
public:
	Parser( string file );
	virtual ~Parser();

	void execute();

private:
	Lex * lex = 0;
	SymbolTable * symbolTable = 0;

	Symbol getNextSymbol();
	void checkSymbolInvalid( Symbol s );

	void comand();
	void expression();

	string location( Symbol s );


};

#endif /* PARSER_H_ */
