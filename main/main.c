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

#ifndef IMG_LIB_H
#include "../include/img_lib.h"
#endif

/*********************************
 * Prototypes
**********************************/
void _test_FirstProg(void);

int main(int argc, char** argv) {

	PPM ppm;
	PGM pgm;

	_test_FirstProg();

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


	//log
	printf("[%s : %d] done\n", base_name(__FILE__), __LINE__);


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
