#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

/*******************************
  int RetVals get_PGM_2(char *file_path, PGM *pgm)
 * @return -2	=> can't open the file, or the file doesn't exist
 *	    -1	=> The file format is not P5
 *	    1	=> a PGM obtained
 *******************************/
int get_PGM_2(char *file_path, PGM *pgm)
{
    /************************************
     * Get: file
    ************************************/
    FILE *fp;

    if ( (fp = fopen( file_path, "rb" ))==NULL ){
        printf("The file doesn't exist, or can't open: %s\n", file_path);

        return -2;

    }

    /************************************
     * Read: header
    ************************************/
    //log
    printf("[%s:%d] pgm file => Reading header...\n", base_name(__FILE__), __LINE__);

    
    int res_i;
    
    //REF pass pointer http://www.geekpage.jp/programming/c/func-pointer-arg.php
    res_i = get_PGM(fp, pgm);
//    enum RetVals res = get_PGM(fp, &pgm);

    if (res_i == 1) {	// pgm => obtained

//    	char *tmp_msg = "[%s:%d] pgm => obtained\n";

	printf("[%s:%d] pgm => obtained\n",
			base_name(__FILE__), __LINE__);

	fclose(fp);

	return 1;

    } else {

	    printf("[%s:%d] file format => not P5\n", __FILE__, __LINE__);

	    fclose(fp);

	    return -1;

    }

}//enum RetVals get_PGMHeader(FILE* fp)

/*******************************
 int RetVals get_PGM(FILE* fp, PGM *pgm)
 * @return -1 =>  The file format is not P5
 *	    1 => PGM obtained
 *******************************/
int get_PGM(FILE* fp, PGM *pgm)
{
    char buffer[MAX_BUFFERSIZE];  /* �f�[�^�ǂݍ��ݗp��ƕϐ� */
    int max_gray; /* �ő�K���l */
    int x, y; /* ���[�v�ϐ� */

    int i, j;

//    gray grays[];

//    PGM pgm;

	/************************************
	 * Read: header
	************************************/


    fgets( buffer, MAX_BUFFERSIZE, fp );
    if ( buffer[0] != 'P' || buffer[1] != '5' ){
//        printf("File format => not P5 (given=%c%c)\n", buffer[0], buffer[1]);
//        printf( "File format => not P5 (given=%s)\n", buffer );
//        printf("File format => not P5 (given=%c%c)\n", buffer[0], buffer[1]);
//        exit(1);
//    	return NULL;
    	return -1;

    }

    //log
    printf("[%s:%d] whie loop => starting...\n", base_name(__FILE__), __LINE__);

    
    // file name
    while ( 1 ){
		fgets( buffer, MAX_BUFFERSIZE, fp );
		if ( buffer[0] = '#' ) {

			pgm->file_name = (char *) malloc (sizeof(char) * (strlen(buffer) + 1));
//			file_name = (char *) malloc (sizeof(char) * (strlen(buffer) + 1));

			sscanf( buffer, "#%s", pgm->file_name );
//			sscanf( buffer, "#%s", file_name );

			break;

		}

	}//while ( 1 )

    x = 0; y = 0;

    while ( x == 0 || y == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' )
            sscanf( buffer, "%d %d", &x, &y );
    }

    max_gray = 0;
    while ( max_gray == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' )
            sscanf( buffer, "%d", &max_gray );
    }

    /* Display the parameters */
//    printf( "pixels(x) = %d, pixels(y) = %d\n", x, y );
//    printf( "max brightness = %d\n",max_gray );

    /************************************
	 * read: grays
	************************************/
    pgm->grays = (gray *) malloc (sizeof(gray) * ((x * y) + 1));
//    pgm->grays = (gray *) malloc (sizeof(gray) * (x + 1));

    int pos = 0;

    for (i = 0; i < y; ++i) {

    	for (j = 0; j < x; ++j) {

			pgm->grays[pos] = (unsigned char)fgetc( fp );

			pos ++;
	//    	pgm->grays[i] = (unsigned char)fgetc( fp );
	//    	grays[i] = (unsigned char)fgetc( fp );

		}



	}


    /************************************
	 * PGM
	************************************/
    pgm->x = x;
    pgm->y = y;
    pgm->max_gray = max_gray;

//    pgm->grays = grays;	// invalid use of flexible array member
//    *(pgm->grays) = grays;	// assignment makes integer from pointer without a cast
//    &(pgm->grays) = grays;	// invalid lvalue in assignment

//    pgm.x = x;
//    pgm.y = y;
//    pgm.max_gray = max_gray;

//    return pgm;
    return 1;

}//enum RetVals get_PGMHeader(FILE* fp)

/*******************************
 int conv_PGM2PPM(PGM *pgm, PPM *ppm)
 * @return 1 => conversion done 
 *******************************/
