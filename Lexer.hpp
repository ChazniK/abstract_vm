/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:53:08 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/30 12:29:31 by ckatz            ###   ########.fr       */
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
		Lexer(Lexer const & src);

		//Deconstructor
		~Lexer(void);

		// Getters
		int		getInputType(void) const;
		std::vector<std::vector<std::string> >	getListOfTokens(void) const;

		// Setters
		void	setInputType(int inputType);
		void	setListOfTokens(std::vector<std::vector<std::string> > listOfTokens);

		//Functions to read and tokenize file or input from std::in
		void    readFromStdin(void);
		void    readFromFile(std::string fileName);

		Lexer & operator=(Lexer const & src);

	private:
		
		int		_inputType;
		std::vector<std::vector<std::string> >	_listOfTokens;
};

#endif
