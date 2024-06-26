#include "BitcoinExchange.hpp"

void Exchange::btc(char* filename)
{
	Exchange ex;

	try
	{
		std::ifstream file = ex.load_wallet(filename);
		ex.load_rates();
		ex.read_wallet(file);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
}

Exchange::Exchange()
{
	// std::cout << "Constructor called" << std::endl;
}

Exchange::~Exchange()
{
	// std::cout << "Deconsturctor called" << std::endl;
}

std::ifstream Exchange::load_wallet(char *filename)
{
	if (!filename)
		throw std::invalid_argument("no file");
	std::ifstream file(filename);
	if (!file)
		throw std::invalid_argument("unable to open file");
	return (file);
}

void Exchange::load_rates()
{
	std::string line, key;
	float rate;

	std::ifstream file("data.csv");
	if (!file)
		throw std::invalid_argument("unable to open data.csv");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (!std::getline(iss, key, ',') || !(iss >> rate))
			throw std::invalid_argument("data.csv: bad syntax => " + line);
		if (!is_valid_date(key))
			throw std::invalid_argument("data.csv: invalid date => " + line);
		_rates.insert(std::make_pair(key, rate));
	}
	file.close();
}

void Exchange::read_wallet(std::ifstream &file)
{
	std::string line, key;
	float amount;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (!std::getline(iss, key, '|') || !(iss >> amount))
			std::cout << "Error: bad input => " << line << std::endl;
		else
			print(key, amount);
	}
	file.close();
}

void Exchange::print(std::string &key, float &amount)
{
	key.erase(key.find_last_not_of(" \t\r") + 1);
		
	if (!is_valid_date(key))
		std::cout << "Error: bad date => " << key << std::endl;
	else if (amount < 0 || amount > 1000)
		std::cout << "Error: " << (amount < 0 ? "not a positive number" : "too large a number") << std::endl;
	else
		std::cout << key << " => " << amount << " = " << getvalue(key, amount) << std::endl;
}

float Exchange::getvalue(std::string key, float amount)
{
	auto it = _rates.lower_bound(key);
	if (it->first != key)
		if (it-- == _rates.begin())
			return (0);
	return (it->second * amount);
}

bool Exchange::is_valid_date(std::string &date)
{
	std::tm tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	return (ss.eof() && !ss.fail());
}