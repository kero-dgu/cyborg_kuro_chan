#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__


#include "../models/keycode.h"


// Enums **************************************************
typedef enum _KeyState {
  KEY_NORMAL = 0,  // 通常状態
  KEY_DOWN   = 1,  // キーを押した
  KEY_UP     = 2,  // キーを離した
} KeyState;


// Prototype declarations **************************************************
void update_keyboard(KeyState, unsigned char, int, int);  // キー入力状態の更新
KeyState check_key_state(unsigned char);                  // 指定したキーの入力状態を返す


#endif /* __KEYBOARD_H__ */
