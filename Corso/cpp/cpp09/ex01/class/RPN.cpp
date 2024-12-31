#include "./RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &rhs)
{
  *this = rhs;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rhs)
{
  if (this != &rhs)
  {
    _stack = rhs._stack;
  }
  return *this;
}

bool RPN::isOperator(char c) const
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char op, int a, int b) const
{
  switch (op)
  {
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0)
      throw std::runtime_error("Division by zero");
    return a / b;
  default:
    return a + b;
  }
}

int RPN::evaluate(const std::string &expression)
{
  std::istringstream iss(expression);
  std::string token;

  while (iss >> token)
  {
    if (token.size() == 1 && isOperator(token[0]))
    {
      if (_stack.size() < 2)
        throw std::runtime_error("Invalid expression");
      int b = _stack.top();
      _stack.pop();
      int a = _stack.top();
      _stack.pop();
      _stack.push(performOperation(token[0], a, b));
    }
    else if (std::isdigit(token[0]) && token.size() == 1)
    {
      _stack.push(token[0] - '0');
    }
    else
    {
      throw std::runtime_error("Invalid token");
    }
  }

  if (_stack.size() != 1)
    throw std::runtime_error("Invalid expression");

  return _stack.top();
}
