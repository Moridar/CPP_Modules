#include "Span.cpp"

int main()
{
	std::cout << "==1. Initailise span of 11==" << std::endl;
	Span span(11);

	std::cout << std::endl << "==2. Testing Empty Span==" << std::endl;
	try
	{
		span.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "== 3. Testing single element, adds number 1337 to Span==" << std::endl;
	span.addNumber(1337);
	try
	{
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "== 4. Adding numbers 0 - 9 to span and test shortest/longest span==" << std::endl;
	for(int i = 0; i < 10; i++)
		span.addNumber(i);
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	
	std::cout << std::endl << "==5. Adding 12th number==" << std::endl;
	try
	{
		span.addNumber(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==6. Assigns new Span with size of 100.000==" << std::endl;
	span = Span(100000);

	std::cout << std::endl << "==7. Adds 100.000 random numbers to span==" << std::endl;
	span.addNumbers(100000);

	std::cout << std::endl << "==8. Shortest and Longest Span==" << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	
	std::cout << std::endl << "==9. Make a copy of span, adds another 100.000 random numbers to the copy==" << std::endl;
	Span copy(span);
	try
	{
		copy.addNumbers(100000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}