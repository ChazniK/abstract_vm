/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:57:37 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 17:40:59 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Error.hpp"
#include <sstream>

Parser::Parser(void)
{
	
}

Parser::Parser(Parser const & src)
{
	std::cout << "Copy" << "\n";
	if (this != &src)
	{
		*this = src;
	}
}

Parser::~Parser(void)
{
	
}

std::string	Parser::extractInstruction(std::string currentCommand)
{
	std::string command;

	try
	{
		if (currentCommand == "push")
		{
			command = currentCommand;
		}
		else if (currentCommand == "pop")
		{
			command = currentCommand;
		}
		else if (currentCommand == "dump")
		{
			command = currentCommand;
		}
		else if (currentCommand == "assert")
		{
			command = currentCommand;
		}
		else if (currentCommand == "add")
		{
			command = currentCommand;
		}
		else if (currentCommand == "sub")
		{
			command = currentCommand;
		}
		else if (currentCommand == "mul")
		{
			command = currentCommand;
		}
		else if (currentCommand == "div")
		{
			command = currentCommand;
		}
		else if (currentCommand == "mod")
		{
			command = currentCommand;
		}
		else if (currentCommand == "print")
		{
			command = currentCommand;
		}
		else if (currentCommand == "exit")
		{
			command = currentCommand;
			exitFound = 1;	
		}
		else if (currentCommand == ";;")
		{
			command = currentCommand;
		}
		else
		{
			throw Error::UnknownInstructionException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (command);
}

eOperandType	Parser::extractType(std::string type)
{
	eOperandType	currentType;

	try
	{
		if (type.compare(0, 4, "int8") == 0)
		{
			currentType = INT8;
		}
		else if (type.compare(0, 5, "int16") == 0)
		{
			currentType = INT16;
		}
		else if (type.compare(0, 5, "int32") == 0)
		{
			currentType = INT32;
		}
		else if (type.compare(0, 5, "float") == 0)
		{
			currentType = FLOAT;
		}
		else if (type.compare(0, 6, "double") == 0)
		{
			currentType = DOUBLE;
		}
		else
		{
			throw Error::InvalidOperandException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (currentType);
}

std::string	Parser::extractValue(std::string val)
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
	try
	{
		if (isValidNum(val) == 0)
		{
			throw Error::ParserException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (val);
}

int			Parser::isValidNum(std::string val)
{
	long double	num;

	std::stringstream stream(val);
	if (stream >> num)
	{
		return (1);
	}
	return (0);
}


std::string	Parser::getInstruction(void) const
{
	return this->_instruction;
}

eOperandType Parser::getType(void) const
{
	return this->_type;
}

std::string	Parser::getValue(void) const
{
	return this->_value;
}

void		Parser::setInstruction(std::string instruction)
{
	this->_instruction = instruction;
}

void		Parser::setType(eOperandType type)
{
	this->_type = type;
}

void		Parser::setValue(std::string value)
{
	this->_value = value;
}

Parser & Parser::operator=(Parser const & src)
{
	std::cout << "assing" << std::endl;
	this->_instruction = src.getInstruction();
	this->_type = src.getType();
	this->_value = src.getValue();

	return *this;
}