/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:57:37 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/13 18:57:26 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(void)
{
	// std::cout << "Parser constructor called" << std::endl;
	return;
}

Parser::~Parser(void)
{
	// std::cout << "Parser destructor called" << std::endl;
	return;
}

std::string	Parser::extractInstruction(std::string currentCommand) const
{
	std::string command;

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
	}
	else
	{
		std::cout << "Command not found" << std::endl;
		return ("");
	}
	return (command);
}

eOperandType	Parser::extractType(std::string type) const
{
	eOperandType	currentType;

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
		std::cout << "value not valid" << std::endl;
	}
	return (currentType);
}

std::string	Parser::extractValue(std::string val) const
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
		return ("");
	}
	if ()
	return val;
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