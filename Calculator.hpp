#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "Parser.hpp"
#include <vector>

class Calculator
{
  public:

	Calculator(void);
	Calculator(Calculator const & src);
	~Calculator(void);
  
  	void	push(Parser parse, std::vector<IOperand const *> & vmStack);
	void	pop(Parser parse, std::vector<IOperand const *> & vmStack);
	void	dump(std::vector<IOperand const *> & vmStack);
	void	assert(Parser parse, std::vector<IOperand const *> & vmStack);
	void	add(std::vector<IOperand const *> & vmStack);
	void	sub(std::vector<IOperand const *> & vmStack);
	void	mul(std::vector<IOperand const *> & vmStack);
	void	div(std::vector<IOperand const *> & vmStack);
	void	mod(std::vector<IOperand const *> & vmStack);
	void	print(std::vector<IOperand const *> & vmStack);
	void	executeCommand(Parser parse, std::vector<IOperand const *> & vmStack);
	// void	exit(void);

	Calculator & operator=(Calculator const & src);
};

#endif