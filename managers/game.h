#ifndef __GAME_H__
#define __GAME_H__


#include <stdio.h>


// Macros **************************************************
// TODO: 完成時に消す
#define DEBUG
#define APP_NAME        "サイボーグクロちゃん"
#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_POS_X    200
#define WINDOW_POS_Y    200
// debug
#ifdef DEBUG
#define LOG(...) { printf("%s(%d): ", __func__, __LINE__); printf(__VA_ARGS__); printf("\n"); }
#else
#define LOG(...)
#endif


// Enums **************************************************
typedef enum _Scene {
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
void fin_game(void);            // ゲームの終了
void play_game(void);           // ゲーム開始

// GLUT callbacks
void draw_event(void);                                      // 描画処理のコールバック
void keyboard_down_event(unsigned char key, int x, int y);  // キーが押された時ののコールバック
void keyboard_up_event(unsigned char key, int x, int y);    // キーが話された時のコールバック
void reshape_event(int, int);                               // ウィンドウサイズ変更のコールバック

// Freeglut wrappers
// TODO: glutCreateWindow をラップしてマルチバイト文字が扱えるようにする
void drawString(float, float, void*, const char* string);   // 文字列描画


#endif /* __GAME_H__ */
