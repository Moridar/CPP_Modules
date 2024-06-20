#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}


void RPN::validate_and_fill(char *argv)
{
	if (!argv)
		throw std::invalid_argument("Error");
	while (isspace(*argv))
		argv++;
	while (*argv)
	{
		if (!isdigit(*argv) && *argv != '+' &&  *argv != '-' && *argv != '*' && *argv != '/')
			throw std::invalid_argument("Error");
		_mstack.push(*argv++);
		while (isspace(*argv))
			argv++;
	}
}

int RPN::resolve()
{
	if (_mstack.empty())
		throw std::invalid_argument("Error");
	char top = _mstack.top();
	_mstack.pop();
	if (isdigit(top))
		return (top - '0');
	if (top == '+')
		return (resolve() + resolve());
	if (top == '-')
	{
		int tmp = resolve();
		return (resolve() - tmp);
	}
	if (top == '*')
		return (resolve() * resolve());
	if (top == '/')
	{
		int tmp = resolve();
		return (resolve() / tmp);
	}
	throw std::invalid_argument("Unknown error");
}

bool RPN::isempty()
{
	return _mstack.empty();
}
void RPN::calc(char *argv)
{
	RPN rpn;
	try
	{
		rpn.validate_and_fill(argv);
		int res = rpn.resolve();
		if (!rpn.isempty())
			throw std::invalid_argument("Error");
		std::cout << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
}