#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

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
