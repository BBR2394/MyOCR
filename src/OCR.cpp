#include "OCR.hh"

OCR::OCR()
{

}

OCR::~OCR()
{

}

int OCR::isEverythingOK()
{
	_alphabet.printAlphabet();
}

int OCR::work()
{
	_ldFile = new LoadFile();
	_alphabet.loadAlphabet("alphabet-fr.ab");
	_ldFile->openTheFile("./pourOCR/test-texte-to-detect.png");
	//_ldFile->openTheFile("titi");

	this->isEverythingOK();
	std::cout << "bonjour" << std::endl;
	return 0;
}