#include "game_scene.h"
#include "../managers/game.h"
#include "../managers/keyboard.h"


/**
 * ゲームシーンの初期化
 */
void init_game_scene(void)
{
  set_background_color(0.0f, 0.0f, 0.0f, 0.0);
}

/**
 * ゲームシーンの更新
 */
void update_game_scene(void)
{
  if (check_key_state(GLUT_KEY_ENTER) == KEY_DOWN) {
    g_current_scene = MENU_SCENE;
  }
}

/**
 * ゲームシーンの描画
 */
void draw_game_scene(void)
{
  set_draw_string_color(1.0f, 0.0f, 0.0f);
  draw_string(-0.25f, 0.0f, "<-- Game Scene -->");
}

/**
 * ゲームシーンの終了
 */
void fin_game_scene(void)
{

}
