#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cerrno>
#include <sys/stat.h>
#include <unistd.h>
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
bool __mkdir_recursive(const char* path, mode_t type = 0775) {
	size_t pre = 0, pos;
	std::string path_str(path);
	std::string dir;
	int ret;

	if (path_str[path_str.size() - 1] != '/') {
		path_str += '/';
	}

	while((pos = path_str.find_first_of('/', pre)) != std::string::npos) {
		dir = path_str.substr(0, pos++);
		pre = pos;

		if (dir.size() == 0) {
			continue;
		}

		if ((ret = mkdir(dir.c_str(), type)) && errno != EEXIST) {
			return ret;
		}
	}
	return ret;
}


/**
*
*/
bool __path_exists(const char* path, mode_t type = IS_ANY) {
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