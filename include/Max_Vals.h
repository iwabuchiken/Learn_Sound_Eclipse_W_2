/*
 * Max_Vals.h
 *
 *  Created on: 2014/06/02
 *      Author: iwabuchik
 */

#ifndef MAX_VALS_H_
#define MAX_VALS_H_

#ifndef GEN_PPM_H_
#include "../include/main.h"
#endif

//////////////////////////////////

// vars

//////////////////////////////////
char *src_Max_Vals;
MONO_PCM pcm0;

//////////////////////////////////

// Prototypes

//////////////////////////////////
void Max_Vals(int argc, char **argv);
void _Setup_Options_Max_Vals(int argc, char **argv);

void _Setup_Options_Max_Vals__Src(char **argv);

#endif /* MAX_VALS_H_ */
