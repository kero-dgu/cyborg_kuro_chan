#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__


// Enums **************************************************
typedef enum {
  MENU_SCENE,
  GAME_SCENE,
  CONFIG_SCENE,
} Scene;  // ゲームのシーン


// Global variables **************************************************
Scene g_current_scene;  // カレントシーン


// Prototype declarations **************************************************
void init_game(void);           // ゲームの初期化
void advance_game_frame(void);  // ゲーム画面を更新するための処理
void update_game(void);         // ゲームの更新
void draw_game(void);           // ゲームの描画
void fin_game(void);            // ゲームの終了
void play_game(void);           // ゲーム開始

// GLUT をラップ
void drawString(float, float, void*, const char* string);   // 文字列描画


#endif /* __GAME_MANAGER_H__ */
