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
  set_background_color(0.0f, 0.0f, 0.0f, 0.0);
}

/**
 * メニュー画面の更新
 */
void update_menu_scene(void)
{
  if (check_key_state(GLUT_KEY_A) == KEY_DOWN) {
    LOG("'a' が押されました");
  }
  else if (check_key_state(GLUT_KEY_ENTER) == KEY_DOWN) {
    g_current_scene = GAME_SCENE;
  }
}

/**
 * メニュー画面の描画
 */
void draw_menu_scene(void)
{
  set_draw_string_color(1.0f, 0.0f, 0.0f);
  draw_string(-0.25f, 0.0f, "<-- Menu Scene -->");
}

/**
 * メニュー画面の終了
 */
void fin_menu_scene(void)
{

}
