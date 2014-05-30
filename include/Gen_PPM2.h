/*
 * Gen_PPM2.h
 *
 *  Created on: 2014/05/30
 *      Author: iwabuchik
 */

#ifndef GEN_PPM2_H_
#define GEN_PPM2_H_

/*********************************
 * includes
**********************************/
//#ifndef MAIN_H_
//#include "../include/main.h"
//#endif

#ifndef LIB_H
#include "../include/lib.h"
#endif

#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

/////////////////////////////////////

// prototypes

/////////////////////////////////////
void _Setup_Options2(int argc, char **argv);
void _Setup_Options__Bright2(char **argv);
void _Setup_Options__Size2(char **argv);
void _Setup_Options__Bg2(char **argv);
void _Setup_Options__Dst2(char **argv);

void build_PPM_Header2(void);
void build_PPM_Pixels2(void);


#endif /* GEN_PPM2_H_ */
