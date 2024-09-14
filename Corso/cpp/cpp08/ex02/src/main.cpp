#include "../class/MutantStack.hpp"

#include <iostream>


int main () {
	MutantStack<int> mstack;
	MutantStack<int> mstack2;

	mstack.push(5);
	mstack.push(17);

	mstack2.push(3);
	mstack2.push(5);
	mstack2.push(737);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout <<  "stack 1 size:" << mstack.size() << std::endl;

	mstack.swap(mstack2);

	std::cout << "stack 1 size:" <<  mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(128);
	mstack.push(111);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	std::stack<int> s(mstack);

	return 0;
}
