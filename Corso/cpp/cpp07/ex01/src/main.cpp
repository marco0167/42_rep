#include "../class/Iter.hpp"

int main()
{
	int arr[3] = {1, 14, 4};
	std::string arr2[3] = {"Ciao", "Prova", "Hello"};

	iter(arr, 3, &print);
	iter(arr2, 3, &print);
}
