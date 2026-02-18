#include "RPN.hpp"

void RPN::evaluate(const std::string& expr)
{
    std::stack<int> stack;
    std::istringstream iss(expr);
    std::string token;
    int a,b;
    
    while(iss >> token){
        if(std::isdigit(token[0]))
            stack.push(std::stoi(token));
        else if(token == "+" || token == "-" || token == "*" || token == "/"){
            if(stack.size() < 2)
                throw std::runtime_error("Invalid expression");
            b = stack.top(); 
            stack.pop();
            a = stack.top();
            stack.pop();
            if(token == "+")
                stack.push(a + b);
            else if(token == "-")
                stack.push(a - b);
            else if(token == "*")
                stack.push(a * b);
            else if(token == "/"){
                if(b == 0)
                    throw std::runtime_error("Division by zero");
                stack.push(a / b);
            }
        }
        else
            throw std::runtime_error("Invalid token: " + token);
    }
    if(stack.size() != 1)
        throw std::runtime_error("Invalid expression");
    std::cout << stack.top() << std::endl;
}

RPN::RPN() {}

RPN::RPN(const RPN& src) {(void)src;}

RPN& RPN::operator=(const RPN& src) {(void)src; return *this;}

RPN::~RPN() {}
