#include "math_util.h"
#include <math.h>


/**
 * 浮動小数点を指定された精度で四捨五入を行った数値を返す
 * @param   f_num     四捨五入を行いたい数値
 * @param   precision 小数第何位で四捨五入を行うか
 * @return  float     四捨五入を行った数値
 */
float round_float(float f_num, int precision)
{
  float ret;
  ret = f_num*powf(10.0f, precision);
  ret = (float)(int)(ret + 0.5f);
  return ret*powf(10.0f, -precision);
}
