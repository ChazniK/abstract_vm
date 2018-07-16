/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:56:57 by ckatz             #+#    #+#             */
/*   Updated: 2018/07/16 17:15:44 by ckatz            ###   ########.fr       */
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
		Parser(Parser const & src);
		
		//Parser deconstructor
		~Parser(void);

		std::string		extractInstruction(std::string instr);
		eOperandType	extractType(std::string type);
		std::string		extractValue(std::string val);

		//Getters
		std::string		getInstruction(void) const;
		eOperandType	getType(void) const;
		std::string		getValue(void) const;

		//Setters
		void			setInstruction(std::string instruction);
		void			setType(eOperandType type);
		void			setValue(std::string value);

		int				isValidNum(std::string val);

		int				exitFound = 0;

		virtual	Parser & operator=(Parser const & src);

	private:

		std::string		_instruction;
		eOperandType	_type;
		std::string		_value;
};

#endif
