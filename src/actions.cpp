#include <cstdio>
#include <actions.h>

int call_action(struct action action, struct arguments* args) {
	if (DEBUG) {
		printf("Calling action: %s().\n", action.name);
	}
	return action.action(args);
}