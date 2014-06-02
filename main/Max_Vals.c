/*
 * Max_Vals.c
 *
 *  Created on: 2014/06/02
 *      Author: iwabuchik
 */

#ifndef GEN_PPM_H_
#include "../include/Max_Vals.h"
#endif

//////////////////////////////////

// Vars

//////////////////////////////////
PPM *ppm;

void Max_Vals(int argc, char **argv)
{
	//////////////////////////////////

	// Options

	//////////////////////////////////
	_Setup_Options_Max_Vals(argc, argv);


}

void _Setup_Options_Max_Vals(int argc, char **argv)
{

	/*********************************
		 * Opt: src
		**********************************/
	_Setup_Options_Max_Vals__Src(argv);

//	//log
//	printf("[%s : %d] _Setup_Options_Max_Vals\n", base_name(__FILE__), __LINE__);


}

void _Setup_Options_Max_Vals__Src(char **argv)
{

//	src_Max_Vals =

	char *opt_key_Src = "-src";

	char *file_src = (char *) get_Opt_Value(argv, opt_key_Src);

	/*********************************
	 * validate: exists?
	**********************************/
	int res_i = fileExists(file_src);

	if (res_i == false) {

		consolColor_Change(RED);
		//log
		printf("[%s : %d] Src file => deosn't exist(%s)\n",
				(char *) base_name(__FILE__), __LINE__, file_src);

		consolColor_Reset();

		exit(-1);

	} else {

		src_Max_Vals = file_src;

	}

	consolColor_Change(GREEN);
	//log
	printf("[%s : %d] src_Max_Vals => %s\n",
			(char *) base_name(__FILE__), __LINE__, src_Max_Vals);

	consolColor_Reset();
//	//log
//	printf("[%s : %d] _Setup_Options_Max_Vals__Src()\n", base_name(__FILE__), __LINE__);


}
