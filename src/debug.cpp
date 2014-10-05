#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <stdarg.h>
#include <debug.h>

/**
* Printf with unix timestamp
*/
int debug_printf(const char* format, ...) {
	char* buffer;

	va_list arg;
	va_start(arg, format);
	vasprintf(&buffer, format, arg);
	va_end(arg);

	/* This still uses the old C ways
	*  It doesn't use nullptr so it doesn't require C++11
	*/
	int ret = printf("[%d]: %s", time(NULL), buffer);

	free(buffer);
	return ret;
}

/**
* debug_printf() with a new line.
*/
int debug_printl(const char* format, ...) {
	char* buffer;

	va_list arg;
	va_start(arg, format);
	vasprintf(&buffer, format, arg);
	va_end(arg);

	/* This still uses the old C ways
	*  It doesn't use nullptr so it doesn't require C++11
	*/
	int ret = printf("[%d]: %s\n", time(NULL), buffer);

	free(buffer);
	return ret;
}