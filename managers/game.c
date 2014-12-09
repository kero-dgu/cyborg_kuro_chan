#include <GL/freeglut.h>
#include <stdarg.h>
#include <stdlib.h>

#include "game.h"
#include "keyboard.h"
#include "../controllers/menu_scene.h"
#include "../controllers/game_scene.h"
#include "../controllers/config_scene.h"


// Static variables **************************************************
static int s_frame = -180;  // ゲーム新港ためのフレームキー


// Game functions **************************************************
/**
 * ゲームの初期化
 */
void init_game(void)
{
  g_current_scene = MENU_SCENE;

  init_menu_scene();
  init_game_scene();
  init_config_scene();
  glutDisplayFunc(draw_event);      // 画面を更新する内容
  glutKeyboardFunc(keyboard_down_event);  // キーボードを押した時
  glutKeyboardUpFunc(keyboard_up_event);  // キーボードを離した時
  glutReshapeFunc(reshape_event);   // ウィンドウサイズ変更(※ウィンドウのサイズを変更できなくする)
}

/**
 * ゲーム画面を更新するための処理
 */
void advance_game_frame(void)
{
  static GLuint s_past_gl_time = 0;   // 前回画面が更新された時の時刻を記録
  GLuint now_gl_tike = 0;             // 今回関数実行時の時刻を記憶

  // TODO: 以下の処理を見直し
  now_gl_tike = glutGet(GLUT_ELAPSED_TIME);   // glutInit() 後の経過時間をミリ秒で取得
  if (now_gl_tike - 16 > s_past_gl_time) {    // 60fps を上回る状態を維持するため、16ミリ秒ごとにアニメーションを新港させ画面を更新する
    ++s_frame;                    // フレーム番号を進める
    update_game();                // ゲームの更新処理
    glutPostRedisplay();          // 画面更新の実行
    s_past_gl_time = now_gl_tike; // 画面更新時間を更新
  }
}

/**
 * ゲームの更新処理
 */
void update_game(void)
{
  // TODO: 数値の変更など
  switch (g_current_scene) {
    // TODO: 起動画面の追加
    case MENU_SCENE:    update_menu_scene();    break;
    case GAME_SCENE:    update_game_scene();    break;
    case CONFIG_SCENE:  update_config_scene();  break;
  }

  if (check_key_state(GLUT_KEY_ESC) == KEY_UP) {
    LOG("Ended game");
    fin_game();
    exit(0);
  }
}

/**
 * ゲームの終了処理
 */
void fin_game(void)
{
  fin_menu_scene();
  fin_game_scene();
  fin_config_scene();
}

/**
 * ゲーム開始
 */
void play_game(void)
{
  init_game();
  glutIdleFunc(advance_game_frame);  // 画面を更新
  // TODO: 必要？
  glutGet(GLUT_ELAPSED_TIME);
  // TODO: ゲームの終了処理
  glutMainLoop();             // ループ開始
}


// GLUT callbacks **************************************************
/**
 * ゲームの描画処理
 */
void draw_event(void)
{
  glClear(GL_COLOR_BUFFER_BIT);     // glClearColor の色を反映させる
  switch (g_current_scene) {
    // TODO: 起動画面の追加
    case MENU_SCENE:    draw_menu_scene();    break;
    case GAME_SCENE:    draw_game_scene();   break;
    case CONFIG_SCENE:  draw_config_scene();  break;
  }
  glutSwapBuffers();                      // 実行されていない OpenGL の処理を強制的に実行
}

/**
 * キーボードを押した時のコールバック
 */
void keyboard_down_event(unsigned char key, int x, int y)
{
  update_keyboard(KEY_DOWN, key, x, y);
}

/**
 * キーボードを離した時のコールバック
 */
void keyboard_up_event(unsigned char key, int x, int y)
{
  update_keyboard(KEY_UP, key, x, y);
}

/**
 * ウィンドウサイズ変更のコールバック
 */
void reshape_event(int width, int height)
{
  glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}


// Freeglut wrappers **************************************************
void drawString(float x, float y, void* font, const char* string)
{
  glRasterPos2f(x, y);
  glutBitmapString(font, (const unsigned char*)string);
}
