#include "Calculator.hpp"
#include "Error.hpp"

Calculator::Calculator(void)
{

}

Calculator::~Calculator(void)
{

}

void	Calculator::push(Parser parse, std::vector<IOperand const *> & vmStack)
{
	OperandFactory fact;
	IOperand const * newOperand;

	newOperand = fact.createOperand(parse.getType(), parse.getValue());
	vmStack.push_back(newOperand);	
}

void	Calculator::pop(std::vector<IOperand const *> & vmStack)
{
	OperandFactory fact;
	IOperand const * poppedOperand;
	try
	{
		if (vmStack.size() > 0)
		{
			poppedOperand = vmStack.back();
			vmStack.pop_back();
		}
		else
			throw Error::EmtyStackException();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void	Calculator::dump(std::vector<IOperand const *> & vmStack)
{
	try
	{
		if (vmStack.size() > 0)
		{
			for (std::vector<IOperand const *>::reverse_iterator i = vmStack.rbegin(); i != vmStack.rend(); ++i)
			{
				std::cout << (*i)->toString() << std::endl;
			}
		}
		else
			throw Error::EmtyStackException();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}	
}

void	Calculator::assert(Parser parse, std::vector<IOperand const *> & vmStack)
{
	IOperand const *	assertOperand;
	long double			parsedVal;
	long double			assertedVal;	

	try
	{
		if (vmStack.size() > 0)
		{
			assertOperand = vmStack.back();
			parsedVal = std::stold(parse.getValue());
			assertedVal = std::stold(assertOperand->toString());
			if ((parse.getType() == assertOperand->getType()) && (parsedVal == assertedVal))
			{			
			}
			else
				throw Error::FalseAssertException();
		}
		else
			throw Error::EmtyStackException();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}	
}

void	Calculator::add(std::vector<IOperand const *> & vmStack)
{
	IOperand const * val1;
	IOperand const * val2;

	try
	{
		if (vmStack.size() < 2)
		{
			throw Error::TooFewValuesException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	val1 = vmStack.back();
	vmStack.pop_back();
	val2 = vmStack.back();
	vmStack.pop_back();
	vmStack.push_back(*val2 + *val1);
}

void	Calculator::sub(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	try
	{
		if (vmStack.size() < 2)
		{
			throw Error::TooFewValuesException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	val1 = vmStack.back();
	vmStack.pop_back();
	val2 = vmStack.back();
	vmStack.pop_back();
	vmStack.push_back(*val2 - *val1);
}

void	Calculator::mul(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	try
	{
		if (vmStack.size() < 2)
		{
			throw Error::TooFewValuesException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	val1 = vmStack.back();
	vmStack.pop_back();
	val2 = vmStack.back();
	vmStack.pop_back();
	vmStack.push_back(*val2 * *val1);
}

void	Calculator::div(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	try
	{
		if (vmStack.size() < 2)
		{
			throw Error::TooFewValuesException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	val1 = vmStack.back();
	vmStack.pop_back();
	val2 = vmStack.back();
	vmStack.pop_back();
	try 
	{
		if (val1->toString() == "0")
		{
			throw Error::DivisionModuloByZeroException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	vmStack.push_back(*val2 / *val1);
}

void	Calculator::mod(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	try
	{
		if (vmStack.size() < 2)
		{
			throw Error::TooFewValuesException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	val1 = vmStack.back();
	vmStack.pop_back();
	val2 = vmStack.back();
	vmStack.pop_back();
	try 
	{
		if (val1->toString() == "0")
		{
			throw Error::DivisionModuloByZeroException();
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	vmStack.push_back(*val2 % *val1);
}

void	Calculator::print(std::vector<IOperand const *> & vmStack)
{
	IOperand const	*assertedVal;
	long double		convertedAssert;
	char			valAsChar;

	try
	{
		if (vmStack.size() > 0)
		{
			assertedVal = vmStack.back();
			if (assertedVal->getType() == INT8)
			{
				convertedAssert = stold(assertedVal->toString());
				valAsChar = static_cast<char>(convertedAssert);
				std::cout << valAsChar << std::endl;
			}
			else
				throw Error::FalseAssertException();
		}
		else
			throw Error::EmtyStackException();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}	
}

void	Calculator::executeCommand(Parser parse, std::vector<IOperand const *> & vmStack)
{
	if (parse.getInstruction() == "push")
	{
		push(parse, vmStack);
	}
	else if (parse.getInstruction() == "pop")
	{
		pop(vmStack);
	}
	else if (parse.getInstruction() == "dump")
	{
		dump(vmStack);
	}
	else if (parse.getInstruction() == "assert")
	{
		assert(parse, vmStack);
	}
	else if (parse.getInstruction() == "add")
	{
		add(vmStack);
	}
	else if (parse.getInstruction() == "sub")
	{
		sub(vmStack);
	}
	else if (parse.getInstruction() == "mul")
	{
		mul(vmStack);
	}
	else if (parse.getInstruction() == "div")
	{
		div(vmStack);
	}
	else if (parse.getInstruction() == "mod")
	{
		mod(vmStack);
	}
	else if (parse.getInstruction() == "print")
	{
		print(vmStack);
	}
	else if (parse.getInstruction() == "exit")
	{
		std::exit(EXIT_FAILURE);
	}
	else if (parse.getInstruction() == ";;")
	{
		std::cout << "Done reading from the std::in" << std::endl;
	}
}