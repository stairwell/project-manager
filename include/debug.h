#ifndef DEBUG_H
#define DEBUG_H

/*
* Debug print function.
*/
int debug_printf(const char* format, ...);

/*
* Debug print function with a new line.
*/
int debug_printl(const char* format, ...);

/*
* Are we in debugging mode?
*/
extern volatile bool DEBUG_MODE;

#endif