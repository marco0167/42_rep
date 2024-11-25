#include "../class/Iter.hpp"

void print(int &i)
{
	std::cout << i << std::endl;
}

void print(std::string &i)
{
	std::cout << i << std::endl;
}

int main()
{
	int arr[3] = {1, 14, 4};
	std::string arr2[3] = {"Ciao", "Prova", "Hello"};

	iter(arr, 3, &print);
	iter(arr2, 3, &print);
}
