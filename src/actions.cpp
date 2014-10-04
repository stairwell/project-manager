#include <cstdio>
#include <actions.h>
#include <debug.h>

int call_action(struct action action, struct arguments* args) {
	if (DEBUG_MODE == true) {
		printf("Calling action: %s().\n", action.name);
	} else {

	}
	return action.action(args);
}