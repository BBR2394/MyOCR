
#include "PNGFile.hh"

PNGFile::PNGFile()
{
	std::cout << "pngfile created" << std::endl;
}


PNGFile::~PNGFile()
{
	std::cout << "png file destroyed" << std::endl;
}

int PNGFile::openFile(char *file_name)
{
    int x, y;

	char header[8];    // 8 is the maximum size that can be checked

        /* open file and test for it being a png */
        FILE *fp = fopen(file_name, "rb");
        if (!fp)
            std::cout << "le fichier n'a pas été ouvert" << std::endl;
                //abort_("[read_png_file] File %s could not be opened for reading", file_name);
        fread(header, 1, 8, fp);
        if (png_sig_cmp((png_const_bytep)header, (png_size_t)0, 8))
                std::cout << "problem 1" << std::endl;
                //abort_("[read_png_file] File %s is not recognized as a PNG file", file_name);


        /* initialize stuff */
        _png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

        if (!_png_ptr)
                std::cout << "problem 2" << std::endl;
                //abort_("[read_png_file] png_create_read_struct failed");

        _info_ptr = png_create_info_struct(_png_ptr);
        if (!_info_ptr)
            std::cout << "problem 3" << std::endl;
                //abort_("[read_png_file] png_create_info_struct failed");

        if (setjmp(png_jmpbuf(_png_ptr)))
                std::cout << "problem 4" << std::endl;
                //abort_("[read_png_file] Error during init_io");

        png_init_io(_png_ptr, fp);
        png_set_sig_bytes(_png_ptr, 8);
        png_read_info(_png_ptr, _info_ptr);

        _width = png_get_image_width(_png_ptr, _info_ptr);
        _height = png_get_image_height(_png_ptr, _info_ptr);
        _color_type = png_get_color_type(_png_ptr, _info_ptr);
        _bit_depth = png_get_bit_depth(_png_ptr, _info_ptr);

        _number_of_passes = png_set_interlace_handling(_png_ptr);
        png_read_update_info(_png_ptr, _info_ptr);


        /* read file */
        if (setjmp(png_jmpbuf(_png_ptr)))
                std::cout << "problem 5" << std::endl;
                //abort_("[read_png_file] Error during read_image");

        _row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * _height);
        for (y=0; y< _height; y++)
                _row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(_png_ptr,_info_ptr));

        std::cout << "different informations " << _width << " " << _height << std::endl;
        png_read_image(_png_ptr, _row_pointers);
        
        fclose(fp);
    return 0;
}

int PNGFile::printData()
{
	if (png_get_color_type(_png_ptr, _info_ptr) == PNG_COLOR_TYPE_GRAY)
		std::cout << "the picture is in grayscale" << std::endl;
    if (png_get_color_type(_png_ptr, _info_ptr) == PNG_COLOR_TYPE_RGB)
    	std::cout << "type RGB " << std::endl;
    
    

    if (png_get_color_type(_png_ptr, _info_ptr) == PNG_COLOR_TYPE_RGBA)
    {
    	std::cout << "color type is rgba" << std::endl;
    	//attention ca doit etre du RGBA
    for (int i = 0; i < _height * _width * 4; i++)
    {
    	printf("%d-", _row_pointers[i]);
    }
    /*for (int y=0; y<_height; y++) {
                png_byte* row = _row_pointers[y];    
                for (int x=0; x<_width; x++) {
                        png_byte* ptr = &(row[x*4]);
                        printf("Pixel at position [ %d - %d ] has RGBA values: %d - %d - %d - %d\n",
                               x, y, ptr[0], ptr[1], ptr[2], ptr[3]);

                        //set red value to 0 and green value to the blue one 
                        ptr[0] = 0;
                        ptr[1] = ptr[2];
                }
        }*/
     }
     if (png_get_color_type(_png_ptr, _info_ptr) == PNG_COLOR_TYPE_RGB)
     {
     	for (int y=0; y<_height; y++) {
                png_byte* row = _row_pointers[y];    
                for (int x=0; x<_width; x++) {
                        png_byte* ptr = &(row[x*3]);
                        printf("Pixel at position [ %d - %d ] has RGB values: %d - %d - %d - %d\n",
                               x, y, ptr[0], ptr[1], ptr[2]);

                        /* set red value to 0 and green value to the blue one */
                        ptr[0] = 0;
                        ptr[1] = ptr[2];
                }
        }
     }
        std::cout << "i have processed the file" << std::endl;
}