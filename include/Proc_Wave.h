/*
 * Gen_PPM.h
 *
 *  Created on: 2014/05/30
 *      Author: iwabuchik
 */

#ifndef PROC_WAVE_H_
#define PROC_WAVE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/*********************************
 * includes
 *
 * main.h	lib.h		ppmlib.h
 * wave.h	methods.h
 *
**********************************/

#ifndef MAIN_H_
#include "../include/main.h"
#endif

//#ifndef LIB_H
//#include "../include/lib.h"
//#endif

#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

#ifndef WAVE_H
//#define WAVE_H
#include "../include/wave.h"
#endif

//#ifndef IMG_LIB_H
//#include "../include/img_lib.h"
//#endif

#ifndef METHODS_H
#include "../include/methods.h"
#endif

/////////////////////////////////////

// defines

/////////////////////////////////////
#define DEFALUT_PPM_WIDTH 300
#define DEFALUT_PPM_HEIGHT 500
//#define DEFALUT_PPM_HEIGHT 500
//#define DEFALUT_PPM_WIDTH 255
//#define DEFALUT_PPM_HEIGHT 255

#define PPM_MAX_SIZE		500
#define PPM_MIN_SIZE		255

/////////////////////////////////////

// prototypes

/////////////////////////////////////
void _Setup_Options_ProcWave(int argc, char **argv);
void _Setup_Options_ProcWave__Src(char **argv);
void _Setup_Options_ProcWave__Dst(char **argv);
void _Setup_Options_ProcWave__SaveFile(char **argv, int argc);
void _Setup_Options_ProcWave__Op(char **argv, int argc);
void _Setup_Options_ProcWave__Size(char **argv, int argc);


void Proc_Wave(int argc, char **argv);
void Proc_Wave__SaveWave(void);
void Proc_Wave__ReadWave(void);

void Proc_Wave__Analyze(void);
void Proc_Wave__Op_Dispatch(void);

// Op: wave to ppm
void op_Wave2PPM(void);
void op_Wave2PPM__Header_Wave(void);
void op_Wave2PPM__Pixels_Wave(void);
void build_PPM_Pixels_WaveData(void);

void build_PPM_Pixels_Image(void);
void build_PPM_Rotate_Image(void);
int build_PPM_Rotate_Image__PosConv
(int pos_A, int A_width, int A_height, int B_width, int B_height);

void build_PPM_DstFile(void);

/////////////////////////////////////

// global vars

/////////////////////////////////////
MONO_PCM pcm0, pcm1;

char *file_src_wave;
char *file_dst_wave;

char *file_dst_ppm;

char *operation;	// 1. name of the operation to be conducted
					// 2. The name will be one of those in "op_names" array

int save_file;	// if true, a new wave file will be saved
						//	with the name given in '-dst' optoin

char *op_names[];

//		"wave-to-ppm",
//		NULL			// NULL is added so that counting the elements
//						//	will require only the array itself, not the
//						//	size of it as well.
//};

char *ppm_file_dst;

// The size of the ppm file that will display the wave form of the audio data
int ppm_size[2];

// Max brightness value for the ppm file
int max_bright;

// 1. Background color for the ppm file
// 2. The value will be one of those in Colors:ppmlib.c
char *bg_color;

PPM *ppm_A;
PPM *ppm_B;

// Pixel values converted from wave data: 0-255
int pixel_data[DEFALUT_PPM_HEIGHT];
//int pixel_data[DEFALUT_PPM_WIDTH];

#endif /* GEN_PPM_H_ */
