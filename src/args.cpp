#include <cstdio>
#include <cstring>
#include <actions.h>
#include <debug.h>

/**
*
*/
void arguments_pre(struct arguments* arguments) {
	arguments->options["verbose"] = "FALSE";

	arguments->options["debug"] = "FALSE";
}

/**
*
*/
void arguments_post(struct arguments* arguments) {

	/* Replace */
	if (arguments->options["debug"] == "TRUE") {
		DEBUG_MODE = true;
	} 
}

/**
*
*/
int parse_args(int key, char* arg, struct argp_state* state) {

	struct arguments* arguments = (struct arguments*) state->input;

	switch(key) {
		case 'v':
			arguments->options["verbose"] = "TRUE";
			break;
		case 'd':
			arguments->options["debug"] = "TRUE";
			break;
		case ARGP_KEY_ARG:
			arguments->args.push_back(arg);
			break;
		case ARGP_KEY_END:
			arguments_post(arguments);
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}

	return 0;
}