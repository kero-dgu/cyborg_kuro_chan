#include "window.h"


// Functions **************************************************
/**
 * ウィンドウの作成
 * @param   window_title  ウィンドウのタイトル
 * @param   width         ウィンドウの横幅
 * @param   height        ウィンドウの高さ
 * @param   pos_x         ウィンドウを表示させたい X 座標
 * @param   pos_y         ウィンドウを表示させたい Y 座標
 * @return  int           作成したウィンドウの ID
 */
int create_window(const char * window_title, int width, int height, int pos_x, int pos_y)
{
  glutInitWindowSize(width, height);
  glutInitWindowPosition(pos_x, pos_y);
  int window_id = glutCreateWindow(window_title);
  return window_id;
}
