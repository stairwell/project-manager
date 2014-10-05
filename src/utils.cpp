#include <iostream>
#include <unistd.h>
#include <climits>
#include <utils.h>

/**
*
*/
std::string getcwd_string() {
	char buffer[PATH_MAX];
	return (getcwd(buffer, PATH_MAX) ? std::string(buffer) : std::string(""));
}


/**
*
*/
bool __path_exists(const char* path, int type) {
	struct stat st;

	if (stat(path, &st) != 0) {
		return false;
	}

	switch(type) {
		case IS_DIRECTORY:
			return directory_exists(st);
		case IS_ANY:
			return true;
		default:
			return st.st_mode & type;
	}
	
	return false;
}

/**
*
*/
bool directory_exists(struct stat st) {
	return (st.st_mode & S_IFMT) == S_IFDIR;
}