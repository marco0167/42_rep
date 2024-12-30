#include "./Span.hpp"

Span::Span(unsigned int N) : _maxN(N), _container() {}

Span::~Span()
{
}

Span::Span(const Span &rhs)
{
	*this = rhs;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_maxN = rhs._maxN;
		this->_container = rhs._container;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_container.size() < this->_maxN)
		this->_container.push_back(n);
	else
		throw OutOfSpaceExeption();
}

unsigned int Span::longestSpan()
{
	unsigned int max = 0;
	unsigned int tmp;

	if (this->_container.size() > 1)
	{
		for (unsigned int i = 0; i < this->_container.size() - 1; i++)
		{
			tmp = std::abs(this->_container[i] - this->_container[i + 1]);
			if (tmp > max)
				max = tmp;
		}
		return max;
	}
	else
		throw NoSpanExeption();
}

unsigned int Span::shortestSpan()
{
	unsigned int min = 0;
	unsigned int tmp;

	if (this->_container.size() > 1)
	{
		min = std::abs(this->_container[0] - this->_container[1]);
		for (unsigned int i = 1; i < this->_container.size() - 1; i++)
		{
			tmp = std::abs(this->_container[i] - this->_container[i + 1]);
			if (tmp < min)
				min = tmp;
		}
		return min;
	}
	else
		throw NoSpanExeption();
}

void Span::addRandomNumbers(unsigned int qt)
{
	try
	{
		srand(static_cast<unsigned>(time(NULL)));

		for (unsigned int i = 0; i < qt; i++)
		{
			addNumber(rand());
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
