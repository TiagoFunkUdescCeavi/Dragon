#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

using namespace std;

class Symbol{

public:
	enum TOKEN_TYPE{
		ID,
		NUMBER,
		KEYWORD,
		OPERATOR,
		CHARACTERS,
		SEPARATOR,
		INDEFINED
	};

	Symbol( TOKEN_TYPE type, string token );
	
	string getToken();
	TOKEN_TYPE getType();

	friend ostream &operator<<( ostream &output, const Symbol &symbol );

private:
	TOKEN_TYPE type;
	string token;

};
#endif
