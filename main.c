#include <GL/glut.h>
#include "managers/game.h"


// Prototype declaration **************************************************
static void init_window(void);   // ウィンドウの初期化


// TODO: _WIN32 が宣言されているなら, iconv を使って UTF-8 を SHIFT-JIS に変換した文字列をタイトルに設定する


// Main **************************************************
int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  init_window();
  glutCreateWindow();
  play_game();
  return 0;
}


/**
 * ウィンドウの初期化
 */
void init_window()
{
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}
