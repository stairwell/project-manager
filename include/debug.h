#ifndef DEBUG_H
#define DEBUG_H

#include <cstdio>

/**
*
*/
#define debug_printf(fmt, ...) pm_fprintf(stdout, fmt, __VA_ARGS__)

/**
*
*/
#define debug_printl(fmt, ...) pm_fprintl(stdout, fmt, __VA_ARGS__)

/**
*
*/
int pm_fprintf(FILE* stream, const char* format, ...);

/**
*
*/
int pm_fprintl(FILE* stream, const char* format, ...);

/*
* Are we in debugging mode?
*/
extern volatile bool DEBUG_MODE;

#endif