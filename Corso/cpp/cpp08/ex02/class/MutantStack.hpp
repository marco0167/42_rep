#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template< class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {

public:
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack& rhs) {*this = rhs;}
	MutantStack&	operator=(const MutantStack& rhs) {
		std::stack<T, Container>::operator=(rhs);
		return *this;
	}

	typedef typename Container::iterator	iterator;

	iterator	begin() {return this->c.begin();}
	iterator	end() {return this->c.end();}

};

#endif
