#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <vector>
#include <map>
#include <argp.h>
#include <config.h>

#define DEBUG 1

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
static const char args_doc[] = "[ACTION] [ARGS]";

/**
*
*/
static const char doc[] = "A project manager.";

/**
*
*/
struct arguments {
	std::vector<std::string> args;
	std::map<std::string, std::string> options;
};

/**
*
*/
static struct argp_option options[] = {
	{"verbose", 'v', 0, 0, "Produce verbose output."},
	{0}
};

/**
*
*/
static struct argp argp = {
	/* */
	options,
	/* */
	parse_args,
	/* */
	args_doc,
	/* */
	doc
};

#endif
