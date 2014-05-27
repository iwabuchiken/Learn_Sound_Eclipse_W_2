#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#ifndef LIB_H
#include "../include/lib.h"
#endif

#ifndef WAVE_H
#include "../include/wave.h"
#endif

//#ifndef IMG_LIB_H
//#include "../include/img_lib.h"
//#endif

#ifndef METHODS_H
#include "../include/methods.h"
#endif

#ifndef MAIN_H_
#include "../include/main.h"
#endif

/////////////////////////////////////

// vars

/////////////////////////////////////
const char *app_names[] = {
		"gen-ppm"

};

/////////////////////////////////////

// Prototypes

/////////////////////////////////////
void _test_FirstProg(void);
void dispather(int, char**);

/////////////////////////////////////

// main()

/////////////////////////////////////
int main(int argc, char** argv) {

	//log
	printf("[%s : %d] main()\n", base_name(__FILE__), __LINE__);
	printf("[%s : %d] argc = %d\n", base_name(__FILE__), __LINE__, argc);


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

//	PPM ppm;
//	PGM pgm;
//
//	_test_FirstProg();

//	MONO_PCM pcm0, pcm1;
//	int n;
//
//	mono_wave_read(&pcm0, "./audio/a.wav"); /* WAVEファイルからモノラルの音データを入力する */
//	//  mono_wave_read(&pcm0, ".\\audio\\a.wav"); /* WAVEファイルからモノラルの音データを入力する */
//	//  mono_wave_read(&pcm0, "..\\audio\\a.wav"); /* WAVEファイルからモノラルの音データを入力する */
//	//  mono_wave_read(&pcm0, "a.wav"); /* WAVEファイルからモノラルの音データを入力する */
//
//	pcm1.fs = pcm0.fs; /* 標本化周波数 */
//	pcm1.bits = pcm0.bits; /* 量子化精度 */
//	pcm1.length = pcm0.length; /* 音データの長さ */
//	pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */
//
//	for (n = 0; n < pcm1.length; n++)
//	{
//		pcm1.s[n] = pcm0.s[n]; /* 音データのコピー */
//	}
//
//	/*********************************
//	 * Save: wav file
//	**********************************/
//	int tmp_i = 3;
//
//	char **tmp = (char **) malloc(sizeof(char *) * tmp_i);
//
//	tmp[0] = "b_";
//	tmp[1] = get_TimeLabel_Now(SERIAL);
//	tmp[2] = ".wav";
//
//	char *file_dst = join_simple(tmp, tmp_i);
//
//	mono_wave_write(&pcm1, file_dst); /* WAVEファイルにモノラルの音データを出力する */
////	mono_wave_write(&pcm1, "b.wav"); /* WAVEファイルにモノラルの音データを出力する */
//
//	free(pcm0.s); /* メモリの解放 */
//	free(pcm1.s); /* メモリの解放 */

#ifndef UBUNTU

	consolColor_Change(0, 0x0f);

#endif
	//log
	printf("[%s : %d] done", base_name(__FILE__), __LINE__);

	consolColor_Reset();

	printf("\n");

	return 0;

}

void _test_FirstProg()
{
	MONO_PCM pcm0, pcm1;
	int n;

	mono_wave_read(&pcm0, "./audio/a.wav"); /* WAVEファイルからモノラルの音データを入力する */
	//  mono_wave_read(&pcm0, ".\\audio\\a.wav"); /* WAVEファイルからモノラルの音データを入力する */
	//  mono_wave_read(&pcm0, "..\\audio\\a.wav"); /* WAVEファイルからモノラルの音データを入力する */
	//  mono_wave_read(&pcm0, "a.wav"); /* WAVEファイルからモノラルの音データを入力する */

	pcm1.fs = pcm0.fs; /* 標本化周波数 */
	pcm1.bits = pcm0.bits; /* 量子化精度 */
	pcm1.length = pcm0.length; /* 音データの長さ */
	pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */

	for (n = 0; n < pcm1.length; n++)
	{
		pcm1.s[n] = pcm0.s[n]; /* 音データのコピー */
	}

	/*********************************
	 * Save: wav file
	**********************************/
	int tmp_i = 3;

	char **tmp = (char **) malloc(sizeof(char *) * tmp_i);

	tmp[0] = "./audio/b_";
	tmp[1] = get_TimeLabel_Now(SERIAL);
	tmp[2] = ".wav";

	char *file_dst = join_simple(tmp, tmp_i);

	mono_wave_write(&pcm1, file_dst); /* WAVEファイルにモノラルの音データを出力する */
//	mono_wave_write(&pcm1, "b.wav"); /* WAVEファイルにモノラルの音データを出力する */

	free(pcm0.s); /* メモリの解放 */
	free(pcm1.s); /* メモリの解放 */

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
	printf("[%s : %d] test_str => %s\n",
			base_name(__FILE__), __LINE__, test_str);


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
	//log
	printf("[%s : %d] app_names[0] => %s\n",
			(char *) base_name(__FILE__), __LINE__, app_names[0]);


	if (!strcmp(opt_val, app_names[0])) {	// "gen-ppm"

		Gen_PPM(argc, argv);

	} else {

	}


}
