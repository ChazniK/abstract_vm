/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/17 11:48:00 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Calculator.hpp"
#include "Error.hpp"

int		main(int argc, char **argv)
{
	Lexer		inputLexer;
	Parser		parse;
	Calculator	calc;
	
	std::vector<std::vector<std::string> > listOfTokens;
	std::vector<Parser> listOfCommands;
	std::vector<IOperand const *> vmStack;
	
	// Read in instructions from the std::in
	if (argc == 1)
	{
		inputLexer.setInputType(0);
		inputLexer.readFromStdin();
	}
	// Read in instructions from text file
	else if (argc == 2)
	{
		inputLexer.setInputType(1);
		inputLexer.readFromFile(argv[1]);
	}
	else
	{
		std::cout << "Incorrect number of arguements entered" << std::endl;
		return (-1);
	}
	listOfTokens = inputLexer.getListOfTokens();

	for (int i = 0; i < (int)listOfTokens.size(); i++)
	{
		parse.setInstruction(parse.extractInstruction(listOfTokens[i][0]));
		if (parse.getInstruction() == "push" || parse.getInstruction() == "assert")
		{
			parse.setType(parse.extractType(listOfTokens[i][1]));
			parse.setValue(parse.extractValue(listOfTokens[i][1]));
		}
		if (parse.getInstruction() == "exit")
		{
			break;
		}
		listOfCommands.push_back(parse);
	}
	try 
	{
		if (parse.exitFound == 0)
		{
			throw Error::NoExitException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < (int)listOfCommands.size(); i++)
	{
		calc.executeCommand(listOfCommands[i], vmStack);
	}
	return (0);
}
