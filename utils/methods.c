#ifndef METHODS_H
//#define	METHODS_H
#include "../include/methods.h"
#endif

#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif


//#ifndef PNGLIB_H
////#include "include/pnglib.h"
//#include "include/pnglib.h"
////#include "include/pnglib.h"
//#include "include/pnginfo.h"
//#endif

///////////////////////////////////

// Variables

///////////////////////////////////
//const char *LOG_FILE_PATH = "..\\log\\exec_log.txt";
//const char *LOG_FILE_PATH = ".\\log\\exec_log.txt";
const char *LOG_FILE_PATH = "./log/exec_log.txt";
//const char *LOG_FILE_PATH = "../log/exec_log.txt";

///////////////////////////////////

// Functions

///////////////////////////////////
void show_help(void)
{
    char *msg = "<Usage>\n"
    "Learn_Sound_Eclipse_W.exe -app gen-ppm "
	"-dst images\\test.ppm -size 255,255 -bright 255 -bg red"
    "\n"

	"<Options>\n"
    "\t-bg\t"
    		"background color\n"
    		"\t\tred, green, blue, purple, white, black, gray"

    "\n"

    "\t-dst\t"
    		"dst file name\n"
    		"\t\te.g. images\\test.ppm"

    "\t-bright\t"
    		"max brightness in the ppm file\n"
    		"If not given, the value is set to the default of 255\n"
    		"\t\te.g. 255"

	"\t-save\t"
    		"save a generate wave file\n"

    ;


//    consolColor_Change(LIGHT_BLUE);
    
    //log
    printf("[%s : %d]\n%s\n", base_name(__FILE__), __LINE__, msg);

    consolColor_Reset();

    /*********************************
	 * Color names
	**********************************/
	int tmp_i = 0;

	while(*(Colors + tmp_i)) tmp_i ++;

	char *tmp_ch = join(',', Colors, tmp_i);

	printf("Available color names => %s\n", tmp_ch);

}

void log_Command_Input(int argc, char **argv)
{
	/*********************************
	 * vars
	**********************************/
	char *time_label = get_TimeLabel_Now(STANDARD);

    char joint = ' ';
    
    char *argv_str = join(joint, argv, argc);
    
//    //log
//	printf("[%s : %d] argv_str => %s\n",
//			base_name(__FILE__), __LINE__, argv_str);


    FILE *fp;
    
    /*********************************
	 * File: open
	**********************************/
//    //log
//	printf("[%s : %d] Opening file => %s\n",
//			base_name(__FILE__), __LINE__, LOG_FILE_PATH);

    if((fp = fopen(LOG_FILE_PATH, "a")) == NULL) {
        
        //log
        printf("[%s : %d] Can't open the log file: %s\n", 
                base_name(__FILE__), __LINE__, LOG_FILE_PATH);
        
        exit(-1);

    }

    //log
	printf("[%s : %d] File => opened: %s\n",
			base_name(__FILE__), __LINE__, LOG_FILE_PATH);


    /*********************************
	 * File: write
	**********************************/
    //REF fprintf http://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
    fprintf(fp, "[%s]\n", time_label);
    
    fprintf(fp, "%s\n", "<argv>");
    
    // argc
    fprintf(fp, "argc=%d: ", argc);
    
    fprintf(fp, "%s\n", argv_str);
    
    //REF fputc http://www.cplusplus.com/reference/cstdio/fputc/
    fputc('\n', fp);

    /*********************************
	 * File: close
	**********************************/
    fclose(fp);
    
    //log
    printf("[%s : %d] file => closed: %s\n", 
            base_name(__FILE__), __LINE__, LOG_FILE_PATH);

}

void write_Log
(char *file_name, int line, char *message)
{
    /**************************
     * vars
     **************************/
    char *time_label = get_TimeLabel_Now(STANDARD);
    
    char joint = ' ';
    
//    char *argv_str = join(joint, argv, argc);
    
    FILE *fp;

    /**************************
     * processes
     **************************/
    if((fp = fopen(LOG_FILE_PATH, "a")) == NULL) {
        
        //log
        printf("[%s : %d] Can't open the log file: %s\n", 
                base_name(__FILE__), __LINE__, LOG_FILE_PATH);
        
        exit(-1);

    }
    
    //REF fprintf http://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm
    fprintf(fp, "[%s] [%s : %d]\n", time_label, file_name, line);
//    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
    
    fprintf(fp, "%s\n", message);
    
//    char *CR = "\n";
//    
//    fwrite(CR, 1, sizeof(CR), fp);
//    fwrite('\n', 1, sizeof(char), fp);
    
    //REF fputc http://www.cplusplus.com/reference/cstdio/fputc/
    fputc('\n', fp);
    
    fclose(fp);
    
//    //log
//    printf("[%s : %d] file => closed: %s\n", 
//            base_name(__FILE__), __LINE__, LOG_FILE_PATH);

}

/*********************************
 * get_Opt_Value(char **argv, const char *opt)
 *
 * @return
 * 		1. option value for the given option key
 * 		2. If the value not given => exit(-1)
 *
**********************************/

char *get_Opt_Value(char **argv, const char *opt)
{
//	//log
//	printf("[%s : %d] Starting => get_Opt_Value()\n", base_name(__FILE__), __LINE__);


    char *opt_val;

    int i = 0;
    int flag = false;   // true if "-rgb" values given

    while(*(argv + i) != NULL) {

//    	//log
//		printf("[%s : %d] *(argv + i) => %s\n",
//				base_name(__FILE__), __LINE__, *(argv + i));


        if(!strcmp(*(argv + i), opt)) {
//        if(!strcmp(*(argv + i), "-dst")) {

            i ++;

            if(*(argv + i) != NULL) {

                int len = strlen(*(argv + i));

                opt_val = (char *) malloc(sizeof(char) * (len + 1));

                strcpy(opt_val, *(argv + i));

                opt_val[len] = '\0';

                flag = true;

                break;

            } else {

				consolColor_Change(RED);

                //log
                printf("[%s : %d] value not given for \"%s\"\n",
                        base_name(__FILE__), __LINE__, opt);

                consolColor_Reset();

                consolColor_Change(GREEN);

                show_help();

				consolColor_Reset();


                exit(-1);

            }

        }

        i ++;

    }//while(*(argv + i) != NULL)

    if(flag == false) {

    	consolColor_Change(RED);

        //log
        printf("[%s : %d] \"%s\" option => not given\n",
                base_name(__FILE__), __LINE__, opt);
//        printf("option => not given\n");

        consolColor_Reset();

        consolColor_Change(GREEN);

		show_help();

		consolColor_Reset();

        exit(-1);

    }

//    /**************************
//     * Validate: opt value => in the array?
//     **************************/
//    int res_i =  is_InArray(opt_val, Histo_RGB, Histo_RGB_len);
//
//    if(res_i != true) {
//
//        consolColor_Change(RED);
//
//        //log
//        printf("[%s : %d] Unknown option value for '%s' => %s\n",
//                base_name(__FILE__), __LINE__, opt, opt_val);
//
//        //log
//        char *msg = join(',', Histo_RGB, Histo_RGB_len);
//
//        printf("[%s : %d] Available values =L> %s (%d items)\n",
//                base_name(__FILE__), __LINE__, msg, Histo_RGB_len);
//
//
//        consolColor_Reset();
//
//        exit(-1);
//
//    }

    return opt_val;

}
