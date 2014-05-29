/*
 * Proc_Wave.c
 *
 *  Created on: 2014/05/29
 *      Author: iwabuchik
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/*********************************
 * includes
 *
 * main.h	lib.h		ppmlib.h
 * wave.h	methods.h
 *
**********************************/

#ifndef MAIN_H_
#include "../include/main.h"
#endif

//#ifndef LIB_H
//#include "../include/lib.h"
//#endif

#ifndef PPMLIB_H
#include "../include/ppmlib.h"
#endif

#ifndef WAVE_H
//#define WAVE_H
#include "../include/wave.h"
#endif

//#ifndef IMG_LIB_H
//#include "../include/img_lib.h"
//#endif

#ifndef METHODS_H
#include "../include/methods.h"
#endif

/////////////////////////////////////

// global vars

/////////////////////////////////////
MONO_PCM pcm0, pcm1;

char *file_src_wave;
char *file_dst_wave;

/////////////////////////////////////

// prototypes

/////////////////////////////////////
void _Setup_Options_ProcWave(int argc, char **argv);
void _Setup_Options_ProcWave__Src(char **argv);
void _Setup_Options_ProcWave__Dst(char **argv);

void Proc_Wave__SaveWave(void);
void Proc_Wave__ReadWave(void);

/////////////////////////////////////

// Proc_Wave()

/////////////////////////////////////
void Proc_Wave(int argc, char **argv)
{
//	MONO_PCM pcm0, pcm1;
//	int n;

	/*********************************
	 * Options
	**********************************/
	_Setup_Options_ProcWave(argc, argv);

	/*********************************
	 * Read: wave
	**********************************/
	Proc_Wave__ReadWave();

//	mono_wave_read(&pcm0, file_src_wave); /* WAVEファイルからモノラルの音データを入力する */
////	mono_wave_read(&pcm0, "./audio/a.wav"); /* WAVEファイルからモノラルの音データを入力する */
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

	/*********************************
	 * Save: wav file
	**********************************/
	Proc_Wave__SaveWave();

//	char delim = '.';
//
//	int position = 1; int num_of_tokens;
//
//	char **tokens = (char **) str_split_r_2
//			(file_dst_wave, delim, position, &num_of_tokens);
//
//	int tmp_i = 4;
//
//	char **tmp = (char **) malloc(sizeof(char *) * tmp_i);
//
//	tmp[0] = tokens[0];
//	tmp[1] = "_";
//	tmp[2] = get_TimeLabel_Now(SERIAL);
//	tmp[3] = ".wav";
////	tmp[0] = "./audio/";
////	tmp[1] = "b_";
////	tmp[2] = get_TimeLabel_Now(SERIAL);
////	tmp[3] = ".wav";
//
//	char *file_dst = join_simple(tmp, tmp_i);
//
//	free(file_dst_wave);
//
//	file_dst_wave = file_dst;
//
//	mono_wave_write(&pcm1, file_dst_wave); /* WAVEファイルにモノラルの音データを出力する */
////	mono_wave_write(&pcm1, file_dst_wave); /* WAVEファイルにモノラルの音データを出力する */
////	mono_wave_write(&pcm1, file_dst); /* WAVEファイルにモノラルの音データを出力する */
////	mono_wave_write(&pcm1, "b.wav"); /* WAVEファイルにモノラルの音データを出力する */
//
//	//log
//	printf("[%s : %d] wave => written: %s\n", base_name(__FILE__), __LINE__, file_dst);


	/*********************************
	 * Free: pcms
	**********************************/
	free(pcm0.s); /* メモリの解放 */
	free(pcm1.s); /* メモリの解放 */
//

	//log
	printf("[%s : %d] Proc_Wave => done\n",
				base_name(__FILE__), __LINE__);


}//void Proc_Wave(int argc, char **argv)

void _Setup_Options_ProcWave(int argc, char **argv)
{
	/*********************************
	 * Opt: size
	**********************************/
	_Setup_Options_ProcWave__Src(argv);

	/*********************************
	 * Opt: dst
	**********************************/
	_Setup_Options_ProcWave__Dst(argv);

//	/*********************************
//	 * Opt: bright
//	**********************************/
//	_Setup_Options_ProcWave__Bright(argv);
//
//	/*********************************
//	 * Opt: background
//	**********************************/
//	_Setup_Options_ProcWave__Bg(argv);
//

}

