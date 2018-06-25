/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/25 18:56:12 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

enum command { push, pop, dump, assert, add, sub, mul, di, mod , print, exi };

// Checks if line parsed is a comment
int		isComment(std::string line)
{
	if(line.compare(0, 1, ";") == 0)
	{
		std::cout << "Comment found" << std::endl;
	}
	return (0);
}

int		isCommand(command currentCommand)
{

	switch (currentCommand)
	{
		case push:
			std::cout << "push found" << std::endl;
			break;
		case pop:
			std::cout << "pop found" << std::endl;
			break;
		case dump:
			std::cout << "dump found" << std::endl;
			break;
		case assert:
			std::cout << "assert found" << std::endl;
			break;
		case add:
			std::cout << "add found" << std::endl;
			break;
		case sub:
			std::cout << "sub found" << std::endl;
			break;
		case mul:
			std::cout << "mul found" << std::endl;
			break;
		case di:
			std::cout << "div found" << std::endl;
			break;
		case mod:
			std::cout << "mod found" << std::endl;
			break;
		case print:
			std::cout << "print found" << std::endl;
			break;
		case exi:
			std::cout << "exit found" << std::endl;
			break;
		default:
			std::cout << "No command found" << std::endl;
			break;			
	}
	return (0);
}

/*
int		checkOperandType(std::string line)
{
}

int		checkValue(std::string line)
{
}

//Checks that there is only one instruction on each line
int		singleInstrOnLine(std::string line)
{

}

std::string[] tokenizeLine(std::string line)
{

}
*/

std::string	trimSpace(const std::string &str)
{
	auto	start = str.begin();
	auto	end = str.end();
	while (start != end && std::isspace(*start))
	{
		start++;
	}
	return std::string(start, end + 1);
}

int		main(int argc, char **argv)
{
	std::string	fileName;
	std::string	line;
	std::string trimLine;
//	std::string	instruction;
//	std::string	value;

	// Read in instructions from the std::in
	if (argc == 1)
	{
		std::cout << "Implement reading from the std::in" << std::endl;
	}
	// Read in instructions from text file
	else if (argc == 2)
	{
		fileName = argv[1];
		std::ifstream input(fileName);

		if (!input)
		{
			std::cout << "Error, can not open input file " << fileName << std::endl;
		}
		else
		{
			while (input)
			{
				std::getline(input, line);
				std::cout << line << std::endl;
				trimLine = trimSpace(line);

				//isComment(trimLine);

			}
		}
	}
	else
		std::cout << "Incorrect number of arguements entered" << std::endl;
	return (0);
}
