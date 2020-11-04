#ifndef LEX_H
#define LEX_H

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include <iostream>

#include "utils.h"
#include "SymbolTable.h"
#include "Buffer.h"

using namespace std;

class Lex{
public:
	Lex( string fileName ){
		buffer = new Buffer( fileName );
	}
	
	virtual ~Lex(){
		delete buffer;
	}
	
	void mostrarMerda( char ch ){
		cout << "char:";
		if(ch=='\0'){
			cout << "\\0";
		} else{
			cout << ch;
		} 
		cout << endl;
	}
	
	string nextToken(){
		bool stop = false;
		char ch;
		aux = "";
		
		while( !stop ){
			ch = buffer->next();
//			mostrarMerda( ch );
			if( ch == '\0' ){
				stop = true;
				hasNext = false;
			} else if( isBlank( ch ) ){
				if( aux.size() != 0 ){
					stop = true;
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
		return aux;
	}
	
	bool hasNextToken(){
		return hasNext;
	}
	
private:
	bool hasNext = true;
	string aux;
	Buffer * buffer = 0;
	
};

#endif
