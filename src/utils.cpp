#include <iostream>
#include <unistd.h>
#include <climits>
#include <utils.h>

std::string getcwd_string() {
	char buffer[PATH_MAX];
	return (getcwd(buffer, PATH_MAX) ? std::string(buffer) : std::string(""));
}