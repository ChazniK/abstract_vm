/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:53:08 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/27 09:32:03 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

class Lexer
{
	public:

		// Getters
		std::string	getFileName(void);
		std::string	getLine(void);
		std::vector<std::vector<std::string> >	getListOfTokens(void);

		// Setters
		void	setFileName(std::string fileName);
		void	setLine(std::string line);
		void	setListOftokens();

	
	private:
		
		std::string	_fileName;
		std::string	_line;
		std::vector<std::vector<std::string> >	_listOfTokens;
};

#endif
