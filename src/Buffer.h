#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <fstream>
#include <stdexcept>

#include <iostream>

using namespace std;

class Buffer{
public:
	Buffer( string fileName );
	virtual ~Buffer();
	
	char next();
	char peek();
	void retract( int n );
	
private:
	bool load_begin = false;
	bool load_end  = true;
	char ch;
	string fileName;
	ifstream file;
	int position = 0;
	char * buffer = 0;
	
	static const int BUFFER_SIZE = 10;
	
	void loadBuffer( int begin );
	void checkReload();
	
	void print();
	
};

#endif
