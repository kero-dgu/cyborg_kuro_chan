#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__


#include <stddef.h>


void convert_char_code(const char *, const char *, const char *, char *, size_t);   // 文字列の文字コードを変換
void convert_string_to_hex(const char *, float *, float *, float *);                // 16進数のカラーコード(文字列)を float 型の 16進数に変換


#endif /* __STRING_UTIL_H__ */
