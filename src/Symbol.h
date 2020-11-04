#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

using namespace std;

class Symbol{
private:
	string type;
	string token;

public:
	Symbol( string type, string token ){
		this->type = type;
		this->token = token;
	}
	
	string getToken(){
		return this->token;
	}

	string getType(){
		return this->type;
	}
};
#endif