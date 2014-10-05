#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

/* Template section start */

/**
* Turn a generic vector into a comma deliminated string.
*/
template<typename T>
std::string vector_to_comma_delimited_string(std::vector<T> vector) {
	std::string comma_list;
	typename std::vector<T>::iterator iterator;
	for(iterator = vector.begin(); iterator != vector.end(); iterator++) {
		if (iterator != vector.begin()) {
			comma_list += ", ";
		}
		comma_list += *iterator;
	}
	return comma_list;
}

/* Template section end */

std::string getcwd_string();

#endif