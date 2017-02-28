#include "Alphabet.hh"

Alphabet::Alphabet()
{
	
}

Alphabet::~Alphabet()
{
	
}

int Alphabet::loadAlphabet(std::string fileName)
{
	Letter *letter;
	_alphabetFile.open(fileName, std::ios::in);

	_alphabetFile.seekg (0, _alphabetFile.end);
    int length = _alphabetFile.tellg();
    _alphabetFile.seekg (0, _alphabetFile.beg);

	if (_alphabetFile.is_open())
		std::cout << "alphabet file is open"  << std::endl;
	else
    {
		std::cout << "alphabet file is not open" << std::endl;
        return -1;
    }
	//std::cout << _alphabetFile << std::endl;

	char *buf = new char[length];
	_alphabetFile.read(buf, 1);
	std::cout << "le buffer : " << buf << std::endl;

	for (int i = 0; i < length; i++)
	{
		letter = new Letter(buf[i]);
		_alphabetLst.push_back(letter);
	}
	std::cout << "size of the list " << _alphabetLst.size() << std::endl;
    return 0;
}

/*
** a faire en mode surchage de l'operateur <<
*/
int Alphabet::printAlphabet()
{
	Letter *temp;

	std::cout << "size of the alphabet " << _alphabetLst.size() << std::endl;
	for (std::list<Letter *>::iterator it=_alphabetLst.begin(); it != _alphabetLst.end(); ++it)
	{
    	temp = *it;
    	std::cout << ' "' << temp->getLetter() << '" ';
	}
	std::cout << std::endl;
}