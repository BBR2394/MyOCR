#ifndef LOADFILE_HH_
# define LOADFILE_HH_

#include <iostream>     // std::cout
#include <fstream>		// ifstream
#include <string>

#include "IDocument.hh"
#include "PNGFIle.hh"

class LoadFile
{
public:
	LoadFile();
	~LoadFile();

private:
	unsigned char * _file;
	int 			_fdFile;
	std::ifstream	_theFile;
	IDocument *_theDoc;

public:
	int openTheFile(char * );
	int loadTheFile();
};

#endif