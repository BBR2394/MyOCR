/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2017-01-18 15:41:24
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2017-02-16 15:06:22
*/

#include "LoadFile.hh"

LoadFile::LoadFile()
{

}

LoadFile::~LoadFile()
{

}

int LoadFile::openTheFile(char * name)
{
	std::cout << "here i open the file" << std::endl;
	std::cout << "if probleme return bad value" << std::endl;
	
	_theFile.open(name, std::ios::in|std::ios::binary|std::ios::ate);

	if (_theFile.is_open())
		std::cout << "le fichier est ouvert"  << std::endl;
	else
		std::cout << "le fichier n'a pu etre ouvert" << std::endl;
    
    _theDoc = new PNGFile();
    _theDoc->openFile(name);
    //_theDoc->printData();
    return 0;
}

int LoadFile::loadTheFile()
{
    return 0;
}
