#include "string_util.h"
#include <stdio.h>
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


float convert_string_to_hex(const char *color_code, float *red, float *green, float *blue)
{
  char shape_symbol[4] = {0};

  strncpy(shape_symbol, color_code, 1);
  if (str)
}
