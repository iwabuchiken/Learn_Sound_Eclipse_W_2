/* 
 * File:   ppmlib.h
 * Author: IwabuchiK
 *
 * Created on 2014/05/07, 15:32
 */

#ifndef PPMLIB_H
#define	PPMLIB_H

/*******************************
 * includes
 *******************************/
#ifndef IMG_LIB_H
#include "img_lib.h"
#endif

#ifndef PGMLIB_H
#include "pgmlib.h"
#endif

#ifdef	__cplusplus
extern "C" {
#endif

    /*******************************
     * typedef
     *******************************/
//    typedef gray pixval;

    /*******************************
     * struct
     *******************************/
//    typedef struct {
//	pixval r, g, b;
//    } pixel;
//
//    typedef struct {
//
//	gray x;
//	gray y;
//
//	gray max_brightness;
//	
//	char format[3];
//	
//	char *file_name;
//
//	pixel *pixels;	//
//
//    } PPM;

    /*******************************
     * Prototypes
     *******************************/
    int save_PPM(char *, PPM *);
    
//    char * conv_DstFile_Name(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PPMLIB_H */

