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

	void checkSymbolInvalid( Symbol s );

};

#endif /* PARSER_H_ */
