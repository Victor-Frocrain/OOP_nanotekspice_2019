##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC			=	src/nanoTekSpice.cpp	\
				src/IComponent.cpp		\
				src/Circuit.cpp			\
				src/Error.cpp			\
				src/Parser.cpp			\
				src/Puts.cpp			\
				src/Tools.cpp			\
				src/Components.cpp		\
				src/Interpretor.cpp		\
				src/Comp4081.cpp		\
				src/Clock.cpp			\
				src/Comp4071.cpp		\
				src/Comp4001.cpp		\
				src/Comp4011.cpp		\
				src/Comp4030.cpp		\
				src/Comp4069.cpp		\
				src/Comp4008.cpp		\
				src/TrueFalse.cpp		\

SRC_MAIN	=	src/main.cpp

SRC_TEST	=	tests/nanoTests.cpp		\

NAME		=	nanotekspice

TEST_NAME	=	unitTests

OBJ			=	$(SRC:%.cpp=%.o)

OBJ_MAIN	=	$(SRC_MAIN:%.cpp=%.o)

CXXFLAGS	=	-Wall -Wextra

CXX			=	g++

TEST_FLAGS	=	-lcriterion --coverage -lgcov

all:		$(NAME)

$(NAME):	$(OBJ_MAIN) $(OBJ)
		$(CXX) $(SRC_MAIN) $(SRC) -o $(NAME) $(CXXFLAGS)

clean:
		rm -f $(OBJ) $(OBJ_MAIN)
		rm -f *.gcno
		rm -f *.gcda

fclean:		clean
		rm -f $(NAME)
		rm -f $(TEST_NAME)

re:		fclean all

tests_run:
		$(CXX) -o $(TEST_NAME) $(CXXFLAGS) $(SRC_TEST) $(SRC) $(TEST_FLAGS)
		./$(TEST_NAME)
		gcovr --exclude tests
