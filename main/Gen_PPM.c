/*
 * Gen_PPM.c
 *
 *  Created on: 2014/05/27
 *      Author: iwabuchik
 */


#ifndef MAIN_H_
#include "../include/main.h"
#endif

#ifndef LIB_H
#include "../include/lib.h"
#endif

#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

/////////////////////////////////////

// defines

/////////////////////////////////////
#define MAX_BRIGHTNESS	255

/////////////////////////////////////

// prototypes

/////////////////////////////////////
void _Setup_Options(int argc, char **argv);
void _Setup_Options__Bright(char **argv);

void build_PPM_Header(void);
void build_PPM_Pixels(void);

/////////////////////////////////////

// vars

/////////////////////////////////////
char *ppm_file_dst;

int ppm_size[2];
int max_bright;

char *bg_color;

PPM *ppm;

void Gen_PPM(int argc, char **argv)
{
	//log
	printf("[%s : %d] Gen_PPM()\n", base_name(__FILE__), __LINE__);

	_Setup_Options(argc, argv);

	/*********************************
	 * Build: PPM header
	**********************************/
	build_PPM_Header();

	/*********************************
	 * Build: PPM pixels
	**********************************/
	build_PPM_Pixels();

	/*********************************
	 * Save: ppm file
	**********************************/
	int res_i = save_PPM(ppm_file_dst, ppm);

	if (res_i == 1) {

		consolColor_Change(GREEN);

		//log
		printf("[%s : %d] PPM => saved: %s\n",
					base_name(__FILE__), __LINE__, ppm_file_dst);

		consolColor_Reset();


	} else {

		consolColor_Change(RED);

		//log
		printf("[%s : %d] PPM => not saved: %s\n",
					base_name(__FILE__), __LINE__, ppm_file_dst);

		consolColor_Reset();


	}

	/*********************************
	 * Free: ppm
	**********************************/
	free(ppm);

}

void _Setup_Options(int argc, char **argv)
{
	/*********************************
	 * Opt: dst
	**********************************/
	char *opt_key_Dst = "-dst";

	ppm_file_dst = (char *) get_Opt_Value(argv, opt_key_Dst);

	consolColor_Change(GREEN);
	//log
	printf("[%s : %d] ppm_file_dst => %s\n",
			(char *) base_name(__FILE__), __LINE__, ppm_file_dst);

	consolColor_Reset();

	/*********************************
	 * Opt: size
	**********************************/
	char *opt_key_Size = "-size";

	char *opt_val_Size = (char *) get_Opt_Value(argv, opt_key_Size);

	/*********************************
	 * Opt: bright
	**********************************/
	_Setup_Options__Bright(argv);

//	char *opt_key_Bright = "-bright";
//
//	char *opt_val_Bright = (char *) get_Opt_Value(argv, opt_key_Bright);
//
//	consolColor_Change(GREEN);
//
//	if (is_Numeric(opt_val_Bright)) {
//
//		max_bright = atoi(opt_val_Bright);
//
//		consolColor_Change(GREEN);
//
//		//log
//		printf("[%s : %d] bright => %d\n",
//				(char *) base_name(__FILE__), __LINE__, max_bright);
////				(char *) base_name(__FILE__), __LINE__, opt_val_Bright);
//
//		consolColor_Reset();
//
//
//
//	} else {
//
//		consolColor_Change(RED);
//
//		//log
//		printf("[%s : %d] bright => not numeric (%s)\n",
//				(char *) base_name(__FILE__), __LINE__, opt_val_Bright);
//
//		consolColor_Reset();
//
//		exit(-1);
//
//	}
//
//
////	//log
////	printf("[%s : %d] bright => %s\n",
////			(char *) base_name(__FILE__), __LINE__, opt_val_Bright);
////
////	consolColor_Reset();

}

void build_PPM_Header()
{
	ppm = (PPM *) malloc(sizeof(PPM) * 1);

	strcpy(ppm->format, "P6");

	ppm->format[2] = '\0';

	ppm->x = 255;
	ppm->y = 255;

	ppm->max_brightness = 255;

}

void build_PPM_Pixels(void)
{

    int position = 0;

    int i, j;

    int num_of_pixels = ppm->x * ppm->y;

    ppm->pixels = (pixel *) malloc (sizeof(pixel) * num_of_pixels);

    int default_pixel_val = 150;

    for (i = 0; i < ppm->y; ++i) {

		for (j = 0; j < ppm->x; ++j) {

			ppm->pixels[position].r = default_pixel_val;
			ppm->pixels[position].g = default_pixel_val;
			ppm->pixels[position].b = default_pixel_val;
//			ppm->pixels[position].b = ((int) pgm->grays[position] * (int) rgb[2]) / 100;

			position ++;

		}
    }

}

void _Setup_Options__Bright(char **argv) {

	char *opt_key_Bright = "-bright";

	char *opt_val_Bright = (char *) get_Opt_Value(argv, opt_key_Bright);

	consolColor_Change(GREEN);

	if (is_Numeric(opt_val_Bright)) {

		max_bright = atoi(opt_val_Bright);

		consolColor_Change(GREEN);

		//log
		printf("[%s : %d] bright => %d\n",
				(char *) base_name(__FILE__), __LINE__, max_bright);
//				(char *) base_name(__FILE__), __LINE__, opt_val_Bright);

		consolColor_Reset();



	} else {

		consolColor_Change(RED);

		//log
		printf("[%s : %d] bright => not numeric (%s)\n",
				(char *) base_name(__FILE__), __LINE__, opt_val_Bright);

		consolColor_Reset();

		exit(-1);

	}


//	//log
//	printf("[%s : %d] bright => %s\n",
//			(char *) base_name(__FILE__), __LINE__, opt_val_Bright);
//
//	consolColor_Reset();

}
