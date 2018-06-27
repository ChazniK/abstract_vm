# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 10:06:31 by ckatz             #+#    #+#              #
#    Updated: 2018/06/27 11:49:06 by ckatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm
SRCS = main.cpp Lexer.cpp
OBJS = main.o Lexer.o
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -Wno-c++11-extensions

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
