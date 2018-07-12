/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/12 11:10:02 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

int		main(int argc, char **argv)
{
	Lexer		inputLexer;
	// Parser		inputParser;
	std::vector<std::vector<std::string> > listOfTokens;
	std::vector<Parser> listOfCommands;
	
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

	//Run the vm
	int i = 0; 
	while (i < (int)listOfTokens.size())
	{
		Parser parse;
		int j = 0;
		while (j < (int)listOfTokens[i].size())
		{
			if (j == 0)
			{
				parse.setInstruction(parse.extractInstruction(listOfTokens[i][j]));
			}
			j++;
		}
		listOfCommands.push_back(parse);
		i++;
	}

	Parser p;
	listOfCommands[0]

	// int a = 0; 
	// while (a < (int)listOfCommands.size())
	// {
	// 	Parser parse;
	// 	std::cout << parse.getInstruction() << std::endl;
	// 	a++;
	// }
	return (0);
}
