#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <exception>
#include <sstream>
#include <iomanip>


class Exchange
{
	private:
		std::map<std::string, float> _rates;
		
		void	load_rates();
		void	read_wallet(char *filename);
		void	print(std::string key, float amount);
		float	getvalue(std::string key, float amount);
		bool	is_valid_date(std::string &date);

		Exchange(Exchange &copy);
		Exchange &operator=(const Exchange &assign);
		Exchange();
		~Exchange();
	public:
		static void btc(char* filename);
};

#endif