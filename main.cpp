/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/13 18:57:24 by ckatz            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	Lexer		inputLexer;
	Parser		inputParser;
	Calculator	calc;
	
	std::vector<std::vector<std::string> > listOfTokens;
	std::vector<Parser> listOfCommands;
	std::vector<IOperand const *> vmStack;

	std::string val = "11223344.1111";
	long double	num = stold(val);
	int8_t		n = static_cast<int8_t>(num);
	std::cout << n << std::endl;
	
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
		std::cout << "Incorrect number of arguements entered" << std::endl;
	listOfTokens = inputLexer.getListOfTokens();

	int i = 0; 
	while (i < (int)listOfTokens.size())
	{
		Parser parse;
		parse.setInstruction(parse.extractInstruction(listOfTokens[i][0]));
		if (parse.getInstruction() == "push" || parse.getInstruction() == "assert")
		{
			parse.setType(parse.extractType(listOfTokens[i][1]));
			parse.setValue(parse.extractValue(listOfTokens[i][1]));
		}
		listOfCommands.push_back(parse);
		i++;
	}

	for (int i = 0; i < listOfCommands.size(); i++)
	{
		calc.executeCommand(listOfCommands[i], vmStack);
	}
	return (0);
}
