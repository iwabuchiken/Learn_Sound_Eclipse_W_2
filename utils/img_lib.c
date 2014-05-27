#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif


#ifndef IMG_LIB_H
#include "../include/img_lib.h"
#endif

void show_usage__pgm2ppm(void)
{
	char *message =
			"<Usage>\n"
			"\tpgm2ppm.exe <source file> [options]\n"
			"\n"

			"<Option>\n"
			"\t-rgb [r,g,b]\tbrightness value for each color composite\n"
			"\t            \t=> unit is percentage. So, 10,10,50 means, say, \n"
			"\t            \t   pgm file has a value 216\n"
			"\t            \t   => ppm values will be 22,22,103\n"
			"\t            \t     (pgm value times each percentage value)\n"
			"\t            \t=> If omitted, the values will be set to \n"
			"\t            \t   the default of 100,100,100\n"

			"\n"
			"\t-src [filename]\tsource pgm file name\n"

			"\n"
			"\t-dst [filename]\ttarget pgm file name\n"

			;

	printf("%s\n", message);

}

/************************************
 * @return 1 => rgb values obtained
 * 			0 => not obtained
 * @param
 * 		int **rgb => int array to put rgb values into
************************************/
int _opt_RGB(char **argv, int *rgb[3])
//int _opt_RGV(char **argv, int **rgb)
{
	char *opt_RGB = "-rgb";

	int opt_rgb = 0;

	int increment = 1;

	char *rgb_values_string;
	char **rgb_values_array;

//	int *rgb_values;

	// Inspect args
	while(*(argv + increment) != NULL) {

//	    //log
//	    printf("[%s:%d] argv => %s\n",
//			    base_name(__FILE__), __LINE__, *(argv + increment));

	    int res = strcmp(*(argv + increment), opt_RGB);

	    if (res == 0) {

		    increment ++;

		    // Get the next arg to "-rgb" switch
		    if (*(argv + increment) != NULL) {

//			    //log
//			    printf("[%s:%d] RGB option => %s\n",
//					    base_name(__FILE__), __LINE__, *(argv + increment));
////						base_name(__FILE__), __LINE__, *argv);

			    res = validate_RGBStringFormat((*(argv + increment)));

			    if (res == 1) {

				    //log
				    printf("[%s:%d] RGB format => validated(%s)\n",
						    base_name(__FILE__), __LINE__, *(argv + increment));

				    opt_rgb = 1;

				    // rgb values ----------------------------
				    // malloc for rgb_values_string
				    // strcpy argv value to rgb_values_string
				    int len = strlen(*(argv + increment)) + 1;

				    rgb_values_string =
						    malloc(sizeof(char) * len);
//							malloc(sizeof(char) * strlen(*(argv + increment)));

				    strcpy(rgb_values_string, *(argv + increment));

//				    //log
//				    printf("[%s:%d] Prepared => rgb_values_string (= %s)\n",
//						    base_name(__FILE__), __LINE__, rgb_values_string);

			    } else {

				    //log
				    printf("[%s:%d] RGB option => not well-formed: %s\n",
						    base_name(__FILE__), __LINE__, *(argv + increment));
//							base_name(__FILE__), __LINE__, *argv);

			    }

			    break;

		    } else {

			    //log
			    printf("[%s:%d] RGB option => not in the args\n",
					    base_name(__FILE__), __LINE__);

		    }//if (*argv != NULL)

	    }//if (res == 0)

	    increment ++;

	}//while(*argv != NULL)

	//////////////////////////////////////

	// Build: rgb values array

	//////////////////////////////////////

//	//log
//	printf("[%s:%d] opt_rgb => %d\n", base_name(__FILE__), __LINE__, opt_rgb);

	if (opt_rgb == 1) {

		int count;

//		//log
//		printf("[%s:%d] Calling... str_split_3\n", base_name(__FILE__), __LINE__);


		rgb_values_array = str_split_3(rgb_values_string, ',', &count);
//		rgb_values_array = str_split(rgb_values_string, ',');

		//log
		printf("[%s:%d] split => done (count = %d)\n",
				base_name(__FILE__), __LINE__, count);

		int tmp;

		for (tmp = 0; tmp < 3; ++tmp) {

//			rgb[tmp] = atoi(rgb_values_array[tmp]);
		    rgb[tmp] = (int *)atoi(rgb_values_array[tmp]);

		}

//		rgb[0] = atoi(rgb_values_array[0]);
//		rgb[1] = atoi(rgb_values_array[1]);
//		rgb[2] = atoi(rgb_values_array[2]);

//		//log
//		printf("[%s:%d] rgb[0] => %d\n", base_name(__FILE__), __LINE__, rgb[0]);

	}//if (opt_rgb == 1)

	return opt_rgb;

}//void _opt_RGV(char *argv, int **rgb)

