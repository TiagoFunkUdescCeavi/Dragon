#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "lex.h"

using namespace std;

void run( string fileName ){
	Lex l( fileName );
		
	string s;
	do{
		s = l.nextToken();
		cout << ">>>" << s << "<<<" << endl;
	}while( l.hasNextToken() );
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
