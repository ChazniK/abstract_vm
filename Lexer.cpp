/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:05:16 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/29 09:19:15 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

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
		std::istringstream is(line);
		std::vector<std::string> tokens;
		while (is >> token)
		{ 
			tokens.push_back(token);
		}
		listOfTokens.push_back(tokens);
		if (token == ";;")
			break;
   	}
	setListOfTokens(listOfTokens);
}

void	Lexer::readFromFile(std::string fileName)
{
	std::string line;
	std::string token;
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
			std::istringstream is(line);
			std::vector<std::string> tokens;
			while (is >> token)
			{
				tokens.push_back(token);
			}
			listOfTokens.push_back(tokens);
		}
	}
	setListOfTokens(listOfTokens);
}
