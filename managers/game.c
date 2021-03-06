#include "game.h"
#include "keyboard.h"
#include "scene.h"
#include "../controllers/menu_scene.h"
#include "../controllers/game_scene.h"
#include "../controllers/config_scene.h"
#include "../models/string_util.h"
#include <GL/freeglut.h>
#include <stdarg.h>
#include <stdlib.h>


// Global variables **************************************************
extern Scene g_next_scene;


// Static variables **************************************************
static int s_frame  = 0;        // ゲーム進行ためのフレームキー
static float s_fps  = 0;        // FPS


// Game functions **************************************************
/**
 * ゲームの初期化
 */
void init_game(void)
{
  glutDisplayFunc(draw_event);            // 画面を更新する内容
  glutKeyboardFunc(keyboard_down_event);  // キーボードを押した時
  glutKeyboardUpFunc(keyboard_up_event);  // キーボードを離した時
  glutReshapeFunc(reshape_event);         // ウィンドウサイズ変更(※ウィンドウのサイズを変更できなくする)

  g_next_scene = NONE_SCENE;
  init_scene();
}


/**
 * ゲーム画面を更新するための処理
 */
void advance_game_frame(void)
{
  static int s_prev_time = 0;   // 前回画面が更新された時の時刻を記録
  int current_time = glutGet(GLUT_ELAPSED_TIME);  // glutInit() 後の経過時間をミリ秒で取得
  // 15ミリ秒ごとにアニメーションを進行させて画面を更新
  if (current_time - 15 > s_prev_time) {
    ++s_frame;                    // フレームを更新
    update_game();                // ゲームの更新処理
    glutPostRedisplay();          // 画面更新の実行
    s_prev_time = current_time;   // 画面更新時間を更新
  }
}

/**
 * ゲームの更新処理
 */
void update_game(void)
{
  measurement_fps(&s_fps);  // FPS を計測

  update_scene();   // シーンの更新

  if (check_key_state(GLUT_KEY_ESC) == KEY_UP) {
    LOG("Ended game");
    exit(0);
  }

  reset_key_state();  // キー状態をリセット
}

/**
 * ゲームの終了処理
 */
void fin_game(void)
{
  fin_scene();
}

/**
 * ゲーム開始
 */
void play_game(void)
{
  init_game();
  glutIdleFunc(advance_game_frame);   // 画面を更新
  // TODO: 必要？
  // glutGet(GLUT_ELAPSED_TIME);
  glutMainLoop();                     // ループ開始
}

/**
 * FPS を計測(update_game() 内で実行)
 * @param  fps   FPS をセットする
 */
void measurement_fps(float *fps)
{
  static int s_prev_time  = 0;  // 前回の FPS 計測時間
  int current_time    = glutGet(GLUT_ELAPSED_TIME);
  int elapsed_time    = current_time - s_prev_time;   // 前回の FPS 計測からの経過時間

  if (elapsed_time > 1000) {
    *fps = (s_frame*1000.0f)/elapsed_time;
    s_prev_time = current_time;   // FPS 計測時間を更新
    s_frame     = 0;              // フレームをクリア
  }
}


// GLUT callbacks **************************************************
/**
 * ゲームの描画処理
 */
void draw_event(void)
{
  glClear(GL_COLOR_BUFFER_BIT);     // glClearColor の色を反映させる

  // debug
  // FPS を表示
  char fps_str[16];
  sprintf(fps_str, "FPS:%.2f", s_fps);

  draw_string(-0.9f, 0.9f, fps_str);
  //////////////////////////////////////////////////

  draw_scene();

  glutSwapBuffers();                // 実行されていない OpenGL の処理を強制的に実行
}

/**
 * キーボードを押した時のコールバック
 */
void keyboard_down_event(unsigned char key, int pos_x, int pos_y)
{
  update_keyboard(KEY_DOWN, key, pos_x, pos_y);
}

/**
 * キーボードを離した時のコールバック
 */
void keyboard_up_event(unsigned char key, int pos_x, int pos_y)
{
  update_keyboard(KEY_UP, key, pos_x, pos_y);
}

/**
 * ウィンドウサイズ変更のコールバック
 */
void reshape_event(int width, int height)
{
  glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}


// GLUT wrappers **************************************************
/**
 * 四角形を描画
 * @param   x
 * @param   y
 * @param   width
 * @param   height
 */
void draw_rect(int x, int y, int width, int height)
{
  glBegin(GL_QUADS);
  glVertex2d(-0.7, 0.5);
  glVertex2d(-0.7, 0.7);
  glVertex2d(-0.5, 0.7);
  glVertex2d(-0.5, 0.5);
  glEnd();
}

/**
 * glColor3f を描画する文字色を16進数で設定
 * @param   color_code    カラーコード
 */
void set_draw_string_color(const char *color_code)
{
  float red, green, blue;
  convert_string_to_hex(color_code, &red, &green, &blue);
  glColor3f(red, green, blue);
}

/**
 * glClearColor をラップして背景色を16進数で設定
 * @param   color_code    カラーコード
 * @param   alpha         透明度
 */
void set_background_color(const char *color_code, float alpha)
{
  float red, green, blue;
  convert_string_to_hex(color_code, &red, &green, &blue);
  glClearColor(red, green, blue, alpha);
}


// Freeglut wrappers **************************************************
/**
 * 文字列を描画
 * @param x      中心座標から X 座標にどれだけずらすか
 * @param y      中心座標から Y 座標にどれだけずらすか
 * @param string 表示したい文字列
 */
void draw_string(float x, float y, const char *string)
{
  void* font = GLUT_BITMAP_HELVETICA_18;
  glRasterPos2f(x, y);
  glutBitmapString(font, (const unsigned char *)string);
}
