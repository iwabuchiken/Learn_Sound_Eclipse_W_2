/* 
 * File:   methods.h
 * Author: buchi
 *
 * Created on 2014/05/25, 11:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#ifndef LIB_H
#include "../include/lib.h"
#endif


#ifndef METHODS_H
#define	METHODS_H

#ifdef	__cplusplus
extern "C" {
#endif

/**************************
 * Variables
 **************************/
const char *LOG_FILE_PATH;
//const char *LOG_FILE_PATH = "../log/exec_log.txt";


/**************************
 * Prototypes
 **************************/
void log_Command_Input(int, char **);

void write_Log(char *, int, char *);

#ifdef	__cplusplus
}
#endif

#endif	/* METHODS_H */

