#include "OCR.hh"

OCR::OCR()
{

}

OCR::~OCR()
{

}

int OCR::work()
{
	_ldFile = new LoadFile();

	//_ldFile->openTheFile("./pourOCR/test-texte-to-detect.jpg");
	_ldFile->openTheFile("titi");
	std::cout << "bonjour" << std::endl;
	return 0;
}