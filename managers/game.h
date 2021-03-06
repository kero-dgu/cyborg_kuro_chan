#ifndef __GAME_H__
#define __GAME_H__


#include <GL/freeglut.h>
#include <stdio.h>


// Macros **************************************************
// Game configs
#define APP_TITLE       "サイボーグクロちゃん"
#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define WINDOW_POS_X    200
#define WINDOW_POS_Y    200

// debug
#ifdef DEBUG
// TODO: 恐らく glut が MainLoop で処理を返さないために, LOG の実行時刻が取得できていない
// #define LOG(...) { printf("%s %s(%d): ", __TIME__ , __func__, __LINE__); printf(__VA_ARGS__); printf("\n"); }
#define LOG(...) { printf("%s(%d): ", __func__, __LINE__); printf(__VA_ARGS__); printf("\n"); }
#else
#define LOG(...)
#endif


// Prototype declarations **************************************************
void init_game(void);          // ゲームの初期化
void advance_game_frame(void); // ゲーム画面を更新するための処理
void update_game(void);        // ゲームの更新
void fin_game(void);           // ゲームの終了
void play_game(void);          // ゲーム開始
void measurement_fps(float *); // FPS を計測

// GLUT callbacks
void draw_event(void);                             // 描画処理のコールバック
void keyboard_down_event(unsigned char, int, int); // キーが押された時ののコールバック
void keyboard_up_event(unsigned char, int, int);   // キーが話された時のコールバック
void reshape_event(int, int);                      // ウィンドウサイズ変更のコールバック

// GLUT wrappers
// TODO: 図形の描画
void draw_rect(int, int, int, int);               // 四角形の描画
void draw_triangle(int, int, int, int, int, int); // 三角形の描画
// TODO: png 画像の描画
void draw_graphics(int, int, int, int);           // 画像の描画
void draw_rect(int, int, int, int);               // 四角形を描画
void set_draw_string_color(const char *);         // 描画する文字色
void set_background_color(const char *, float);   // 背景色を設定

// Freeglut wrappers
void draw_string(float, float, const char * string);   // 文字列描画


#endif /* __GAME_H__ */
