/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:57:37 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/27 17:08:57 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

enum	command { push, pop, dump, assert, add, sub, mul, div, mod, print, exit }

int		isComment(std::string line)
{

}

int		isCommand(command currentCommand)
{

	switch ()
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
			std::cout << "add found" << std::endl
			break;
		case sub:
			std::cout << "sub found" << std::endl;
			break;
		case mul:
			std::cout << "mul found" << std::endl;
			break;
		case div:
			std::cout << "div found" << std::endl;
			break;
		case mod:
			std::cout << "mod found" << std::endl;
			break;
		case print:
			std::cout << "print found" << std::endl;
			break;
		case exit:
			std::cout << "exit found" << std::endl;
			break;
		default:
			std::cout << "No command found" << std::endl;
			break;
	}
	return (0);
}
