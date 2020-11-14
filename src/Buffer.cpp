#include "Buffer.h"

Buffer::Buffer( string fileName ){
	this->fileName = fileName;
	file.open( this->fileName );
	file.unsetf(ios::skipws);
	buffer = new char[ 2 * BUFFER_SIZE ];
	for( int i = 0; i < 2*BUFFER_SIZE; i++ ){
		buffer[ i ] = 'a';
	}
	loadBuffer( 0 );
}

Buffer::~Buffer(){
	file.close();
}

char Buffer::next(){
	ch = buffer[ position ];
	position = (position+1) % (2*BUFFER_SIZE);
//	cout << position << endl;
	checkReload();
	return ch;
}

char Buffer::peek(){
	return buffer[ position ];
}

void Buffer::retract( int n ){
	position -= n;
	if( position < 0 ){
		position = BUFFER_SIZE + position;
	}
//	cout << position << endl;
}

void Buffer::loadBuffer( int begin ){
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

void Buffer::checkReload(){
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

void Buffer::print(){
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
