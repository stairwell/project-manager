#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <libconfig.h++>
#include <actions.h>
#include <manifest.h>
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
		fprintf(stderr, "Failed to create project, exiting.\n");
		exit(1);
	}

	if (!pm::manifest::create_new_manifest(path + "/.projectmanager/manifest")) {
		fprintf(stderr, "Failed to create project manifest, exiting.\n");
		exit(1);
	}
}