#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

static void fixnewline(std::string &s1)
{
	size_t pos;
	std::string news1;

	while ((pos = s1.find("\\n", 0)) != std::string::npos)
	{
		news1 += s1.substr(0, pos) + "\n";
		s1 = s1.substr(pos + 2, s1.length());
	}
	news1 += s1.substr(0, s1.length());
	s1 = news1;
}


static std::string replace(std::ifstream &file, std::string s1, std::string s2)
{
	std::string str;
	std::string newStr = "";
	size_t pos;
	std::stringstream strStream;

	strStream << file.rdbuf();
	str = strStream.str();
	
	fixnewline(s1);
	std::cout << "org file:" << std::endl << str << std::endl;
	while ((pos = str.find(s1, 0)) != std::string::npos)
	{
		newStr += str.substr(0, pos) + s2;
		str = str.substr(pos + s1.length(), str.length());
	}
	newStr += str.substr(0, str.length());
	std::cout << "new file:" << std::endl << newStr << std::endl;
	return (newStr);
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
