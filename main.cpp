/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/06 09:59:34 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Int32.hpp"

int		main(int argc, char **argv)
{
	Lexer		inputLexer;
	Parser		inputParser;
	std::vector<std::vector<std::string> > listOfTokens;
	IOperand		* test =  new Int32("21.45");
	IOperand		* test2 = new Int32("21");
	std::cout << "add\n";
	IOperand const * result = *test + *test2;

	std::cout << result->toString() << std::endl;

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
		
/*	int i = 0; 
	while (i < (int)listOfTokens.size())
	{
		int j = 0;
		while (j < (int)listOfTokens[i].size())
		{
			if (inputParser.isComment(listOfTokens[i][j]))
			{
				i++;
				j = 0;
			}
			else if (inputParser.isCommand(listOfTokens[i][j]) == 1)
			{
			   j++;	
			}
			else
			{
				std::cout << "test" << std::endl;
				inputParser.getValue(listOfTokens[i][j]);
				j++;
			}
		}	
		i++;
	}*/
	return (0);
}
