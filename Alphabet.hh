#ifndef ALPHABET_HH_
# define ALPHABET_HH_

#include <iostream>     // std::cout
#include <fstream>		// ifstream
#include <string>
#include <list>

#include "Letter.hh"

class Alphabet
{
public:
	Alphabet();
	~Alphabet();

private:
	std::ifstream _alphabetFile;
	std::list<Letter*> _alphabetLst;
	
public:
	int loadAlphabet(std::string);
};

#endif