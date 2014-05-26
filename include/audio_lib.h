/* 
 * File:   audio_lib.h
 * Author: iwabuchik
 *
 * Created on 2014/05/20, 17:08
 */

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

//#ifndef STDLIB_H
//#define STDLIB_H
#include <stdlib.h>
//#endif

#ifndef LIB_H
#define	LIB_H
#include "lib.h"
#endif

#ifndef AUDIO_LIB_H
#define	AUDIO_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

    char *get_Src_Path(char **, char *);



#ifdef	__cplusplus
}
#endif

#endif	/* AUDIO_LIB_H */

