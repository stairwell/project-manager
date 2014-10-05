#include <debug.h>
#include <config.h>

/* This file contains things that can't be inialized in header files */


/* Argp section start */

/**
* Package name and version.
*/
const char* argp_program_version = PACKAGE_NAME "-" PACKAGE_VERSION;

/**
* Package bug report email.
*/
const char* argp_program_bug_address = "<" PACKAGE_BUGREPORT ">";

/* Argp section end */


/* Extern section start */

/*
* Set default debug mode.
*/
volatile bool DEBUG_MODE = false;

/* Extern section  end */