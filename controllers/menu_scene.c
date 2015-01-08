#include "menu_scene.h"
#include "../managers/game.h"
#include "../managers/keyboard.h"
#include "../managers/scene.h"
#include <GL/freeglut.h>
#include <string.h>


// Golbal variables **************************************************
extern Scene g_next_scene;


/**
 * メニュー画面の初期化
 */
void init_menu_scene(void)
{
  set_background_color("#000000", 1.0f);
}

/**
 * メニュー画面の更新
 */
void update_menu_scene(void)
{
  if (check_key_state(GLUT_KEY_A) == KEY_PRESSING) {
    LOG("'a' が押され続けています");
  }
  else if (check_key_state(GLUT_KEY_ENTER) == KEY_UP) {
    g_next_scene = GAME_SCENE;
    LOG("ゲームシーンに遷移");
  }
}

/**
 * メニュー画面の描画
 */
void draw_menu_scene(void)
{
  set_draw_string_color("#ff0000");
  draw_string(-0.25f, 0.0f, "<-- Menu Scene -->");
}

/**
 * メニュー画面の終了
 */
void fin_menu_scene(void)
{

}
