#include <string>
#include <fstream>
#include <iostream>

static std::string replace(std::ifstream &file, std::string s1, std::string s2)
{
	std::string line;
	std::string newline = "";
	size_t pos;
	

	while (std::getline(file, line))
	{
		if (newline != "")
			newline += "\n";
		while ((pos = line.find(s1, 0)) != std::string::npos)
		{
			newline += line.substr(0, pos) + s2;
			line = line.substr(pos + s1.length(), line.length());
		}
		newline += line.substr(0, line.length());
	}
	return (newline);
}

static int	initialise(int argc, char **argv, std::ifstream &file, std::ofstream &outfile)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	if ((std::string) argv[2] == "")
	{
		std::cerr << "Error: s1 is empty" << std::endl;
		return (1);
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: infile" << std::endl;
		return (1);
	}
	outfile.open(std::string(argv[1]) + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Error: outfile" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::ofstream outfile;
	
	if (initialise(argc, argv, file, outfile))
		return (1);
	outfile << replace(file, argv[2], argv[3]);
}
