#ifndef ACTIONS_H
#define ACTIONS_H

#include <options.h>

int call_action(struct action action, struct arguments* args);

struct action {
	const char* name;
	int (*action)(struct arguments*);
};

/* Begin action Functions */
int init(struct arguments* args);

static struct action actions[] = {
	{"init", init}
};

static size_t number_of_actions = sizeof(actions) / sizeof(struct action);
/* End action Functions */

#endif