#ifndef OCR_HH_
# define OCR_HH_

# include <iostream>
# include "LoadFile.hh"
# include "Alphabet.hh"

class OCR
{
public:
	OCR();
	~OCR();

private:
	int 		_toto;
	LoadFile *	_ldFile;
	Alphabet	_alphabet;

public:
	int work();
	int isEverythingOK();
};

#endif