/************************************
 * @return 0 => Invalid
 * 			1 => valid
************************************/
int validate_RGBStringFormat(char *string)
{

//	//log
//	printf("[%s:%d] string => %s\n", base_name(__FILE__), __LINE__, string);


	int count;

	char delim = ',';

//	char **tokens = str_split_3(string, delim, &count);
//	char **tokens = str_split_3(&string, delim, count);
//	char **tokens = str_split_3(*string, delim, count);
//	char **tokens = str_split_3(string, delim, count);

//	//log
//	printf("[%s:%d] count => %d\n", base_name(__FILE__), __LINE__, count);


	return (count == 3) ? 1 : 0;

//	//log
//	printf("[%s:%d] **tokens => %s\n", base_name(__FILE__), __LINE__, **tokens);
////	printf("[%s:%d] **tokens => %s\n", base_name(__FILE__), __LINE__, *(*tokens)); // format argument is not a pointer (arg 4)
//
//
//	return 1;

}

/************************************
 * _opt_Src_File(char ** argv, char *current_dir)
 *
 * @return char pointer
 * 	=> For each format of input:
 * 		- <program> abc.txt				=> <current_dir>\abc.txt
 * 		- <program> [arg] -src abc.txt	=> <current_dir>\abc.txt
 * 		- <program> XXX\abc.txt			=> XXX\abc.txt
 * 		- <program> [arg] -src XXX\abc.txt	=> XXX\abc.txt
 * @notes
 * 	1. The length of argv needs to be more than 1:
 * 		The function doesn't perform validation.
************************************/
//char * _opt_Src_File(char * argv)
char * _opt_Src_File(char ** argv, char *current_dir)
{
//    //log
//    printf("[%s:%d] Starts => _opt_Src_File\n", base_name(__FILE__), __LINE__);

    
    char *opt_SrcFile = "-src";

    int increment = 1;

    char *src_file_path = NULL;

    // Flag:
    //	If "-src" option is present, and the following argument
    //		given => the flag gets changed to 1.
    //	If, after the while loop, this flag is still 0, that means
    //		option switch is not given in argv
    //	=> if so, copy the first argument to src_file_path
    int flag_src = 0;

    // Inspect args
    while(*(argv + increment) != NULL) {

//    //log
//    printf("[%s:%d] *argv => %s\n", base_name(__FILE__), __LINE__, *(argv + increment));


	int res = strcmp(*(argv + increment), opt_SrcFile);
//		int res = strcmp(*argv, opt_RGB);

	if (res == 0) {

		increment ++;

		// Chech if an argument exists after the "-src" switch
		//	=> If doesn't, then the function returns NULL
		if (*(argv + increment) != NULL) {
//			if (*argv != NULL) {

			//log
			printf("[%s:%d] source option => %s\n",
					base_name(__FILE__), __LINE__, *(argv + increment));
//						base_name(__FILE__), __LINE__, *argv);

			src_file_path = malloc(sizeof(char) * strlen(*(argv + increment)));

			strcpy(src_file_path, *(argv + increment));
//				strcpy(src_file_path, strlen(*(argv + increment)));

			// Value is given for "-src" switch
			//	=> set the flag to 1
			flag_src = 1;

		} else {

			// Corresponding argument for "-src" switch is not given
			//	=> return NULL

			//log
			printf("[%s:%d] Source file option => corresponding value missing\n",
					base_name(__FILE__), __LINE__);

			return NULL;


		}//if (*argv != NULL)

		// "-src" switch given; also, the correspoinding values is
		//		given => Leave the while loop
		break;

	} else {//if (res == 0)

//			// No "-src" switch => First argument(next to the program name)
//			//	is used as the source pgm file name
//
//			src_file_path = malloc(sizeof(char) * strlen(*(argv + increment)));
//
//			strcpy(src_file_path, argv[1]);

	}//if (res == 0)

//		argv++;
	increment ++;

    }//while(*argv != NULL)

//    //log
//    printf("[%s:%d] while loop => ended (flag_src=%d)\n",
//		base_name(__FILE__), __LINE__, flag_src);

    
    /////////////////////////////////////////

    // Check: source path obtained in the while loop?
    //			=> i.e. the flag is still 0?
    //		If so, add the given cuurent_path to
    //			src_file_path

    /////////////////////////////////////////
    if (flag_src == 0) {

	    // No "-src" switch => First argument(next to the program name)
	    //	is used as the source pgm file name

	    // Reset the incrementor to 1
	    increment = 1;

	    src_file_path = (char *) malloc(sizeof(char) * (strlen(argv[1]) + 1));
//	    src_file_path = malloc(sizeof(char) * strlen(argv[1]));
//	    src_file_path = malloc(sizeof(char) * strlen(*(argv + increment)));
	    
//	    //log
//	printf("[%s:%d] (argv + increment) => %s\n",
//		base_name(__FILE__), __LINE__, *(argv + increment));
////		base_name(__FILE__), __LINE__, (argv + increment));

	    //log
	    printf("[%s:%d] malloc => done\n", base_name(__FILE__), __LINE__);

	    
	    strcpy(src_file_path, argv[1]);
	    
	    *(src_file_path + strlen(argv[1])) = '\0';
//	    *(src_file_path + strlen(argv[1]) + 1) = '\0';
	    
//	    //log
//	    printf("[%s:%d] strcpy => done (src_file_path=%s)\n",
//		    base_name(__FILE__), __LINE__, src_file_path);

    }

    //////////////////////////////////////

    // Modify: file path
    //	=> if no dir path ===> add the current dir path

    //////////////////////////////////////

    // - Split src_file_path
    // - If the length of the tokens => < 2
    //		=> this means that the src_file_path doesn't contain
    //			a dir path
    // - If so, add the current dir to src_file_path
    // - Otherwise, do nothing to src_file_path

    char sep = get_FileSep();
    int count;

//    //log
//    printf("[%s:%d] sep => %c\n", base_name(__FILE__), __LINE__, sep);
//
//    //log
//    printf("[%s:%d] Calling => str_split_3()\n", base_name(__FILE__), __LINE__);

    str_split_3(src_file_path, sep, &count);

//    //log
//    printf("[%s:%d] done => str_split_3()\n", base_name(__FILE__), __LINE__);

    
    if (count < 2) {
	    // Lengh is less than 2: Meaning
	    //	src_file_path has no dir part
	    //	=> add the current dir string

	    char *sep_string = get_FileSep_Str(); // get_FileSep_Str() :: lib_2.h

	    src_file_path = concat3(current_dir, sep_string, src_file_path);

    }

    return src_file_path;

}//char * _opt_Src_File(char * argv)

