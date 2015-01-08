#include "scene.h"
#include "../controllers/config_scene.h"
#include "../controllers/game_scene.h"
#include "../controllers/menu_scene.h"


// Static variables **************************************************
static Scene s_current_scene = MENU_SCENE;   // 現在のシーン


// Scene functions **************************************************
/**
 * シーンの初期化
 */
void init_scene(void)
{
  switch (s_current_scene) {
    case MENU_SCENE:   init_menu_scene();   break;
    case GAME_SCENE:   init_game_scene();   break;
    case CONFIG_SCENE: init_config_scene(); break;
    case NONE_SCENE:                        break;
  }
}

/**
 * シーンの更新
 */
void update_scene(void)
{
  // のシーンが設定されているならシーンの切り替え
  if (g_next_scene != NONE_SCENE && g_next_scene != s_current_scene) {
    fin_scene();    // カレントシーンの終了
    s_current_scene = g_next_scene; // カレントシーンの切り替え
    init_scene();   // カレントシーンの初期化
  }

  switch (s_current_scene) {
    case MENU_SCENE:   update_menu_scene();   break;
    case GAME_SCENE:   update_game_scene();   break;
    case CONFIG_SCENE: update_config_scene(); break;
    case NONE_SCENE:                          break;
  }
}

/**
 * シーンの描画
 */
void draw_scene(void)
{
  switch (s_current_scene) {
    case MENU_SCENE:   draw_menu_scene();   break;
    case GAME_SCENE:   draw_game_scene();   break;
    case CONFIG_SCENE: draw_config_scene(); break;
    case NONE_SCENE:                        break;
  }
}

/**
 * シーンの終了処理
 */
void fin_scene(void)
{
  switch (s_current_scene) {
    case MENU_SCENE:   fin_menu_scene();   break;
    case GAME_SCENE:   fin_game_scene();   break;
    case CONFIG_SCENE: fin_config_scene(); break;
    case NONE_SCENE:                       break;
  }
}
