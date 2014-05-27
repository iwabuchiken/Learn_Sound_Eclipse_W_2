/* 
 * File:   img_lib.h
 * Author: IwabuchiK
 *
 * Created on 2014/05/06, 16:02
 */

#ifndef IMG_LIB_H
#define	IMG_LIB_H

#ifndef LIB_H
#include "lib.h"
#endif

/*******************************
 * typedef
 *******************************/
typedef unsigned int gray;

typedef gray pixval;

/*******************************
 * struct
 *******************************/    
typedef struct {

	gray x;
	gray y;

	gray max_gray;

	gray *grays;

	char format[3];

	char *file_name;

} PGM;

typedef struct {
    pixval r, g, b;
} pixel;

typedef struct {

    gray x;
    gray y;

    gray max_brightness;

    char format[3];

    char *file_name;

    pixel *pixels;	//

} PPM;

/*******************************
 * Prototypes
 *******************************/
void show_usage__pgm2ppm(void);

int _opt_RGV(char **, int **);
int validate_RGBStringFormat(char *);
char * _opt_Src_File(char **, char *);
char * _opt_Dst_File(char **, char *, char *);
int _opt_ForceCreate_RootDst(char **);

int _opt_OverWrite_DstFile(char **);
	
char * conv_DstFile_Name(char *, int **);
	
#endif	/* IMG_LIB_H */

