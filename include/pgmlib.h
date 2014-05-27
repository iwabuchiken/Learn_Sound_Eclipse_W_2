/* 
 * File:   pgmlib.h
 * Author: IwabuchiK
 *
 * Created on 2014/05/07, 15:25
 */

#ifndef PGMLIB_H
#define	PGMLIB_H

#ifdef	__cplusplus
extern "C" {
#endif

/*******************************
 * includes
 *******************************/
#ifndef IMG_LIB_H
#include "img_lib.h"
#endif
    
//    /*******************************
//     * typedef
//     *******************************/
//    typedef unsigned int gray;
//
//    /*******************************
//     * struct
//     *******************************/    
//    typedef struct {
//
//	    gray x;
//	    gray y;
//
//	    gray max_gray;
//
//	    gray *grays;
//
//	    char format[3];
//	    
//	    char *file_name;
//    
//    } PGM;

    /*******************************
     * vars
     *******************************/
    #define MAX_IMAGESIZE       1280 /* 想定する縦・横の最大画素数 */
    #define MAX_BRIGHTNESS       255 /* 想定する最大階調値 */
    #define GRAYLEVEL            256 /* 想定する階調数(=最大階調値+1) */
    #define MAX_FILENAME         256 /* 想定するファイル名の最大長 */
    #define MAX_BUFFERSIZE       256 /* 利用するバッファ最大長 */
    #define MAX_NUM_OF_IMAGES      5 /* 利用する画像の枚数 */

    /*******************************
     * prototypes
     *******************************/
    int get_PGM_2(char *, PGM *);
    int get_PGM(FILE *, PGM *);
    
    int conv_PGM2PPM(PGM *, PPM *, int **);
    
#ifdef	__cplusplus
}
#endif



#endif	/* PGMLIB_H */

