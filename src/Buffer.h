#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <fstream>
#include <stdexcept>

#include <iostream>

using namespace std;

class Buffer{
public:
	Buffer( string fileName ){
		this->fileName = fileName;
		file.open( this->fileName );
		file.unsetf(ios::skipws);
		buffer = new char[ 2 * BUFFER_SIZE ];
		for( int i = 0; i < 2*BUFFER_SIZE; i++ ){
			buffer[ i ] = 'a';
		}
		loadBuffer( 0 );
	}
	
	virtual ~Buffer(){
		file.close();
	}
	
	char next(){
		ch = buffer[ position ];
		position = (position+1) % (2*BUFFER_SIZE);
//		cout << position << endl;
		checkReload();
		return ch;
	}
	
	void retract( int n ){
		position -= n;
		if( position < 0 ){
			position = BUFFER_SIZE + position;
		}
//		cout << position << endl;
	}
	
private:
	bool load_begin = false;
	bool load_end  = true;
	char ch;
	string fileName;
	ifstream file;
	int position = 0;
	char * buffer = 0;
	
	static const int BUFFER_SIZE = 10;
	
	void loadBuffer( int begin ){
		char ch;
		for( int i = begin; i < (begin + BUFFER_SIZE); i++ ){
			if( file >> ch ){
				buffer[ i ] = ch;
			}else{
				buffer[ i ] = '\0';
				break;
			}
		}
//		print();
	}
	
	void checkReload(){
		if( position == BUFFER_SIZE-1 && load_end ){
			loadBuffer( BUFFER_SIZE );
			load_end = false;
			load_begin = true;
		}
		if( position == 2*BUFFER_SIZE-1 && load_begin ){
			loadBuffer( 0 );
			load_end = true;
			load_begin = false;
		}
	}
	
	void print(){
		cout << "[";
		for( int i = 0; i < 2*BUFFER_SIZE; i++ ){
			cout << i << ":";
			if( buffer[ i ] == '\0' ){
				cout << "\\0";
			}else if( buffer[ i ] == '\n' ){
				cout << "\\n";
			}else if( buffer[ i ] == '\0' ){
				cout << "\\0";
			}else{
				cout << buffer[ i ];
			}
			cout << ", ";
		}
		cout << "]" << endl;
	}
	
};

#endif
