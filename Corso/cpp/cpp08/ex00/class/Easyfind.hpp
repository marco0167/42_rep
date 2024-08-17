#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>

template <typename T>
bool	easyfind(T container, int val) {
	if (std::find(container.begin(), container.end(), val) != container.end())
		return true;
	return false;
}

#endif
