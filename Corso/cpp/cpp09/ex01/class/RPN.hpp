#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <iostream>

class RPN
{
  std::stack<int> _stack;

  bool isOperator(char c) const;
  int performOperation(char op, int a, int b) const;

public:
  RPN();
  RPN(const RPN &rhs);
  ~RPN();
  RPN &operator=(const RPN &rhs);

  int evaluate(const std::string &expression);
};

#endif
