#include "game_scene.h"
#include "../managers/game.h"
#include "../managers/keyboard.h"
#include "../managers/scene.h"


/**
 * ゲームシーンの初期化
 */
void init_game_scene(void)
{
  set_background_color("#000000", 1.0f);
}

/**
 * ゲームシーンの更新
 */
void update_game_scene(void)
{
  if (check_key_state(GLUT_KEY_ENTER) == KEY_UP) {
    g_next_scene = MENU_SCENE;
    LOG("メニューシーンに遷移");
  }
}

/**
 * ゲームシーンの描画
 */
void draw_game_scene(void)
{
  set_draw_string_color("#0000ff");
  draw_rect(100, 100, 300, 200);
}

/**
 * ゲームシーンの終了
 */
void fin_game_scene(void)
{

}
