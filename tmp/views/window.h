#ifndef __WINDOW_H__
#define __WINDOW_H__


#include <GL/glut.h>
#include <stdbool.h>


// Prototype declarations **************************************************
int create_window(const char *, int, int, int, int);   // ウィンドウの生成


// Global variables **************************************************
bool g_should_close_flag;   // ウィンドウを閉じる必要があるかどうか


#endif /* __WINDOW_H__ */
