#include "Calculator.hpp"

Calculator::Calculator(void)
{

}

Calculator::Calculator(Calculator const & src)
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
	std::cout << "Creating " << newOperand->getType() << " - " << newOperand->toString() << std::endl;
	vmStack.push_back(newOperand);	
}

void	Calculator::pop(Parser parse, std::vector<IOperand const *> & vmStack)
{
	OperandFactory fact;
	IOperand const * poppedOperand;

	if (vmStack.size() > 0)
	{
		poppedOperand = vmStack.back();
		vmStack.pop_back();
	}
	else
		std::cout << "Error, pop on empty stack" << std::endl;
}

void	Calculator::dump(std::vector<IOperand const *> & vmStack)
{
	if (vmStack.size() > 0)
	{
		for (std::vector<IOperand const *>::reverse_iterator i = vmStack.rbegin(); i != vmStack.rend(); ++i)
		{
			std::cout << (*i)->toString() << std::endl;
		}
	}
	else
		std::cout << "Dump on empty stack" << std::endl;
}

void	Calculator::assert(Parser parse, std::vector<IOperand const *> & vmStack)
{
	IOperand const *	assertOperand;
	long double			parsedVal;
	long double			assertedVal;	

	if (vmStack.size() > 0)
	{
		assertOperand = vmStack.back();
		parsedVal = std::stold(parse.getValue());
		assertedVal = std::stold(assertOperand->toString());
		if ((parse.getType() == assertOperand->getType()) && (parsedVal == assertedVal))
		{
			
		}
		else
		{
			std::cout << "Error values do not match" << std::endl;
		}
	}
	else
		std::cout << "Assert on empty stack" << std::endl;
}

void	Calculator::add(std::vector<IOperand const *> & vmStack)
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 + *val1);;
	}
}

void	Calculator::sub(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 - *val1);
	}
}

void	Calculator::mul(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 * *val1);
	}
}

void	Calculator::div(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		if (val1->toString() == "0")
		{
			std::cout << "Divsion by 0 not possible" << std::endl;
		}
		else
			vmStack.push_back(*val2 / *val1);
	}
}

void	Calculator::mod(std::vector<IOperand const *> & vmStack)	
{
	IOperand const * val1;
	IOperand const * val2;

	if (vmStack.size() < 2)
	{
		std::cout << "Error less than two values on stack" << std::endl;
	}
	else
	{
		val1 = vmStack.back();
		vmStack.pop_back();
		val2 = vmStack.back();
		vmStack.pop_back();
		vmStack.push_back(*val2 % *val1);
	}
}

void	Calculator::print(std::vector<IOperand const *> & vmStack)
{
	IOperand const	*assertedVal;
	long double		convertedAssert;
	char			valAsChar;

	if (vmStack.size() > 0)
	{
		assertedVal = vmStack.back();
		std::cout << assertedVal->getType() << " - " << assertedVal->toString() << std::endl;
		if (assertedVal->getType() == INT8)
		{
			convertedAssert = stold(assertedVal->toString());
			std::cout << convertedAssert << std::endl;
			valAsChar = static_cast<char>(convertedAssert);
			std::cout << valAsChar << std::endl;
		}
		else
		{
			std::cout << "Error value is not of type int8" << std::endl;
		}
	}
	else
		std::cout << "Error print on empty stack" << std::endl;
}

// void	Calculator::exit(void)
// {

// }

void	Calculator::executeCommand(Parser parse, std::vector<IOperand const *> & vmStack)
{
	if (parse.getInstruction() == "push")
	{
		push(parse, vmStack);
	}
	else if (parse.getInstruction() == "pop")
	{
		pop(parse, vmStack);
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
		std::cout << "Exiting" << std::endl;
	}
	else if (parse.getInstruction() == ";;")
	{

	}
}