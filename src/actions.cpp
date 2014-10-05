#include <iostream>
#include <cstdio>
#include <actions.h>
#include <utils.h>
#include <debug.h>

int call_action(struct action action, struct arguments* args) {
	if (DEBUG_MODE == true) {
		debug_printf("Calling action: %s(%s).\n", action.name, vector_to_comma_delimited_string(args->args).c_str());
	}
	return action.action(args);
}