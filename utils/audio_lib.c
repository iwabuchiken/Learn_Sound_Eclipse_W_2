#ifndef AUDIO_LIB_H
#include "../include/audio_lib.h"
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef LIB_H
#define	LIB_H
#include "lib.h"
#endif


/********************************
    get_Src_Path(char **argv, char *current_dir)
 * 
 * @return NULL => size of argv is less than 2
 ********************************/

char *get_Src_Path(char **argv, char *current_dir)
{
    printf("[%s : %d] Starting => get_Src_Path()\n", base_name(__FILE__), __LINE__);

    printf("[%s : %d] *argv => %s\n", base_name(__FILE__), __LINE__, *argv);

    
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

    if (*(argv + increment) == NULL) {

        printf("[%s : %d] *(argv + increment) => NULL\n", base_name(__FILE__), __LINE__);
        
        return NULL;

    } else {
        
        printf("[%s : %d] *(argv + increment) => not NULL\n", base_name(__FILE__), __LINE__);
        
    }

    
    printf("[%s : %d] *(argv + increment) => %s\n",
    		(char *) base_name(__FILE__), __LINE__, *(argv + increment));

//    printf("[%s : %d] *(argv + increment) => %s\n");
//    printf("[%s : %d] %s\n",
//            base_name(__FILE__), __LINE__, *(argv + increment));

    
    // Inspect args
    while(*(argv + increment) != NULL) {

        printf("[%s : %d] *(argv + increment) => %s\n", 
                (char *) base_name(__FILE__), __LINE__, *(argv + increment));

        
	int res = strcmp(*(argv + increment), opt_SrcFile);

	if (res == 0) {

		increment ++;

		// Chech if an argument exists after the "-src" switch
		//	=> If doesn't, then the function returns NULL
		if (*(argv + increment) != NULL) {

			src_file_path = (char *) malloc(sizeof(char) * strlen(*(argv + increment)));

			strcpy(src_file_path, *(argv + increment));

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

	}//if (res == 0)

	increment ++;

    }//while(*argv != NULL)

    printf("[%s : %d] Endo of while loop\n", base_name(__FILE__), __LINE__);

    
    /////////////////////////////////////////

    // Check: source path obtained in the while loop?
    //			=> i.e. the flag is still 0?
    //		If so, add the given cuurent_path to
    //			src_file_path

    /////////////////////////////////////////
    printf("[%s : %d] flag_src => %d\n", base_name(__FILE__), __LINE__, flag_src);

    
    if (flag_src == 0) {

	    // No "-src" switch => First argument(next to the program name)
	    //	is used as the source pgm file name

	    // Reset the incrementor to 1
	    increment = 1;

	    src_file_path = (char *) malloc(sizeof(char) * (strlen(argv[1]) + 1));

	    //log
	    printf("[%s:%d] malloc => done\n", base_name(__FILE__), __LINE__);
	    
	    strcpy(src_file_path, argv[1]);
	    
	    *(src_file_path + strlen(argv[1])) = '\0';

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

    str_split_3(src_file_path, sep, &count);

    if (count < 2) {
	    // Lengh is less than 2: Meaning
	    //	src_file_path has no dir part
	    //	=> add the current dir string

	    char *sep_string = (char *) get_FileSep_Str(); // get_FileSep_Str() :: lib_2.h

	    src_file_path = (char *) concat3(current_dir, sep_string, src_file_path);

    }

    return src_file_path;
}
