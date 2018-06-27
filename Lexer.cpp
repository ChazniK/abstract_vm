/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 09:05:16 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/27 11:33:59 by ckatz            ###   ########.fr       */
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

std::string Lexer::getFileName(void)
{
	return _fileName;
}

std::string Lexer::getLine(void)
{
	return _line;
}

std::vector<std::vector<std::string> >  Lexer::getListOfTokens(void)
{
	return _listOfTokens;
}

void	Lexer::setFileName(std::string fileName)
{
	this->_fileName = fileName;
}

void    Lexer::setLine(std::string line)
{
	this->_line = line;
}

void    Lexer::setListOfTokens(std::vector<std::vector<std::string> > listOfTokens)
{
	this->_listOfTokens = listOfTokens;
}
