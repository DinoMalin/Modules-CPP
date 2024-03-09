#pragma once
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int search) {
	typename T::iterator it = std::find(container.begin(), container.end(), search);
	if (it != container.end())
		return it;
	else
		throw std::out_of_range("No occurence found.");
}