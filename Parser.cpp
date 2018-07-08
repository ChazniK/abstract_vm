/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:57:37 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/29 12:34:19 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(void)
{
	std::cout << "Parser constructor called" << std::endl;
	return;
}

Parser::~Parser(void)
{
	std::cout << "Parser destructor called" << std::endl;
	return;
}

int     Parser::isComment(std::string line)
{
	if (line.compare(0, 1, ";") == 0)
	{
		std::cout << "----------------comment found --------------" << std::endl;
		return (1);
	}
	return (0);
}

std::string	Parser::getValue(std::string val)
{

	if (val.compare(0, 4, "int8") == 0)
	{
		val.erase(0, 5);
		val.erase(val.end() - 1);
	}
	else if (val.compare(0, 5, "int16") == 0)
	{
		val.erase(0, 6);
		val.erase(val.end() - 1);
	}
	else if (val.compare(0, 5, "int32") == 0)
	{
		val.erase(0, 6);
		val.erase(val.end() - 1);
	}
	else if (val.compare(0, 5, "float") == 0)
	{
		val.erase(0, 6);
		val.erase(val.end() - 1);
	}
	else if (val.compare(0, 6, "double") == 0)
	{
		val.erase(0, 7);
		val.erase(val.end() - 1);
	}
	else
	{
		std::cout << "value not valid" << std::endl;
		return (NULL);
	}
	return val;

}

int		Parser::isCommand(std::string currentCommand)
{
	if (currentCommand == "push")
	{
		std::cout << "push found" << std::endl;
	}
	else if (currentCommand == "pop")
	{
		std::cout << "pop found" << std::endl;
	}
	else if (currentCommand == "dump")
	{
		std::cout << "dump found" << std::endl;
	}
	else if (currentCommand == "assert")
	{
		std::cout << "assert found" << std::endl;
	}
	else if (currentCommand == "add")
	{
		std::cout << "add found" << std::endl;
	}
	else if (currentCommand == "sub")
	{
		std::cout << "sub found" << std::endl;
	}
	else if (currentCommand == "mul")
	{
		std::cout << "mul found" << std::endl;
	}
	else if (currentCommand == "div")
	{
		std::cout << "div found" << std::endl;
	}
	else if (currentCommand == "mod")
	{
		std::cout << "mod found" << std::endl;
	}
	else if (currentCommand == "print")
	{
		std::cout << "pop found" << std::endl;
	}
	else if (currentCommand == "exit")
	{
		std::cout << "pop found" << std::endl;
	}
	else
		return (0);
//	else if (currentCommand.compare(";", 0, 1) == 0)
//	{
//		std::cout << "comment found" << std:: endl;
//	}
	//else
	//	std::cout << "command not found" << std::endl;
	return (1);
}
