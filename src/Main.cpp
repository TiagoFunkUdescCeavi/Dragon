#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Parser.h"

using namespace std;

void run( string fileName ){
//	Lex l( fileName );
//
//	do{
//		cout << ">>>" << l.nextToken() << "<<<" << endl;
//	}while( l.hasNextToken() );

	Parser p( fileName );
	p.execute();
}

string getFileName( int argc, char* argv[] ){
	if( argc == 2 ){
		return argv[1];
	}
	throw runtime_error( "This program expect one argument: kpiler <name of file>" );
}

int main(int argc, char* argv[]){
	try{
		run( getFileName( argc, argv ) );
	}catch(runtime_error &ex){
		cerr << ex.what() << endl;
	}
	return 0;
}
