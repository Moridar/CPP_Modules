#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class ICharacter
{
	public:
		virtual ~ICharacter();
		ICharacter();
		ICharacter(const ICharacter &icharacter);
		ICharacter &operator=(const ICharacter &icharacter);	

};

#endif