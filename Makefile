# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 10:06:31 by ckatz             #+#    #+#              #
#    Updated: 2018/07/17 10:57:07 by ckatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
SRCS = main.cpp Lexer.cpp Parser.cpp Calculator.cpp Int8.cpp Int16.cpp Int32.cpp Float.cpp Double.cpp OperandFactory.cpp Error.cpp
OBJS = main.o Lexer.o Parser.o Calculator.o Int8.o Int16.o Int32.o Float.o Double.o OperandFactory.o Error.o
CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