/************************************
 * _opt_Dst_File(char ** argv, char *current_dir)
 *
 * @return char pointer
 * 	=> For each format of input:
 * 		- <program> abc.txt				=> <current_dir>\abc.txt
 * 		- <program> [arg] -dst abc.txt	=> <current_dir>\abc.txt
 * 		- <program> XXX\abc.txt			=> XXX\abc.txt
 * 		- <program> [arg] -dst XXX\abc.txt	=> XXX\abc.txt
 * @notes
 * 	1. The length of argv needs to be more than 1:
 * 		The function doesn't perform validation.
************************************/
char * _opt_Dst_File
(char ** argv, char *current_dir, char *src_file_path)
{

	char *opt_DstFile = "-dst";

	int increment = 1;

	char *dst_file_path = NULL;

	// Flag:
	//	If "-dst" option is present, and the following argument
	//		given => the flag gets changed to 1.
	//	If, after the while loop, this flag is still 0, that means
	//		option switch is not given in argv
	//	=> if so, copy the first argument to dst_file_path
	int flag_dst = 0;

#ifdef DEBUG
	//log
	printf("[%s:%d] *(argv + increment) => %s\n",
			base_name(__FILE__), __LINE__, *(argv + increment));
#endif

	// Inspect args
	while(*(argv + increment) != NULL) {

		int res = strcmp(*(argv + increment), opt_DstFile);
//		int res = strcmp(*argv, opt_RGB);

#ifdef DEBUG
		//log
		printf("[%s:%d] res => %d\n", base_name(__FILE__), __LINE__, res);
#endif

		if (res == 0) {

//			argv++;
			increment ++;

			// Chech if an argument exists after the "-dst" switch
			//	=> If doesn't, then the function returns NULL
			if (*(argv + increment) != NULL) {
//			if (*argv != NULL) {

				//log
				printf("[%s:%d] source option => %s\n",
						base_name(__FILE__), __LINE__, *(argv + increment));
//						base_name(__FILE__), __LINE__, *argv);
#ifdef DEBUG
				//log
				printf("[%s:%d] strlen(*(argv + increment)) => %d\n",
						base_name(__FILE__), __LINE__, strlen(*(argv + increment)));
#endif

				dst_file_path = malloc(sizeof(char) * strlen(*(argv + increment)));

#ifdef DEBUG
				//log
				printf("[%s:%d] malloc => done\n", base_name(__FILE__), __LINE__);
#endif

				strcpy(dst_file_path, *(argv + increment));
//				strcpy(src_file_path, strlen(*(argv + increment)));

#ifdef DEBUG
				//log
				printf("[%s:%d] strcpy => done\n", base_name(__FILE__), __LINE__);
#endif
				// Value is given for "-dst" switch
				//	=> set the flag to 1
				flag_dst = 1;

			} else {

				// Corresponding argument for "-dst" switch is not given
				//	=> return NULL

				//log
				printf("[%s:%d] Source file option => corresponding value missing\n",
						base_name(__FILE__), __LINE__);

				return NULL;


			}//if (*argv != NULL)

			// "-dst" switch given; also, the correspoinding values is
			//		given => Leave the while loop
			break;

		} else {//if (res == 0)

//			// No "-dst" switch => First argument(next to the program name)
//			//	is used as the source pgm file name
//
//			src_file_path = malloc(sizeof(char) * strlen(*(argv + increment)));
//
//			strcpy(src_file_path, argv[1]);

		}//if (res == 0)

//		argv++;
		increment ++;

	}//while(*argv != NULL)

	/////////////////////////////////////////

	// Check: dst path not obtained in the while loop?
	//			=> i.e. the flag is still 0?
	//		If so, use the src_file_path as the source
	//			file name
	//		=> Just that the file extension is changed to
	//			".ppm"

	/////////////////////////////////////////
	if (flag_dst == 0) {

		// No "-dst" switch => First argument(next to the program name)
		//	is used as the source pgm file name
	
		// Reset the incrementor to 1
	    
		increment = 1;

		/************************************
		 * - Right-split the src_file_path
		 * - If the return is NULL
		 * 		=> just copy src_file_path to dst...
		 * - Otherwise, concatenate the first token and ".ppm"
		 * 		and copy the product to dst...
		************************************/
		int tmp_i;

		char delim = '.';

		char *ppm_extension = ".ppm";

//		char **splits = str_split_r_2(string, delim, &count);;
		char **splits = str_split_r_2(src_file_path, delim, 1, &tmp_i);

		if (splits != NULL) {

			//log
			printf("[%s:%d] *splits => %s\n",
					base_name(__FILE__), __LINE__, *splits);


			int len = strlen(*splits) + strlen(ppm_extension) + 1;
//
			//log
			printf("[%s:%d] len => %d\n", base_name(__FILE__), __LINE__, len);

			dst_file_path = malloc(sizeof(char) * len);

			dst_file_path = concat(*splits, ppm_extension);

			//log
			printf("[%s:%d] dst_file_path => %s\n",
					base_name(__FILE__), __LINE__, dst_file_path);


//			dst_file_path = malloc(sizeof(char) *
//						strlen(*splits) + strlen(ppm_extension) + 1);

		} else {

			dst_file_path = malloc(sizeof(char) * strlen(src_file_path));

			strcpy(dst_file_path, src_file_path);

		}


//		strcpy(dst_file_path, argv[1]);

		// Split the string with the delimiter '.'
		// If the length of the tokens is more than 1
		//		=> The last token gets changed to "ppm"
		//		=> then, concatenate the tokens
		//
		// If the length is 1
		//		=> Just add the ppm extension to the string
		//		=> i.e. concatenete the token with the extension
		//			string
		// If the length is 0
		//		=> Means the program can't generate the
		//			output file name
		//		=> return NULL

	}//if (flag_dst == 0)

	//////////////////////////////////////

	// Modify: file path
	//	=> if no dir path ===> add the current dir path

	//////////////////////////////////////
	char sep = get_FileSeparator();
	int count;

	str_split_3(dst_file_path, sep, &count);

	// Lengh is less than 2: Meaning
	//	dst_file_path has no dir part
	//	=> add the current dir string
	if (count < 2) {

		char *sep_string = get_FileSep_Str(); // get_FileSep_Str() :: lib_2.h

		dst_file_path = concat3(current_dir, sep_string, dst_file_path);

	}

	return dst_file_path;

}//char * _opt_Dst_File(char ** argv, char *current_dir)

