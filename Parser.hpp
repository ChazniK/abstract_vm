/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 15:56:57 by ckatz             #+#    #+#             */
/*   Updated: 2018/06/27 17:09:00 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

class Parser
{
	public:

		//Parser default constructor
		Parser(void);
		
		//Parser deconstructor
		~Parser(void);

		int		isComment(std::string line);
		int		isCommand(std::string line);
		int		isValidExit(std::string line);

		//int		singleInstrOnLine(std::string line);
		//int		validExit(std::string, int fd);		

	private:

};

#endif
