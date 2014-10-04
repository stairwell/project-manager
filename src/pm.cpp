#include <cstdio>
#include <cstdlib>
#include <options.h>
#include <libgen.h>

/**
*
*/
void arguments_pre(struct arguments* arguments) {
	arguments->options["verbose"] = "FALSE";
}

/**
*
*/
void arguments_post(struct arguments* arguments) {

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

/**
*
*/
int main(int argc, char** argv) {
	struct arguments arguments;
	arguments_pre(&arguments);

	error_t ret_code = argp_parse(&argp, argc, argv, 0, 0, &arguments);
	
	if (arguments.args.size() == 0) {
		argp_help(&argp, stdout, ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR, basename(argv[0]));
	}



	return 0;
}
