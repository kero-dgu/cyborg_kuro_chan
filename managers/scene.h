#ifndef __SCENE_H__
#define __SCENE_H__


// Enums **************************************************
typedef enum _Scene {
  MENU_SCENE,
  GAME_SCENE,
  CONFIG_SCENE,
  NONE_SCENE,
} Scene;  // ゲームのシーン


// Global variables **************************************************
Scene g_next_scene;     // 遷移予定の次のシーン


// Prototype declarations **************************************************
void init_scene(void);   // シーンの初期化
void update_scene(void); // シーンの更新
void draw_scene(void);   // シーンの描画
void fin_scene(void);    // シーンの終了


#endif  // __SCENE_H__
