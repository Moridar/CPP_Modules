#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << std::endl << "==Array tests==" << std::endl;
    std::cout << std::endl << "==1. Constructors==" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    std::cout << std::endl << "==2. Setting random values==" << std::endl;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << std::endl << "==3. Copy and Assignment==" << std::endl;
    Array<int> copy(numbers);
    Array<int> assign;
    assign = copy;

    std::cout << std::endl << "==4. Comparing values - Prints if different values==" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[50] = 0;
        if (numbers[i] != mirror[i])
            std::cerr << "Numbers[" << i << "]: " << numbers[i] << " and Mirrors[" << i << "]: " << mirror[i] << std::endl;
        if (numbers[i] != copy[i])
            std::cerr << "Numbers[" << i << "]: " << numbers[i] << " and Copy[" << i << "]: " << copy[i] << std::endl;
        if (numbers[i] != assign[i])
            std::cerr << "Numbers[" << i << "]: " << numbers[i] << " and Assign[" << i << "]: " << assign[i] << std::endl;
    }
    
    std::cout << std::endl << "==4.1 Testing copy==" << std::endl;
    copy[13]++;
    std::cout << "Numbers[13]: " << numbers[13] << " and Copy[13]: " << copy[13] << std::endl;
    
    std::cout << std::endl << "==4.2 Testing assign==" << std::endl;
    assign[14]++;
    std::cout << "Numbers[14]: " << numbers[14] <<  " and Assign[14]: " << assign[14] << std::endl;

    std::cout << std::endl << "==5. Out of range tests==" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "==6. Testing size==" << std::endl;
    std::cout << "Size of numbers: " << numbers.size() << std::endl;

    std::cout << std::endl << "==7. Testing empty==" << std::endl;
    Array<char> empty = Array<char>();
    std::cout << "Size of empty: " << empty.size() << std::endl;
    try
    {
        empty[0] = 'a';
        std::cout << "Succesfully assigned empty[0] = 'a'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Size of empty: " << empty.size() << std::endl;

    std::cout << std::endl << "==7. Deconstructors==" << std::endl;
    delete [] mirror;//
    return 0;
}