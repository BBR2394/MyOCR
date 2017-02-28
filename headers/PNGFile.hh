#ifndef PNGFILE_HH_
# define PNGFILE_HH_

#include <iostream>
#include <string>

#include "IDocument.hh"
#include "png.h"

class PNGFile : public IDocument
{
public:
	PNGFile();	
	~PNGFile();

private:
	std::string _fileName;
	int _width; //largeur
	int _height; //hauteur

	//variable from the example
	png_byte 		_color_type;
	png_byte 		_bit_depth;
	png_structp 	_png_ptr;
	png_infop 		_info_ptr;
	int 			_number_of_passes;
	png_bytep * 	_row_pointers;

public:
	int openFile(char *);
	int printData();

};

#endif