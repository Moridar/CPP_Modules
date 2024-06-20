#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <exception>
#include <iostream>
#include <stack>

class RPN
{
    private:
        void    validate_and_fill(char *argv);
        int     resolve();
        bool    isempty();
        std::stack<char>    _mstack;

        RPN();
        RPN(const RPN &);
        RPN &operator=(const RPN &);
        ~RPN();
    public:
        static void calc(char *argv);
};

#endif