
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept> //get rid of this and change to standard execption

template <typename T>
typename T::const_iterator easyfind(const T& container, int value)  //using reference bcs no modifiyng
{
	typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("easyfind: value not found"); //change exceotion to standard 
	return it;
}

#endif
