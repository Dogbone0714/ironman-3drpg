#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

double esd;  // 眼睛到螢幕的距離(Eyes to Screen Distance)，也稱視野距離

int main()
{
    double x_3d = 0.0;  // 原三維座標X分量
    double y_3d = 0.0;  // 原三維座標Y分量
    double z_3d = 0.0;  // 原三維座標Z分量

    int bx = 0;  // 轉換後二維座標的X座標(螢幕上座標必須使用整數，文字的像素只有整數個)
    int by = 0;  // 轉換後二維座標的Y座標(同上)

    return 0;
}