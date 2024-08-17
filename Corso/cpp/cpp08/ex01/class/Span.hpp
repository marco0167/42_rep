#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime> 


class Span {
	unsigned int		_maxN;
	std::vector<int>	_container;
	Span();

public:
	Span(unsigned int N);
	~Span();
	Span(const Span &rhs);
	Span &operator=(const Span &rhs);

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			addRandomNumbers(unsigned int qt);

	class OutOfSpaceExeption : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "No more space to insert number!";
			}
	};

	class NoSpanExeption : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "No span can be found!";
			}
	};
};


#endif
