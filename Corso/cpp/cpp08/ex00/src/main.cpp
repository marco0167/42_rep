#include <vector>
#include <iostream>

#include "../class/Easyfind.hpp"

int main()
{
	std::vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	if (easyfind(g1, 1))
		std::cout << "Value found!" << std::endl;
	else
		std::cout << "Value not found!" << std::endl;
		
}
