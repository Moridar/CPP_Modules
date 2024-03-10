#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	std::ofstream output_file(std::string(argv[1]) + ".replace");
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;

	while (std::getline(file, line))
	{
		std::string newline = "";
		size_t start = 0;
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			newline += line.substr(start, pos) + s2;
			pos += s1.length();
			start = pos;
		}
		newline += line.substr(start, pos);
		output_file << line << std::endl;
	}
}