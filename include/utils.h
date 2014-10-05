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

/**
* Find out current working directory and return a C++ std::string.
*/
std::string getcwd_string();



/* SECTION: MKDIR_RECURSIVE START */

/* mkdir_recursive macro routing start */

/**
* Use 0775 as a default type for __mkdir_recursive().
*/
#define MKDIR_RECURSIVE_1(path) __mkdir_recursive(std::string(path).c_str(), 0775)

/**
* We have both args, time to call __mkdir_recursive().
*/
#define MKDIR_RECURSIVE_2(path, type) __mkdir_recursive(std::string(path).c_str(), type)

/**
* Find the function from args.
*/
#define GET_MKDIR_RECURSIVE_MACRO(_1, _2, NAME, ...) NAME

/**
* __mkdir_recursive() wrapper
*/
#define mkdir_recursive(...) GET_MKDIR_RECURSIVE_MACRO(__VA_ARGS__, MKDIR_RECURSIVE_2, MKDIR_RECURSIVE_1)(__VA_ARGS__)

/**
* Make path recursively.
*/
bool __mkdir_recursive(const char* path, mode_t type);

/* mkdir_recursive macro routing end */

/* SECTION: MKDIR_RECURSIVE END */



/* SECTION: PATH_EXISTS START */

/* path_exists types start */
#define IS_ANY			0x1000001
#define IS_DIRECTORY 	0x1000003
/* path_exists types end */

/* path_exists macro routing start */

/**
* Use IS_ANY as the type argument for __path_exists()
*/
#define PATH_EXISTS_1(path) __path_exists(std::string(path).c_str(), IS_ANY)

/**
* We have both args, time to call __path_exists().
*/
#define PATH_EXISTS_2(path, type) __path_exists(std::string(path).c_str(), type)

/**
* Find the function from args.
*/
#define GET_PATH_EXISTS_MACRO(_1, _2, NAME, ...) NAME

/**
* __path_exists() wrapper
*/
#define path_exists(...) GET_PATH_EXISTS_MACRO(__VA_ARGS__, PATH_EXISTS_2, PATH_EXISTS_1)(__VA_ARGS__)

/* path_exists macro routing end */

/**
* Find if a path of a type exists
*/
bool __path_exists(const char* path, mode_t type);

/**
*
*/
bool directory_exists(struct stat st);

/* SECTION: PATH_EXISTS END */

#endif