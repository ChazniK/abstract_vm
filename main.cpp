/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:58:41 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/22 17:11:10 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int			main(int argc, char **argv)
{
	std::string	fileName;
	std::string	line;
	std::string	instruction;
	std::string	value;

	// Reading the input from the std::in
	if (argc == 1)
	{

	}
	// Reading the input from the text file
	else if (argc == 2)
	{
		fileName = argv[1];
		std::ifstream inFile(fileName);
		while (inFile)
		{
			inFile >> instruction;
			if (instruction == "push" || instruction == "assert")
			{
				inFile >> value;
				std::cout  <<  instruction << " " << value << std::endl;
			}
			else
			{
				if (inFile)
				{
					std::cout << "Instruction : " <<  instruction << std::endl;
				}
			}
		}
	}
	// Invalid number of arguements entered
	else
	{
		std::cout << "Error, invalid number of arguements entered" << std::endl;
		return (1);
	}
	return (0);
}
