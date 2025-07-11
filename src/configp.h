/*
 * DO NOT EDIT THIS FILE
*/
#ifndef CONFIGP_H
#define CONFIGP_H

#include <stdio.h>

#define MAX_FILE_COUNT 10 /* Maximum number of files */
#define MAX_LENGTH_COMMAND 25 /* Maximum length of a command */
#define MAX_ARGUMENT_COUNT 5 /* Maximum number of arguments */

typedef struct _config {
    int debug_mode ; /* Debug mode flag --debug */
    char command[MAX_LENGTH_COMMAND] ; /* Command called. Example: helloworld */
    char* filenames[MAX_FILE_COUNT] ; /* Images path. Example: ./images/input/image.jpeg */
    char* arguments[MAX_ARGUMENT_COUNT] ; /* Other arguments. */
} Config ;

#endif
