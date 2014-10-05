#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <sys/stat.h>

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

/* File exists types start */
#define IS_ANY			0x1000001
#define IS_DIRECTORY 	0x1000003
/* File exists types end */

/**
*
*/
#define path_exists(path, type) __path_exists((std::string(path).c_str()), type)

/**
*
*/
bool __path_exists(const char* path, int type);
/**
*
*/
bool directory_exists(struct stat st);

#endif