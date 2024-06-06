#include "MutantStack.hpp"
#include <iostream>
#include <queue>
#include <list>

int main()
{
	std::cout << "==1. Create MutantStack, push 5 and 7, shows the top==" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(7);
	std::cout << mstack.top() << std::endl;
	std::cout << "==2. Pop the top, show the size==" << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << "==2.1  push 3, 5, 737, 0==" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "==3. Iterate through the stack and print the values==" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "==4. Create a list from the stack and print the values==" << std::endl;
	std::list<int> mylist(mstack.begin(), mstack.end());
	for (int i : mylist)
		std::cout << i << std::endl;
	
	std::cout << "==5. Create a new stack from the list and push 42 and print the values==" << std::endl;
	MutantStack<int> *newStack = new MutantStack<int>(mylist.begin(), mylist.end());
	newStack->push(42);
	for (int i : *newStack)
		std::cout << i << std::endl;

	std::cout << "==6. Copies the last stack, deletes the last stack, and print the values of the copy==" << std::endl;
	MutantStack<int> copyStack(*newStack);
	delete newStack;
	for (int i : copyStack)
		std::cout << i << std::endl;

	std::cout << "==7. Assign a new stack with the copy stack and print the values==" << std::endl;
	MutantStack<int> assignStack = copyStack;
	copyStack.push(43);
	for (int i : assignStack)
		std::cout << i << std::endl;

	return 0;
}