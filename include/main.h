/*
 * main.h
 *
 *  Created on: 2014/05/27
 *      Author: iwabuchik
 */

#ifndef MAIN_H_
#define MAIN_H_

//////////////////////////////////

// includes

//////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#ifndef LIB_H
#include "../include/lib.h"
#endif

#ifndef LIB_H
#include "../include/lib.h"
#endif

#ifndef GEN_PPM2_H_
#include "Gen_PPM2.h"
#endif


/////////////////////////////////////

// vars

/////////////////////////////////////
const char *app_names[];

/////////////////////////////////////

// Prototypes

/////////////////////////////////////
void _test_FirstProg(void);
void dispather(int, char**);


void Gen_PPM(int, char **);
void Proc_Wave(int argc, char **argv);



#endif /* MAIN_H_ */
