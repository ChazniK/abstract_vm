/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:56:57 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/12 14:33:44 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "IOperand.hpp"

#include <iostream>
#include <string>

class Parser
{
	public:

		//Parser default constructor
		Parser(void);
		
		//Parser deconstructor
		~Parser(void);

		std::string		extractInstruction(std::string instr) const;
		eOperandType	extractType(std::string type) const;
		std::string		extractValue(std::string val) const;

		//Getters
		std::string		getInstruction(void) const;
		eOperandType	getType(void) const;
		std::string		getValue(void) const;

		//Setters
		void			setInstruction(std::string instruction);
		void			setType(eOperandType type);
		void			setValue(std::string value);

		int				isValidOperand(std::string line);

	private:

		std::string		_instruction;
		eOperandType	_type;
		std::string		_value;
};

#endif