/*******************************
 int _opt_ForceCreate_RootDst(char **argv)
 * @return 1 => "-f" option set
 *	    0 => not set 
 *******************************/
int _opt_ForceCreate_RootDst(char **argv)
{
    char *opt_ForceCreate_RootDst = "-f";

    int increment = 1;

    int flag = 0;

    // Inspect args
    while(*(argv + increment) != NULL) {
	
	int res = strcmp(*(argv + increment), opt_ForceCreate_RootDst);
//		int res = strcmp(*argv, opt_RGB);

	if (res == 0) {
	    
	    flag = 1;
	    
	    break;

	}//if (res == 0)

//		argv++;
	increment ++;

    }//while(*argv != NULL)
    
    return flag;
    
}

_opt_OverWrite_DstFile(char **argv)
{
    char *opt_OverWrite_DstFile = "-ff";

    int increment = 1;

    int flag = 0;

    // Inspect args
    while(*(argv + increment) != NULL) {
	
	int res = strcmp(*(argv + increment), opt_OverWrite_DstFile);
//		int res = strcmp(*argv, opt_RGB);

	if (res == 0) {
	    
	    flag = 1;
	    
	    break;

	}//if (res == 0)

//		argv++;
	increment ++;

    }//while(*argv != NULL)
    
    return flag;
    
}

char * conv_DstFile_Name(char *image_file_dst, int *rgb[3])
{
//    int len = strlen(image_file_dst);
    
    int num_of_tokens;
    
    char **tokens = str_split_r_2(image_file_dst, '.', 1, &num_of_tokens);
    
    char rgb_string[15];
    
    sprintf(rgb_string, "_rgb=%d,%d,%d", (int) rgb[0], (int) rgb[1], (int) rgb[2]);
//    sprintf(rgb_string, "_rgb=%d,%d,%d", rgb[0], rgb[1], rgb[2]);
    
    char *tmp = concat3(*tokens, rgb_string, ".ppm");
    
//    char *tmp = concat(tmp1, ".ppm");
    
//    len += strlen(rgb_string);
//    
//    len ++; // length for separator char
    
//    char *tmp = (char *) malloc(sizeof(char) * (len + 1));
    
//    strcpy(tmp, image_file_dst);
    
//    *(tmp + len) = '\0';
    
    return tmp;
    
    
//    //log
//    printf("[%s:%d] image_file_dst => %s\n",
//	    base_name(__FILE__), __LINE__, image_file_dst);

//    char **tmp = str_split_r_2()
}
