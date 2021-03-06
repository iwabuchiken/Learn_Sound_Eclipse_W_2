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

#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*********************************
 * Defines
**********************************/
#define PIXEL_GREEN     0, 100, 0

#define PIXEL_BLUE      0, 0, 100
#define PIXEL_LIGHT_BLUE      0, 100, 100

#define PIXEL_RED       100, 0, 0

#define PIXEL_PURPLE    100, 0, 100
#define PIXEL_YELLOW    100, 100, 0

#define PIXEL_WHITE     100, 100, 100
#define PIXEL_BLACK     0, 0, 0
#define PIXEL_GRAY      50, 50, 50

//#define INIT_PIXEL(rgb, vals) rgb = vals;
//#define INIT_PIXEL(rgb, vals) rgb = &vals;	// incompatible types when assigning to type 'int[3]' from type 'int (*)[3]'
//#define INIT_PIXEL(rgb, vals) ((int *)rgb) = vals;
#define INIT_PIXEL(rgb, vals) rgb[0] = vals[0]; rgb[1] = vals[1]; rgb[2] = vals[2];
//#define INIT_PIXEL(rgb, r, g, b) rgb[0] = r; rgb[1] = g; rgb[2] = b;

//#define INIT_PIXEL_2(rgb, param) INIT_PIXEL(rgb, )

#define PPM_MAX_BRIGHTNESS	255

/*********************************
 * vars
**********************************/
char *Colors[];

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
    int save_PPM2(char *, PPM2 *);
    
//    char * conv_DstFile_Name(void);

    void set_PixelVals
    (PPM *ppm, int position, int rgb[3]);
//    (PPM *ppm, int position, int r, int g, int b);
//    {
//        ptr[0] = 255 * r / 100;
//        ptr[1] = 255 * g / 100;
//        ptr[2] = 255 * b / 100;
//    //    ptr[1] = g; ptr[2] = b;
//    //    ptr[0] = r; ptr[1] = g; ptr[2] = b;
//    }


#ifdef	__cplusplus
}
#endif

#endif	/* PPMLIB_H */

