#include "Letter.hh"

Letter::Letter()
{
	
}

Letter::Letter(char letter)
{
	_corespondingLetterChar = letter;
}

Letter::~Letter()
{
	
}

std::string Letter::getCorespondingLetter() const
{
	return _corespondingLetter;
}

std::string Letter::getLetter() const
{
	return _corespondingLetter;
}