int conv_PGM2PPM(PGM *pgm, PPM *ppm, int *rgb[3])
{
    /************************************
     * Build ppm: header
    ************************************/
//	fputs( "P6\n", fp );

    // file name
//	fprintf( fp, "# %s\n", pgm->file_name );
//	ppm->file_name = base_name(file_path_dst);
//	ppm->file_name = pgm->file_name;

    // format
    strcpy(ppm->format, "P6");
    
    ppm->format[2] = '\0';
    
//    ppm->format


    // size
//	fprintf( fp, "%d %d\n", pgm->x, pgm->y );
    ppm->x = pgm->x;
    ppm->y = pgm->y;

    // max brightness
//	fprintf( fp, "%d\n", pgm->max_gray );
    ppm->max_brightness = pgm->max_gray;

//	tmp_msg = "[%s:%d] ppm header => created\n";

    printf("[%s:%d] ppm header => created\n",
		    base_name(__FILE__), __LINE__);

//	tmp_msg = "[%s:%d] ppm->file_name => %s\n";

//	printf("[%s:%d] ppm->file_name => %s\n",
//			base_name(__FILE__), __LINE__, ppm->file_name);

    /************************************
     * Build ppm: body
    ************************************/
    int position = 0;

    int i, j;

    int num_of_pixels = ppm->x * ppm->y;

    ppm->pixels = (pixel *) malloc (sizeof(pixel) * num_of_pixels);

//	tmp_msg = "[%s:%d] ppm->x = %d, ppm->y = %d\n";
//
//	printf(tmp_msg, base_name(__FILE__), __LINE__, ppm->x, ppm->y);

    //log
//    printf("[%s:%d] pgm->grays[0] => %d\n",
//	    base_name(__FILE__), __LINE__, (pgm->grays[0] * (rgb[0] / 100)));
    //log
//    printf("[%s:%d] rgb[0] => %d\n", base_name(__FILE__), __LINE__, rgb[0]);
//    printf("[%s:%d] pgm->grays[0] => %d\n",
//		base_name(__FILE__), __LINE__, (pgm->grays[0] * rgb[0]) / 100);
//    //log
//    printf("[%s:%d] pgm->grays[0] => %d\n", base_name(__FILE__), __LINE__, pgm->grays[0]);
    
//    int tmp_i = (pgm->grays[0]) * rgb[0];
//    int tmp_i = (pgm->grays[0]);
//
//    tmp_i += 200 / 100;
    
//    int tmp_2 = rgb[0];	// warning: initialization makes integer from pointer without a cast
//    int tmp_2 = (int) rgb[0];	// works
//    int tmp_2 = rgb[0] / 100;	// invalid operands to binary /
//    int tmp_2 = (int) rgb[0] / 100;	// compile through
    
    //log
//    printf("[%s:%d] tmp_i => %d\n", base_name(__FILE__), __LINE__, tmp_i);

//    tmp_i = (int) pgm->grays[position] * (*rgb[0] / 100); // compile ok, program stops
//    tmp_i = (int) pgm->grays[position] * (*rgb[0] / 100); // works
    
//    tmp_i = (int) pgm->grays[position] * (rgb[0] / 100);  // error: invalid operands to binary /
//    tmp_i = (int) pgm->grays[position] * ((int) rgb[0] / 100);    // 0
//    tmp_i = ((int) pgm->grays[position] * (int) rgb[0]) / 100;	// 16
//    tmp_i = ((int) pgm->grays[position] * rgb[0]) / 100;    // error: invalid operands to binary *
//    tmp_i = ((int) pgm->grays[position] * (int) rgb[0]) / 100;
//    
//    //log
//    printf("[%s:%d] tmp_i => %d\n", base_name(__FILE__), __LINE__, tmp_i);

    for (i = 0; i < ppm->y; ++i) {

	for (j = 0; j < ppm->x; ++j) {

	    ppm->pixels[position].r = ((int) pgm->grays[position] * (int) rgb[0]) / 100;
	    ppm->pixels[position].g = ((int) pgm->grays[position] * (int) rgb[1]) / 100;
	    ppm->pixels[position].b = ((int) pgm->grays[position] * (int) rgb[2]) / 100;

//	    ppm->pixels[position].r = (int) pgm->grays[position] * (*rgb[0] / 100);
//	    ppm->pixels[position].g = (int) pgm->grays[position] * (*rgb[1] / 100);
//	    ppm->pixels[position].b = (int) pgm->grays[position] * (*rgb[2] / 100);
	    
//	    ppm->pixels[position].r = pgm->grays[position];
//	    ppm->pixels[position].g = pgm->grays[position];
//	    ppm->pixels[position].b = pgm->grays[position];
//			ppm->pixels[position].r = 0;
//			ppm->pixels[position].g = 0;

	    position ++;

	}
    }

//	tmp_msg = "[%s:%d] Build ppm body => done\n";

    printf("[%s:%d] Build ppm body => done\n",
		    base_name(__FILE__), __LINE__);

    return 1;
    
}//enum RetVals conv_PGM2PPM
