/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2017-01-18 15:41:24
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2017-01-31 15:20:31
*/

#include "LoadFile.hh"

LoadFile::LoadFile()
{

}

LoadFile::~LoadFile()
{

}

int LoadFile::openTheFile(std::string name)
{
	std::cout << "here i open the file" << std::endl;
	std::cout << "if probleme return bad value" << std::endl;
	_theFile.open(name, std::ifstream::in);

	if (_theFile.is_open())
		std::cout << "le fichier est ouvert"  << std::endl;
	else
		std::cout << "le fichier n'a pu etre ouvert" << std::endl;
}

int LoadFile::loadTheFile()
{

}