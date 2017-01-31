CXX	=	clang++

SRC	=	main.cpp	\
		OCR.cpp		\
		LoadFile.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	MyOCR

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all