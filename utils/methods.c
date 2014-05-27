#ifndef METHODS_H
//#define	METHODS_H
#include "../include/methods.h"
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
const char *LOG_FILE_PATH = "./log/exec_log.txt";
//const char *LOG_FILE_PATH = "../log/exec_log.txt";

///////////////////////////////////

// Functions

///////////////////////////////////
void show_help(void)
{
    char *msg = "<Usage>\n"
    "\tpngtoppm src1 src2 dst\n"
    "\n"
    "<Options>\n"
    "\t-bg\t background color\n"
    "\t\tred, green, blue, purple, white, black"
    "\t-direc\n"
    "\t\tverti, hori\n"
    
    "\t-proc\n"
    "\t\tProcess png pixels\n"
    
    "\t-rgb\n"
    "\t\tRGB values for \"-proc\" mode\n"
    "\t\te.g. 100,20,50 (R,G,B)\n"
    "\t\te.g. ./dist/Debug/GNU-Linux-x86/pngtoppm\n"
    "\t\t\t-src images/XXX -dst images/YYY -proc -rgb 100,20,20\n"
    ;


//    consolColor_Change(LIGHT_BLUE);
    
    //log
    printf("[%s : %d]\n%s\n", base_name(__FILE__), __LINE__, msg);

    consolColor_Reset();
    
}

void log_Command_Input(int argc, char **argv)
{
	/*********************************
	 * vars
	**********************************/
	char *time_label = get_TimeLabel_Now(STANDARD);

    char joint = ' ';
    
    char *argv_str = join(joint, argv, argc);
    
    FILE *fp;
    
    /*********************************
	 * File: open
	**********************************/
    if((fp = fopen(LOG_FILE_PATH, "a")) == NULL) {
        
        //log
        printf("[%s : %d] Can't open the log file: %s\n", 
                base_name(__FILE__), __LINE__, LOG_FILE_PATH);
        
        exit(-1);

    }

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
