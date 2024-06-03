#include "RPN.hpp"

static void validate_and_fill(char *argv, std::stack<char> &mstack)
{
	if (!argv)
		throw std::invalid_argument("Error: nullptr");
	while (*argv)
	{
		if (!isdigit(*argv) && *argv != '+' &&  *argv != '-' && *argv != '*' && *argv != '/')
			throw std::invalid_argument("Illegal character");
		mstack.push(*argv);
		if (*++argv == 0)
			break ;
		if (!isspace(*argv))
			throw std::invalid_argument("Missing a space");
		++argv;
	}
}

static int run(std::stack<char> &mstack)
{
	if (mstack.empty())
		throw std::invalid_argument("Error too few numbers in stack");
	char top = mstack.top();
	mstack.pop();
	if (isdigit(top))
		return (top - '0');
	if (top == '+')
		return (run(mstack) + run(mstack));
	if (top == '-')
		return (- run(mstack) + run(mstack));
	if (top == '*')
		return (run(mstack) * run(mstack));
	if (top == '/')
	{
		int tmp = run(mstack);
		return (run(mstack) / tmp);
	}
	throw std::invalid_argument("Unknown error");
	return (1337);
}
void RPN(char *argv)
{
	std::stack<char> mstack;

	try
	{
		validate_and_fill(argv, mstack);
		if (mstack.empty())
			throw std::invalid_argument("Error");
		int res = run(mstack);
		std::cout << (mstack.empty() ? std::to_string(res) : "Error") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
}