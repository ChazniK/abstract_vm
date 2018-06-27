/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:53:08 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/27 11:24:04 by ckatz            ###   ########.fr       */
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
	//	Lexer(Lexer const & src);

		//Deconstructor
		~Lexer(void);

		// Getters
		std::string	getFileName(void);
		std::string	getLine(void);
		std::vector<std::vector<std::string> >	getListOfTokens(void);

		// Setters
		void	setFileName(std::string fileName);
		void	setLine(std::string line);
		void	setListOfTokens(std::vector<std::vector<std::string> > listOfTokens);
	
	private:
		
		std::string	_fileName;
		std::string	_line;
		std::vector<std::vector<std::string> >	_listOfTokens;
};

#endif
