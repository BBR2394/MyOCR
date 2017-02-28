#ifndef IDOCUMENT_HH_
# define IDOCUMENT_HH_

class IDocument
{
public:
	virtual int openFile(char *) = 0;
	virtual int printData() = 0;
};

#endif