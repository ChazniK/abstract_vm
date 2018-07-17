/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:05:16 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/17 10:52:35 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Error.hpp"

Lexer::Lexer(void)
{

}

Lexer::Lexer(Lexer const & src)
{
	if (this != &src)
	{
		*this = src;
	}
}


Lexer::~Lexer(void)
{

}

int		Lexer::getInputType(void) const
{
	return this->_inputType;
}

std::vector<std::vector<std::string> >  Lexer::getListOfTokens(void) const
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

Lexer & Lexer::operator=(Lexer const & src)
{
	this->_inputType = src.getInputType();
	this->_listOfTokens = src.getListOfTokens();

	return *this;
}