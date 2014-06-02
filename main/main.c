
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdarg.h>
//#include <string.h>
//#include <unistd.h>

/*********************************
 * includes
 *
 * main.h		lib.h	wave.h
 * methods.h
 *
**********************************/
#ifndef MAIN_H_
#include "../include/main.h"
#endif



//#ifndef LIB_H
//#include "../include/lib.h"
//#endif

//#ifndef WAVE_H
////#define WAVE_H
//#include "../include/wave.h"
//#endif

//#ifndef IMG_LIB_H
//#include "../include/img_lib.h"
//#endif

#ifndef METHODS_H
#include "../include/methods.h"
#endif

/*********************************
 * functions used
 *
 * log_Command_Input	: methods.c
 * write_Log			: methods.c
**********************************/


/////////////////////////////////////

// vars

/////////////////////////////////////
const char *app_names[] = {

		"gen-ppm",
		"wave",
		"max-vals"

};

///////////////////////////////////////
//
//// Prototypes
//
///////////////////////////////////////
//void _test_FirstProg(void);
//void dispather(int, char**);

/////////////////////////////////////

// main()

/////////////////////////////////////
int main(int argc, char** argv) {

//	//log
//	printf("[%s : %d] main()\n", base_name(__FILE__), __LINE__);
//	printf("[%s : %d] argc = %d\n", base_name(__FILE__), __LINE__, argc);


	/*********************************
	 * Initial setups
	**********************************/
	log_Command_Input(argc, argv);
#ifndef UBUNTU
	init_ConsoleColors();
#endif
//	/*********************************
//	 * Dispatch
//	**********************************/
	dispather(argc, argv);

#ifndef UBUNTU

	consolColor_Change(0, 0x0f);

#endif
	//log
	printf("[%s : %d] done", base_name(__FILE__), __LINE__);

	consolColor_Reset();

	printf("\n");

	return 0;

}

void dispather(int argc, char** argv)
{
	//log
	printf("[%s : %d] Starting => dispather()\n", base_name(__FILE__), __LINE__);

	/*********************************
	 * Get: opt value for '-app'
	**********************************/
	//test
	char *test_str = (char *) join(',', argv, argc);
	//log
//	printf("[%s : %d] test_str => %s\n",
//			base_name(__FILE__), __LINE__, test_str);


	const char *opt_string = "-app";

	char *opt_val = (char *) get_Opt_Value(argv, opt_string);

	consolColor_Change(GREEN);

	//log
	printf("[%s : %d] opt_val for '%s' => %s\n",
			base_name(__FILE__), __LINE__, opt_string, opt_val);

	consolColor_Reset();

	/*********************************
	 * Dispatch
	**********************************/
	if (!strcmp(opt_val, app_names[0])) {	// "gen-ppm"

		Gen_PPM2(argc, argv);
//		Gen_PPM(argc, argv);

	} else if (!strcmp(opt_val, app_names[1])) {	// "wave"

		Proc_Wave(argc, argv);

	} else if (!strcmp(opt_val, app_names[2])) {	// "max-vals"

		Max_Vals(argc, argv);

	} else {

		consolColor_Change(RED);

		//log
		printf("[%s : %d] Unknown option value for '-app' => %s\n",
					base_name(__FILE__), __LINE__, opt_val);

		consolColor_Reset();

	}

}//void dispather(int argc, char** argv)
