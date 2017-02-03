#ifndef LETTER_HH_
# define LETTER_HH_

#include <string>

class Letter
{
public:
	Letter(char);
	Letter();
	~Letter();

private:
	char	*_letter8;
	char	*_letter16;
	char 	*_letter32;
	char	_corespondingLetterChar;
	std::string	_corespondingLetter;

public:
	std::string getCorespondingLetter() const;

};

#endif