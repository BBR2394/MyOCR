CXX	=	clang++

SRC	=	main.cpp	\
		OCR.cpp		\
		LoadFile.cpp \
		Alphabet.cpp \
		Letter.cpp		\
		Gui.cpp			\
		OptionArg.cpp 	\
		PNGFile.cpp		

OBJ	=	$(SRC:.cpp=.o)

NAME	=	MyOCR

CXXFLAGS	=	-I/usr/local/include/libpng16/ 
LFLAGS		=	-lpng -L/usr/local/lib/ -I/usr/local/include/libpng16/ 

all: $(NAME) 

$(NAME): $(OBJ) -L/usr/local/lib/ -lpng  $(CXXFLAGS) $(LFLAGS)
	$(CXX) -L/usr/local/lib/ -lpng -o $(NAME) $(OBJ) $(CXXFLAGS) $(LFLAGS) 

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all