/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:53:08 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/27 16:32:05 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

class Lexer
{
	public:

		//Constructors
		Lexer(void);

		//Deconstructor
		~Lexer(void);

		// Getters
		int		getInputType(void);
		std::vector<std::vector<std::string> >	getListOfTokens(void);

		// Setters
		void	setInputType(int inputType);
		void	setListOfTokens(std::vector<std::vector<std::string> > listOfTokens);

		//Functions to read and tokenize file or input from std::in
		void    readFromStdin(void);
		void    readFromFile(std::string fileName);

	private:
		
		int		_inputType;
		std::vector<std::vector<std::string> >	_listOfTokens;
};

#endif
