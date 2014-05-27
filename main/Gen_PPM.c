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

/////////////////////////////////////

// defines

/////////////////////////////////////
#define MAX_BRIGHTNESS	255

/////////////////////////////////////

// prototypes

/////////////////////////////////////
void _Setup_Options(int argc, char **argv);

/////////////////////////////////////

// vars

/////////////////////////////////////
char *ppm_file_dst;
int ppm_size[2];
int max_bright;
char *bg_color;

void Gen_PPM(int argc, char **argv)
{
	//log
	printf("[%s : %d] Gen_PPM()\n", base_name(__FILE__), __LINE__);

	_Setup_Options(argc, argv);

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

	consolColor_Change(GREEN);

	//log
	printf("[%s : %d] size => %s\n",
			(char *) base_name(__FILE__), __LINE__, opt_val_Size);

	consolColor_Reset();

	/*********************************
	 * Opt: bright
	**********************************/
	char *opt_key_Bright = "-bright";

	char *opt_val_Bright = (char *) get_Opt_Value(argv, opt_key_Bright);

	consolColor_Change(GREEN);

	//log
	printf("[%s : %d] bright => %s\n",
			(char *) base_name(__FILE__), __LINE__, opt_val_Bright);

	consolColor_Reset();

}
