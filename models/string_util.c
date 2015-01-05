#include "string_util.h"
#include "math_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>


/**
 * 文字列の文字コードを変換
 * @param   tocode      元々の文字コード
 * @param   fromcode    変換したい文字コード
 * @param   src_str     変換したい文字列
 * @param   p_dest_str  変換した文字列を格納する配列へのポインタ
 * @param   buf_size    変換した文字列を格納する変数のサイズ
 */
void convert_char_code(const char* tocode, const char* fromcode, const char* src_str,
                       char* p_dest_str, size_t buf_size)
{
  iconv_t icd;
  size_t src_len, dest_len;

  icd = iconv_open(tocode, fromcode);
  if (icd == (iconv_t)-1) { perror("iconv open"); }

  src_len  = strlen(src_str);
  dest_len = buf_size - 1;
  memset(p_dest_str, '\0', buf_size);   // 変換した文字列を格納する配列を初期化しておく

  dest_len = iconv(icd, &src_str, &src_len, &p_dest_str, &dest_len);
  if (dest_len == -1) { perror("iconv"); }
  iconv_close(icd);
}

/**
 * カラーコードを16進数の文字列で指定して, red, green, blue の変数にそれぞれの値を格納
 * @param color_code 16進数のからコード
 * @param red        赤度を格納する変数
 * @param green      緑度を格納する変数
 * @param blue       青度を格納する変数
 */
void convert_string_to_hex(const char *color_code, float *red, float *green, float *blue)
{
  char shape_symbol[4] = {0};
  char red_hex_str[8] = {0}, green_hex_str[8] = {0}, blue_hex_str[8] = {0};
  char *endptr;
  int head = 0;

  // TODO: 文字数をチェックして6文字ならそのまま, 3文字なら前の文字を続けるようにする

  strncpy(shape_symbol, color_code, 1);
  if (strcmp(shape_symbol, "#") == 0) { head += 1; }

  strcpy(red_hex_str,   "0x");
  strcpy(green_hex_str, "0x");
  strcpy(blue_hex_str,  "0x");

  strncpy(red_hex_str   + 2, color_code + head,     2);
  strncpy(green_hex_str + 2, color_code + head + 2, 2);
  strncpy(blue_hex_str  + 2, color_code + head + 4, 2);

  *red   = round_float((float)strtol(red_hex_str,   &endptr, 16)/255.0f, 1);
  *green = round_float((float)strtol(green_hex_str, &endptr, 16)/255.0f, 1);
  *blue  = round_float((float)strtol(blue_hex_str,  &endptr, 16)/255.0f, 1);
}
