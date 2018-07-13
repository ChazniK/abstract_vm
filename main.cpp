/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 12:54:56 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/13 13:15:04 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

void	push(Parser parse, std::vector<IOperand const *> & vmStack)
{
	OperandFactory fact;
	IOperand const * newOperand;

	newOperand = fact.createOperand(parse.getType(), parse.getValue());
	// std::cout << newOperand->toString() << std::endl;
	vmStack.push_back(newOperand);	
}

void	pop(Parser parse, std::vector<IOperand const *> & vmStack)
{
	OperandFactory fact;
	IOperand const * poppedOperand;

	if (vmStack.size() > 0)
	{
		poppedOperand = vmStack.back();
		vmStack.pop_back();
	}
	else
		std::cout << "Error, pop on empty stack" << std::endl;
	// std::cout << "Popped: " << poppedOperand->toString() << std::endl;	
}

void	dump(std::vector<IOperand const *>  & vmStack)
{
	for (std::vector<IOperand const *>::reverse_iterator i = vmStack.rbegin(); i != vmStack.rend(); ++i)
	{
		std::cout << (*i)->toString() << std::endl;
	}
}

void	assert(Parser parse, std::vector<IOperand const *> & vmStack)
{
	IOperand const *	assertOperand;
	long double			parsedVal;
	long double			assertedVal;	

	assertOperand = vmStack.back();
	parsedVal = std::stold(parse.getValue());
	assertedVal = std::stold(assertOperand->toString());
	if ((parse.getType() == assertOperand->getType()) && (parsedVal == assertedVal))
	{
		// std::cout << "Values match" << std::endl;
		// std::cout << assertOperand->toString() << " - " << assertOperand->getType();
		// std::cout << " " << parse.getValue() << " - " << parse.getType() << std::endl;
	}
	else
	{
		std::cout << "Error values do not match" << std::endl;
	}
}

void	add(std::vector<IOperand const *> & vmStack)
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		// std::cout << "Adding" << std::endl;
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 + *val1);;
	}
}

void	sub(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		// std::cout << "Subbing" << std::endl;
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 - *val1);
	}
}

void	mul(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		// std::cout << "Multiplying" << std::endl;
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 * *val1);
	}
}

void	div(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		// std::cout << "Dividing" << std::endl;
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		if (val1->toString() == "0")
		{
			std::cout << "Divsion by 0 not possible" << std::endl;
		}
		else
			vmStack.push_back(*val2 / *val1);
	}
}

void	mod(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		// std::cout << "Modding" << std::endl;
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 % *val1);
	}
}

void	print(std::vector<IOperand const *> & vmStack)
{
	IOperand const	*assertedVal;
	long double		convertedAssert;
	char			valAsChar;

	assertedVal = vmStack.back();
	if (assertedVal->getType() == INT8)
	{
		convertedAssert = stold(assertedVal->toString());
		valAsChar = static_cast<char>(convertedAssert);
		std::cout << valAsChar << std::endl;
	}
	else
	{
		std::cout << "Error value is not of type int8" << std::endl;
	}
}

void	exit(void)
{

}



void	executeCommand(Parser parse, std::vector<IOperand const *>  & vmStack)
{
	if (parse.getInstruction() == "push")
	{
		push(parse, vmStack);
	}
	else if (parse.getInstruction() == "pop")
	{
		pop(parse, vmStack);
	}
	else if (parse.getInstruction() == "dump")
	{
		dump(vmStack);
	}
	else if (parse.getInstruction() == "assert")
	{
		assert(parse, vmStack);
	}
	else if (parse.getInstruction() == "add")
	{
		add(vmStack);
	}
	else if (parse.getInstruction() == "sub")
	{
		sub(vmStack);
	}
	else if (parse.getInstruction() == "mul")
	{
		mul(vmStack);
	}
	else if (parse.getInstruction() == "div")
	{
		div(vmStack);
	}
	else if (parse.getInstruction() == "mod")
	{
		mod(vmStack);
	}
	else if (parse.getInstruction() == "print")
	{
		print(vmStack);
	}
	else if (parse.getInstruction() == "exit")
	{
		std::cout << "Exiting" << std::endl;
	}
	else if (parse.getInstruction() == ";;")
	{

	}
}

int		main(int argc, char **argv)
{
	Lexer		inputLexer;
	Parser		inputParser;
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
		std::cout << "Incorrect number of arguements entered" << std::endl;
	listOfTokens = inputLexer.getListOfTokens();

	//Run the vm
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
		executeCommand(listOfCommands[i], vmStack);
	}
	return (0);
}
