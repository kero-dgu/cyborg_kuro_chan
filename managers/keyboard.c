#include "keyboard.h"
#include "../models/keycode.h"


// Static global variable **************************************************
static int s_keys[256];


/**
 * キー入力状態の更新
 * @param   key_state   キーの状態
 * @param   keycode     入力されたキー
 * @param   x           マウスの X 座標
 * @param   y           マウスの Y 座標
 */
void update_keyboard(KeyState key_state, unsigned char keycode, int x, int y)
{
  int i;
  for (i = 0; i < 256; ++i) {
    if (i == keycode) { s_keys[i] = key_state;  }
    else              { s_keys[i] = KEY_NORMAL; }
  }
}


/**
 * 指定したキーの入力状態を返す
 * @param   keycode   入力されたキー
 * @return  KeyState  キーの入力状態
 */
KeyState check_key_state(unsigned char keycode)
{
  return s_keys[keycode];
}
