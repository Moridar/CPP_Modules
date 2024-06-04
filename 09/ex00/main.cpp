#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (Exchange::btc(NULL), 1);
	Exchange::btc(argv[1]);
}