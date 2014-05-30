/*
 * Gen_PPM.c
 *
 *  Created on: 2014/05/27
 *      Author: iwabuchik
 */


//#ifndef MAIN_H_
//#include "../include/main.h"
//#endif
//
//#ifndef LIB_H
//#include "../include/lib.h"
//#endif
//
//#ifndef PPMLIB_H
//#include "../include/ppmlib.h"
//#endif

#ifndef GEN_PPM2_H_
#include "../include/Gen_PPM2.h"
#endif

/////////////////////////////////////

// defines

/////////////////////////////////////
//#define PPM_MAX_BRIGHTNESS	255
#define PPM_MAX_SIZE2		255

///////////////////////////////////////
//
//// prototypes
//
///////////////////////////////////////
//void _Setup_Options2(int argc, char **argv);
//void _Setup_Options__Bright2(char **argv);
//void _Setup_Options__Size2(char **argv);
//void _Setup_Options__Bg2(char **argv);
//void _Setup_Options__Dst2(char **argv);
//
//void build_PPM_Header2(void);
//void build_PPM_Pixels2(void);

/////////////////////////////////////

// vars: local => i.e. not in the header file

/////////////////////////////////////
char *ppm_file_dst;

int ppm_size[2];
int max_bright;

char *bg_color;

PPM *ppm_A;

PPM2 *ppm_A2;

void Gen_PPM2(int argc, char **argv)
{
	//log
	printf("[%s : %d] Gen_PPM()\n", base_name(__FILE__), __LINE__);

	/*********************************
	 * Options
	**********************************/
	_Setup_Options2(argc, argv);

	/*********************************
	 * Build: PPM header
	**********************************/
	build_PPM_Header2();

	/*********************************
	 * Build: PPM pixels
	**********************************/
	build_PPM_Pixels2();

	/*********************************
	 * Save: ppm file
	**********************************/
	int res_i = save_PPM(ppm_file_dst, ppm_A2);
//	int res_i = save_PPM(ppm_file_dst, ppm_A);

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
	free(ppm_A);

//	//test
//	//log
//	printf("[%s : %d] colors\n", base_name(__FILE__), __LINE__);
//
//	int i = 0;
//
//	while(Colors[i]) {
//
//		//log
//		printf("[%s : %d] Colors[%d] = %s\n", base_name(__FILE__), __LINE__, i, Colors[i]);
//
//		i ++;
//
//	}
//
//	char *tmp = join(',', Colors, i);
//
//	//log
//	printf("[%s : %d] Colors => %s\n", base_name(__FILE__), __LINE__, tmp);

}

void _Setup_Options2(int argc, char **argv)
{
	/*********************************
	 * Opt: size
	**********************************/
	_Setup_Options__Size2(argv);

	/*********************************
	 * Opt: bright
	**********************************/
	_Setup_Options__Bright2(argv);

	/*********************************
	 * Opt: background
	**********************************/
	_Setup_Options__Bg2(argv);

	/*********************************
	 * Opt: dst
	**********************************/
	_Setup_Options__Dst2(argv);


}

void build_PPM_Header2()
{
	ppm_A2 = (PPM2 *) malloc(sizeof(PPM2) * 1);

	//log
	printf("[%s : %d] malloc => done for ppm_A2\n", base_name(__FILE__), __LINE__);


	strcpy(ppm_A2->format, "P6");

	ppm_A2->format[2] = '\0';

	ppm_A2->x = ppm_size[0];
	ppm_A2->y = ppm_size[1];

	ppm_A2->max_brightness = max_bright;

	//log
	printf("[%s : %d] Build header => done\n", base_name(__FILE__), __LINE__);


//	ppm_A = (PPM *) malloc(sizeof(PPM) * 1);
//
//	strcpy(ppm_A->format, "P6");
//
//	ppm_A->format[2] = '\0';
//
//	ppm_A->x = ppm_size[0];
//	ppm_A->y = ppm_size[1];
//
//	ppm_A->max_brightness = max_bright;

}

