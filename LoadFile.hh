#ifndef LOADFILE_HH_
# define LOADFILE_HH_

#include <iostream>     // std::cout
#include <fstream>		// ifstream
#include <string>

class LoadFile
{
public:
	LoadFile();
	~LoadFile();

private:
	unsigned char * _file;
	int 			_fdFile;
	std::ifstream	_theFile;

public:
	int openTheFile(std::string );
	int loadTheFile();
};

#endif