#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &brain);
		~Brain();
		std::string getIdea(int idx) const;
		void setIdea(int idk, std::string idea);
};

#endif