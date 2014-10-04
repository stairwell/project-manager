#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <list>
#include <map>
#include <argp.h>
#include <config.h>

/**
*
*/
void arguments_pre(struct arguments* arguments);

/**
*
*/
void arguments_post(struct arguments* arguments);

/**
*
*/
int parse_args(int key, char* arg, struct argp_state* state);

/**
*
*/
const char args_doc[] = "[ACTION] [ARGS]";

/**
*
*/
const char doc[] = "A project manager.";

/**
*
*/
struct arguments {
	std::list<std::string> args;
	std::map<std::string, std::string> options;
};

/**
*
*/
struct argp_option options[] = {
	{"verbose", 'v', 0, 0, "Produce verbose output."},
	{0}
};

/**
*
*/
struct argp argp = {
	/* */
	options,
	/* */
	parse_args,
	/* */
	args_doc,
	/* */
	doc
};

/**
* Package name and version.
* Is there a better way to do this?
*/
const char* argp_program_version = PACKAGE_NAME "-" PACKAGE_VERSION;

/**
*
*/
const char* argp_program_bug_address = "<" PACKAGE_BUGREPORT ">";

#endif
