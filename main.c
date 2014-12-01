#include <GL/glut.h>
#include "managers/game.h"


// Macros **************************************************
// TODO: 日本語にすると文字化けしてしまう, Shift-JIS なら文字化けしないが UNIX 系でそのままのコードで使えない
#define DEBUG   // TODO: 完成時に消す
#define APP_NAME        "CyborgKuroChan"
#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_POS_X    200
#define WINDOW_POS_Y    200


// Prototype declaration **************************************************
static void init_window(void);   // ウィンドウの初期化


// Main **************************************************
int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  init_window();
  glutCreateWindow(APP_NAME);
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
  // TODO: ウィンドウサイズの固定処理, ウィンドウサイズが変更されるとレイアウトが崩れる可能性あり
}
