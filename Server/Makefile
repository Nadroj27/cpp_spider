##
## Makefile for  in /home/puccio_c/work/boost
##
## Made by Cyril Puccio
## Login   <cyril.puccio@epitech.eu>
##
## Started on  Fri Sep 29 14:25:53 2017 Cyril Puccio
## Last update Sun Oct  8 23:20:28 2017 Cyril Puccio
##

CC		=	g++

RM		=	rm -rf

NAME            =       Server

CXXFLAGS	+= 	-std=c++11 -W -Wall -Wextra -I./Headers

LFLAGS		 +=	-lboost_system -lpthread -lboost_thread

OBJS		=	$(SRC:.cpp=.o)

SRC		=	Src/main.cpp  \
			Src/Server.cpp  \
			Src/Connection.cpp \
			Src/DataManager.cpp \

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(SRC) -o $(NAME) $(CXXFLAGS) $(LFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONNY	:	all clean fclean re
