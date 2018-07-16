/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:05:16 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 06:06:05 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Error.hpp"

Lexer::Lexer(void)
{
	std::cout << "Default lexer constructor called" << std::endl;
	return ;
}

Lexer::~Lexer(void)
{
	std::cout << "Lexer destructor called" << std::endl;
	return ;
}

int		Lexer::getInputType(void)
{
	return this->_inputType;
}

std::vector<std::vector<std::string> >  Lexer::getListOfTokens(void)
{
	return this->_listOfTokens;
}

void	Lexer::setInputType(int inputType)
{
	this->_inputType = inputType;
}

void	Lexer::setListOfTokens(std::vector<std::vector<std::string> > listOfTokens)
{
	this->_listOfTokens = listOfTokens;
}

void    Lexer::readFromStdin(void)
{
	std::string line;
	std::string token;
	std::vector<std::vector<std::string> > listOfTokens;

	std::cout << "Implement reading from the std::in" << std::endl;
	
	while (getline(std::cin, line, '\n'))
	{
		if (line == "")
			continue;
		std::istringstream is(line);
		std::vector<std::string> tokens;
		int		count = 0;

		while (is >> std::skipws >> token)
		{ 
			if (token.compare(0, 1, ";") == 0 && token.compare(0, 2, ";;") != 0)
				break;
			tokens.push_back(token);
		}
		// std::cout << "count:" << count << std::endl;
		try
		{
			if (count > 2)
			{
				throw Error::ParserException();
			}
		}
		catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
			std::exit(EXIT_FAILURE);
		}
		if (!tokens.empty())
		{
			listOfTokens.push_back(tokens);
			if (tokens[0].compare(0, 2, ";;") == 0)
				break;
		}
   	}
	setListOfTokens(listOfTokens);
}

void	Lexer::readFromFile(std::string fileName)
{
	std::string line;
	std::vector<std::vector<std::string> > listOfTokens;
	std::ifstream input(fileName);
	
	if (!input)
	{
		std::cout << "Error, can not open input file " << fileName << std::endl;
	}
   	else
	{
		while (getline(input, line, '\n'))
		{
			std::string token;
			std::vector<std::string> tokens;
			int		count = 0;

			if (line == "")
				continue;
			std::istringstream is(line);
			while (is >> token)
			{
				if (token.compare(0, 1, ";") == 0)
					break;
				tokens.push_back(token);
				count++;
			}
			// std::cout << "count:" << count << std::endl;
			try
			{
				if (count > 2)
				{
					throw Error::ParserException();
				}
			}
			catch(std::exception & e)
			{
				std::cout << e.what() << std::endl;
				std::exit(EXIT_FAILURE);
			}
			if (!tokens.empty())
			{
				listOfTokens.push_back(tokens);
			}
		}
	}
	setListOfTokens(listOfTokens);
}