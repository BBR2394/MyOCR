#ifndef OCR_HH_
# define OCR_HH_

# include <iostream>
# include "LoadFile.hh"

class OCR
{
public:
	OCR();
	~OCR();

private:
	int 		_toto;
	LoadFile *	_ldFile;


public:
	int work();

};

#endif