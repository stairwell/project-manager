#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <actions.h>
#include <utils.h>

int init(struct arguments* args) {
	std::string path = getcwd_string();

	if (path.empty()) {
		fprintf(stderr, "Failed to find current directory, exiting.\n");
		exit(1);
	}

	/* Create project directory */
	if (path_exists(path + "/.projectmanager", IS_DIRECTORY)) {
		fprintf(stderr, "Project already exists, exiting.\n");
		exit(1);
	}
	
	if (!mkdir_recursive(path + "/.projectmanager")) {

	}

}