void build_PPM_Pixels2(void)
{

//    int position = 0;

    int i, j;

//    int num_of_pixels;

    /*********************************
	 * Malloc
	**********************************/
    ppm_A2->pixels = (pixel **) malloc(sizeof(pixel *) * ppm_A2->y);

    //log
	printf("[%s : %d] malloc => done for ppm_A2->pixels\n", base_name(__FILE__), __LINE__);

	//log
	printf("[%s : %d] ppm_A2->y = %d\n", base_name(__FILE__), __LINE__, ppm_A2->y);


//    int i;

    for (i = 0; i < ppm_A2->y; ++i) {
//    for (i = 0; i < ppm_A2->x; ++i) {

    	ppm_A2->pixels[i] = (pixel *) malloc(sizeof(pixel) * ppm_A2->x);

	}

    //log
	printf("[%s : %d] malloc done for => ppm_A2->pixels[i]\n", base_name(__FILE__), __LINE__);

	/*********************************
	 * Init: each pixel
	**********************************/
	for (i = 0; i < ppm_A2->y; ++i) {
	//    for (i = 0; i < ppm_A2->x; ++i) {

		pixel *pixel_row = ppm_A2->pixels[i];

		for (j = 0; j < ppm_A2->x; ++j) {

			pixel pix;

			pix.r = 0;
			pix.g = 0;
			pix.b = 0;

			pixel_row[j] = pix;

		}

//		ppm_A2->pixels[i] = (pixel *) malloc(sizeof(pixel) * ppm_A2->x);

	}

//    num_of_pixels = ppm_A->x * ppm_A->y;
//
//    ppm_A->pixels = (pixel *) malloc (sizeof(pixel) * num_of_pixels);

//    int default_pixel_val = 150;

    /*********************************
	 * Set: pixels
	**********************************/
    int rgb[3];
//    int tmp_int_array[3] = {PIXEL_YELLOW};
//    int tmp_int_array = {PIXEL_YELLOW};

	if (!strcmp(bg_color, Colors[0])) {
		int tmp_int_array[3] = {PIXEL_GREEN};
		INIT_PIXEL(rgb, tmp_int_array);
//		set_PixelVals(ppm, position, PIXEL_GREEN);

	} else if (!strcmp(bg_color, Colors[1])) {

		int tmp_int_array[3] = {PIXEL_BLUE};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[2])) {

		int tmp_int_array[3] = {PIXEL_LIGHT_BLUE};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[3])) {

		int tmp_int_array[3] = {PIXEL_RED};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[4])) {

		int tmp_int_array[3] = {PIXEL_PURPLE};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[5])) {

		int tmp_int_array[3] = {PIXEL_YELLOW};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[6])) {

		int tmp_int_array[3] = {PIXEL_WHITE};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[7])) {

		int tmp_int_array[3] = {PIXEL_BLACK};
		INIT_PIXEL(rgb, tmp_int_array);

	} else if (!strcmp(bg_color, Colors[8])) {

		int tmp_int_array[3] = {PIXEL_GRAY};
		INIT_PIXEL(rgb, tmp_int_array);

	} else {

		int tmp_int_array[3] = {PIXEL_LIGHT_BLUE};
		INIT_PIXEL(rgb, tmp_int_array);

	}

	//log
	printf("[%s : %d] INIT_PIXEL => done\n", base_name(__FILE__), __LINE__);

//	//test
//	pixel* pixels_row = ppm_A2->pixels[0];

//	pixels_row[0]

	//log
//	printf("[%s : %d] ppm_A2->y = %d\n", base_name(__FILE__), __LINE__, ppm_A2->y);
//	printf("[%s : %d] ppm_A->y = %d\n", base_name(__FILE__), __LINE__, ppm_A->y);



    for (i = 0; i < ppm_A2->y; ++i) {

//    	//log
//		printf("[%s : %d] for loop => i = %d\n", base_name(__FILE__), __LINE__, i);


    	pixel* pixels_row = ppm_A2->pixels[i];
//    	pixel* pixels_row = ppm_A2.pixels[i];

//    	//log
//		printf("[%s : %d] pixels_row = ppm_A2->pixels[%d]\n",
//				base_name(__FILE__), __LINE__, i);

		for (j = 0; j < ppm_A2->x; ++j) {

//			pixel *pix = (pixel *) malloc(sizeof(pixel) * 1);
//			pixel pix = (pixel) malloc(sizeof(pixel) * 1); // conversion to non-scalar type requested
			pixel pix = pixels_row[j];
//			pixel pix;

			pix.r = rgb[0];
			pix.g = rgb[1];
			pix.b = rgb[2];
//
//			pixels_row[j] = pix;

//			set_PixelVals(ppm_A, position, rgb);

//			position ++;

		}//for (j = 0; j < ppm_A2->x; ++j)

    }//for (i = 0; i < ppm_A2->y; ++i)

}//void build_PPM_Pixels2(void)