void _Setup_Options_ProcWave__Src(char **argv) {

	char *opt_key_Src = "-src";

	file_src_wave = (char *) get_Opt_Value(argv, opt_key_Src);

	/*********************************
	 * validate: exists?
	**********************************/
	int res_i = fileExists(file_src_wave);

	if (res_i == false) {

		consolColor_Change(RED);
		//log
		printf("[%s : %d] Src file => deosn't exist(%s)\n",
				(char *) base_name(__FILE__), __LINE__, file_src_wave);

		consolColor_Reset();

		exit(-1);

	}

	consolColor_Change(GREEN);
	//log
	printf("[%s : %d] file_src_wave => %s\n",
			(char *) base_name(__FILE__), __LINE__, file_src_wave);

	consolColor_Reset();

}//void _Setup_Options_ProcWave__Src(char **argv)

void _Setup_Options_ProcWave__Dst(char **argv) {

	char *opt_key_Dst = "-dst";

	file_dst_wave = (char *) get_Opt_Value(argv, opt_key_Dst);

//	char delim = '.';
//
//	int position = 1; int num_of_tokens;
//
//	char **tokens = (char **) str_split_r_2
//			(file_dst_wave, delim, position, &num_of_tokens);

	//log
	printf("[%s : %d] dir name => %s\n",
			base_name(__FILE__), __LINE__, dir_name(file_dst_wave));

	/*********************************
	 * validate: folder exists?
	**********************************/
	char *dname = dir_name(file_dst_wave);

	if (dname != NULL) {

		int res_i = dirExists(dname);

		if (res_i != 1) {

			consolColor_Change(RED);

			//log
			printf("[%s : %d] Dst dir => doesn't exist: %s\n",
						base_name(__FILE__), __LINE__, dname);

			consolColor_Reset();

			exit(-1);

		}

	}


	consolColor_Change(GREEN);
	//log
	printf("[%s : %d] file_dst_wave => %s\n",
			(char *) base_name(__FILE__), __LINE__, file_dst_wave);

	consolColor_Reset();

}//void _Setup_Options_ProcWave__Dst(char **argv)

void Proc_Wave__SaveWave()
{
	char delim = '.';

	int position = 1; int num_of_tokens;

	char **tokens = (char **) str_split_r_2
			(file_dst_wave, delim, position, &num_of_tokens);

	int tmp_i = 4;

	char **tmp = (char **) malloc(sizeof(char *) * tmp_i);

	tmp[0] = tokens[0];
	tmp[1] = "_";
	tmp[2] = get_TimeLabel_Now(SERIAL);
	tmp[3] = ".wav";
//	tmp[0] = "./audio/";
//	tmp[1] = "b_";
//	tmp[2] = get_TimeLabel_Now(SERIAL);
//	tmp[3] = ".wav";

	char *file_dst = join_simple(tmp, tmp_i);

	free(file_dst_wave);

	file_dst_wave = file_dst;

	mono_wave_write(&pcm1, file_dst_wave); /* WAVEファイルにモノラルの音データを出力する */
//	mono_wave_write(&pcm1, file_dst_wave); /* WAVEファイルにモノラルの音データを出力する */
//	mono_wave_write(&pcm1, file_dst); /* WAVEファイルにモノラルの音データを出力する */
//	mono_wave_write(&pcm1, "b.wav"); /* WAVEファイルにモノラルの音データを出力する */

	//log
	printf("[%s : %d] wave => written: %s\n", base_name(__FILE__), __LINE__, file_dst);

}

void Proc_Wave__ReadWave()
{
	int n;

	mono_wave_read(&pcm0, file_src_wave); /* WAVEファイルからモノラルの音データを入力する */
//	mono_wave_read(&pcm0, "./audio/a.wav"); /* WAVEファイルからモノラルの音データを入力する */
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

}
