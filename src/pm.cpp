#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <libgen.h>
#include <options.h>
#include <actions.h>
#include <debug.h>

/**
* Package name and version.
*
*/
const char* argp_program_version = PACKAGE_NAME "-" PACKAGE_VERSION;

/**
*
*/
const char* argp_program_bug_address = "<" PACKAGE_BUGREPORT ">";

/**
*
*/
int main(int argc, char** argv) {
	struct arguments arguments;
	arguments_pre(&arguments);

	error_t ret_code = argp_parse(&argp, argc, argv, 0, 0, &arguments);
	
	/* Do we have any actions */
	if (arguments.args.size() == 0) {
		argp_help(&argp, stdout, ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR, basename(argv[0]));

		/* Manual exit needed? */
		exit(1);
	}

	const char* action = arguments.args.at(0).c_str();
	arguments.args.erase(arguments.args.begin());

	/* Search for action in table */
	for(int i = 0; i < number_of_actions; i++) {
		if (strcmp(actions[i].name, action) == 0) {
			return call_action(actions[i], &arguments);
		}
	}

	fprintf(stderr, "No such action '%s'.\n", action);
	argp_help(&argp, stdout, ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR, basename(argv[0]));

	return 0;
}