void _Setup_Options__Bright2(char **argv) {

	char *opt_key_Bright = "-bright";

	char *opt_val_Bright = (char *) get_Opt_Value(argv, opt_key_Bright);

	consolColor_Change(GREEN);

	if (is_Numeric(opt_val_Bright)) {

		max_bright = atoi(opt_val_Bright);

		/*********************************
		 * Validate: <= 255
		**********************************/
		if (max_bright > 255) {

			consolColor_Change(RED);

			//log
			printf("[%s : %d] bright is %d => more than max value (%d)\n",
					(char *) base_name(__FILE__), __LINE__, max_bright, PPM_MAX_BRIGHTNESS);
	//				(char *) base_name(__FILE__), __LINE__, opt_val_Bright);

			consolColor_Reset();

			exit(-1);

		}

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

void _Setup_Options__Dst2(char **argv) {

	char *opt_key_Dst = "-dst";

	ppm_file_dst = (char *) get_Opt_Value(argv, opt_key_Dst);


	char delim = '.';

	int position = 1; int num_of_tokens;

	char **tokens = (char **) str_split_r_2
			(ppm_file_dst, delim, position, &num_of_tokens);

	/*********************************
	 * String: size
	**********************************/
	char *label_size = "_size=";

	char *str_size = (char *) malloc(sizeof(char) * 7);

	sprintf(str_size, "%d,%d", ppm_size[0], ppm_size[1]);

	//log
	printf("[%s : %d] str_size => %s(%d)\n",
			base_name(__FILE__), __LINE__, str_size, strlen(str_size));

	/*********************************
	 * String: bright
	**********************************/
	char *label_bright = "_bright=";

	char *str_bright = (char *) malloc(sizeof(char) * 3);

	sprintf(str_bright, "%d", max_bright);

//	//log
//	printf("[%s : %d] str_size => %s(%d)\n",
//			base_name(__FILE__), __LINE__, str_size, strlen(str_size));

	/*********************************
	 * String: backgfound
	**********************************/
	char *label_bg = "_bg=";

	char *str_bg = (char *) malloc(sizeof(char) * 3);

	/*********************************
	 * Join
	**********************************/
	int size_of_composite = 9;
	char **tmp = (char **) malloc(sizeof(char *) * size_of_composite);

	tmp[0] = tokens[0];
	tmp[1] = label_size;
	tmp[2] = str_size;
	tmp[3] = label_bright;
	tmp[4] = str_bright;
	tmp[5] = label_bg;
	tmp[6] = bg_color;
	tmp[7] = ".";
	tmp[8] = tokens[1];

	char *dst_final = (char *) join_simple(tmp, size_of_composite);

	/*********************************
	 * Dst => re-initialize
	**********************************/
	ppm_file_dst = dst_final;

//	//log
//	printf("[%s : %d] *dst_final = %s\n", base_name(__FILE__), __LINE__, dst_final);

//	//log
//	printf("[%s : %d] num_of_tokens = %d\n", base_name(__FILE__), __LINE__, num_of_tokens);


//	int i;

//	for (i = 0; i < num_of_tokens; ++i) {
//
//		//log
//		printf("[%s : %d] num_of_tokens[%d] = %s\n",
//				base_name(__FILE__), __LINE__, i, tokens[i]);
//
//	}

	consolColor_Change(GREEN);
	//log
	printf("[%s : %d] ppm_file_dst => %s\n",
			(char *) base_name(__FILE__), __LINE__, ppm_file_dst);

	consolColor_Reset();

}//void _Setup_Options__Dst2(char **argv)

void _Setup_Options__Size2(char **argv)
{

	char *opt_key_Size = "-size";

	char *opt_val_Size = (char *) get_Opt_Value(argv, opt_key_Size);

	char delim = ',';

	int position = 1; int num_of_tokens;

	char **tokens = (char **) str_split_r_2
			(opt_val_Size, delim, position, &num_of_tokens);

	int i;

	for(i = 0; i < 2; i++) {

		if(!is_Numeric(tokens[i])) {

			consolColor_Change(RED);

			//log
			printf("[%s : %d] size is not numeric => (%s) : %s\n",
						base_name(__FILE__), __LINE__,
						tokens[i], (i == 0 ? "width" : "height"));

			consolColor_Reset();

			exit(-1);

		} else {

			ppm_size[i] = atoi(tokens[i]);

			/*********************************
			 * Validate: > PPM_MAX_SIZE2?
			**********************************/
			if (ppm_size[i] > PPM_MAX_SIZE2) {

				consolColor_Change(RED);

				//log
				printf("[%s : %d] size is %d => more than max (%d)\n",
							base_name(__FILE__), __LINE__,
							ppm_size[i], PPM_MAX_SIZE2);

				consolColor_Reset();

				exit(-1);

			}

			//log
			printf("[%s : %d] size  => %d : %s\n",
						base_name(__FILE__), __LINE__,
						ppm_size[i], (i == 0 ? "width" : "height"));

		}//if(!is_Numeric(tokens[i]))

	}//for(i = 0; i < 2; i++)

}//void _Setup_Options__Size2(char **argv)

void _Setup_Options__Bg2(char **argv)
{

	char *opt_key_Bg = "-bg";

	char *opt_val_Bg = (char *) get_Opt_Value(argv, opt_key_Bg);

	/*********************************
	 * Validate
	**********************************/
	int tmp_i = 0;

	while(*(Colors + tmp_i)) tmp_i ++;


	int res_i = is_InArray(opt_val_Bg, Colors, tmp_i);

	if (res_i != true) {

		consolColor_Change(RED);

		//log
		printf("[%s : %d] Unknown color name: %s\n",
					base_name(__FILE__), __LINE__, opt_val_Bg);

		consolColor_Reset();

		char *tmp_ch = join(',', Colors, tmp_i);

		//log
		printf("[%s : %d] Available color names => %s\n",
				base_name(__FILE__), __LINE__, tmp_ch);

		exit(-1);

	} else {//if (res_i != true)

		bg_color = opt_val_Bg;

		consolColor_Change(GREEN);

		//log
		printf("[%s : %d] Background => %s\n",
					base_name(__FILE__), __LINE__, bg_color);
//					base_name(__FILE__), __LINE__, opt_val_Bg);

		consolColor_Reset();


	}//if (res_i != true)



}//void _Setup_Options__Bg2(char **argv)
