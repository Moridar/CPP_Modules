#include "RPN.hpp"

static void validate_and_fill(char *argv, std::stack<char> &mstack)
{
	if (!argv)
		throw std::invalid_argument("Error");
	while (isspace(*argv))
		argv++;
	while (*argv)
	{
		if (!isdigit(*argv) && *argv != '+' &&  *argv != '-' && *argv != '*' && *argv != '/')
			throw std::invalid_argument("Error");
		mstack.push(*argv++);
		while (isspace(*argv))
			argv++;
	}
}

static int resolve(std::stack<char> &mstack)
{
	if (mstack.empty())
		throw std::invalid_argument("Error");
	char top = mstack.top();
	mstack.pop();
	if (isdigit(top))
		return (top - '0');
	if (top == '+')
		return (resolve(mstack) + resolve(mstack));
	if (top == '-')
		return (- resolve(mstack) + resolve(mstack));
	if (top == '*')
		return (resolve(mstack) * resolve(mstack));
	if (top == '/')
	{
		int tmp = resolve(mstack);
		return (resolve(mstack) / tmp);
	}
	throw std::invalid_argument("Unknown error");
}
void RPN(char *argv)
{
	std::stack<char> mstack;

	try
	{
		validate_and_fill(argv, mstack);
		int res = resolve(mstack);
		if (!mstack.empty())
			throw std::invalid_argument("Error");
		std::cout << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
}