#include "menu_scene.h"
#include "../managers/game.h"
#include "../managers/keyboard.h"
#include <GL/freeglut.h>
#include <string.h>


// Golbal variables **************************************************
extern Scene g_current_scene;


/**
 * メニュー画面の初期化
 */
void init_menu_scene(void)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0);
}

/**
 * メニュー画面の更新
 */
void update_menu_scene(void)
{
  if (check_key_state(GLUT_KEY_A) == KEY_DOWN) {
    LOG("'a' が押されました");
  }
}

/**
 * メニュー画面の描画
 */
void draw_menu_scene(void)
{
  glColor3f(1.0f, 0.0f, 0.0f);
  drawString(-0.25f, 0.0f, GLUT_BITMAP_HELVETICA_18, "<-- Game Start -->");
}

/**
 * メニュー画面の終了
 */
void fin_menu_scene(void)
{

}
