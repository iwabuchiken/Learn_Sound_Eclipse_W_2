#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

/*********************************
 * vars
**********************************/
//#define PIXEL_GREEN     0, 100, 0
//#define PIXEL_BLUE      0, 0, 100
//#define PIXEL_RED       100, 0, 0
//#define PIXEL_PURPLE    100, 0, 100
//#define PIXEL_WHITE     100, 100, 100
//#define PIXEL_BLACK     0, 0, 0
//#define PIXEL_GRAY      50, 50, 50

char *Colors[] = {
		"green",	"blue",	"light_blue", "red",
		"purple", "yellow",
		"white",	"black", "gray",
		NULL
};

/*******************************
 int save_PPM(char *dst_file_path, PPM *ppm_dst)
 * @return 1 => PPM file written 
 *******************************/
int save_PPM(char *dst_file_path, PPM *ppm_dst)
{
    /************************************
     * vars
    ************************************/
    int i, j;

    /************************************
     * Get: file
    ************************************/
    FILE *fp;

    if ( (fp = fopen( dst_file_path, "wb" ))==NULL ){
//    if ( (fp = fopen( file_name, "rb" ))==NULL ){
//    if ( (fp = fopen( file_name, "rb" ))==NULL ){
        printf("Can't open the file: %s\n", dst_file_path);

        return FileDoesntExist;

    }

    /*******************************
     * Add file name to PPM instance
     *******************************/
    int len = strlen(base_name_2(dst_file_path));
    
    ppm_dst->file_name = (char *) malloc(sizeof(char) * (len + 1));
    
    strcpy(ppm_dst->file_name, base_name_2(dst_file_path));
    
    *(ppm_dst->file_name + len) = '\0';
    
    /************************************
     * Write: header
    ************************************/
    // format
    fputs( "P6\n", fp );

    // file name
    fprintf( fp, "# %s\n", ppm_dst->file_name );

    fprintf( fp, "%d %d\n", ppm_dst->x, ppm_dst->y );

    /* �ő�K���l�̏o�� */
    fprintf( fp, "%d\n", ppm_dst->max_brightness );

//	char *tmp_msg = "[%s:%d] ppm_dst header => written\n";

    printf("[%s:%d] ppm_dst header => written\n",
		    base_name_2(__FILE__), __LINE__);

//	printf("[%s:%d] ppm header => written\n", __FILE__, __LINE__);

    /************************************
     * write: body
    ************************************/
    int position = 0;

    for (i = 0; i < ppm_dst->y; ++i) {

	    for (j = 0; j < ppm_dst->x; ++j) {

		    fputc( ppm_dst->pixels[position].r, fp );
//			fputc( 0, fp );
//			fputc( 0, fp );
		    fputc( ppm_dst->pixels[position].g, fp );
		    fputc( ppm_dst->pixels[position].b, fp );

		    position ++;
	    }

    }//for (i = 0; i < ppm_dst->y; ++i)

    /************************************
     * return
    ************************************/
    return 1;

}//enum RetVals save_PPM(FILE *fp, PPM *ppm_dst)

/*******************************
 int save_PPM(char *dst_file_path, PPM *ppm_dst)
 * @return 1 => PPM file written
 *******************************/
int save_PPM2(char *dst_file_path, PPM2 *ppm_dst)
{
    /************************************
     * vars
    ************************************/
    int i, j;

    /************************************
     * Get: file
    ************************************/
    FILE *fp;

    if ( (fp = fopen( dst_file_path, "wb" ))==NULL ){
//    if ( (fp = fopen( file_name, "rb" ))==NULL ){
//    if ( (fp = fopen( file_name, "rb" ))==NULL ){
        printf("Can't open the file: %s\n", dst_file_path);

        return FileDoesntExist;

    }

    /*******************************
     * Add file name to PPM instance
     *******************************/
    int len = strlen(base_name_2(dst_file_path));

    ppm_dst->file_name = (char *) malloc(sizeof(char) * (len + 1));

    strcpy(ppm_dst->file_name, base_name_2(dst_file_path));

    *(ppm_dst->file_name + len) = '\0';

    /************************************
     * Write: header
    ************************************/
    // format
    fputs( "P6\n", fp );

    // file name
    fprintf( fp, "# %s\n", ppm_dst->file_name );

    fprintf( fp, "%d %d\n", ppm_dst->x, ppm_dst->y );

    /* �ő�K���l�̏o�� */
    fprintf( fp, "%d\n", ppm_dst->max_brightness );

//	char *tmp_msg = "[%s:%d] ppm_dst header => written\n";

    printf("[%s:%d] ppm_dst header => written\n",
		    base_name_2(__FILE__), __LINE__);

//	printf("[%s:%d] ppm header => written\n", __FILE__, __LINE__);

    /************************************
     * write: body
    ************************************/
//    int position = 0;

    for (i = 0; i < ppm_dst->y; ++i) {

	    for (j = 0; j < ppm_dst->x; ++j) {

		    fputc( ppm_dst->pixels[i][j].r, fp );
//			fputc( 0, fp );
//			fputc( 0, fp );
		    fputc( ppm_dst->pixels[i][j].g, fp );
		    fputc( ppm_dst->pixels[i][j].b, fp );
//		    fputc( ppm_dst->pixels[position].r, fp );
////			fputc( 0, fp );
////			fputc( 0, fp );
//		    fputc( ppm_dst->pixels[position].g, fp );
//		    fputc( ppm_dst->pixels[position].b, fp );

//		    position ++;
	    }

    }//for (i = 0; i < ppm_dst->y; ++i)

    /************************************
     * return
    ************************************/
    return 1;

}//int save_PPM2(char *dst_file_path, PPM2 *ppm_dst)

void set_PixelVals(PPM *ppm, int position, int rgb[3])
//void set_PixelVals(PPM *ppm, int position, int r, int g, int b)
{

	ppm->pixels[position].r = PPM_MAX_BRIGHTNESS * rgb[0] / 100;
	ppm->pixels[position].g = PPM_MAX_BRIGHTNESS * rgb[1] / 100;
	ppm->pixels[position].b = PPM_MAX_BRIGHTNESS * rgb[2] / 100;

}
