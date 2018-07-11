/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/11 18:10:53 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
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
	// IOperand		* test =  new Double("15.01", DOUBLE);
	// IOperand		* test2 = new Double("10.32", DOUBLE);
	
	// IOperand const * result = *test - *test2;

	// std::cout << result->toString() << std::endl;
	// std::cout << result->getType() << std::endl;

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
		int j = 0;
		while (j < (int)listOfTokens[i].size())
		{
			std::cout << listOfTokens[i][j] << " ";
			j++;
		}	
		std::cout << "\n";
		i++;
	}
	return (0);
}
