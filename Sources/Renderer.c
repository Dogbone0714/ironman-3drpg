/* File: Renderer.c */

#include"Renderer.h"
#include<stdlib.h>  // 標準函式庫
#include<math.h>  // 計算三角函數、四捨五入等
#include"RenderMemory.h"  // 需要取用render_memory二維陣列，才有辦法更新畫面
#include"GameStatus.h"  // isFrameUpdated的取用需要此標頭檔

void init_renderer()  // 初始化各項變數，其中幾項可以自由調整，目前是我測試起來較為合適的值
{
    camera_x_pos = 0.0;
    camera_y_pos = 0.0;
    camera_z_pos = -150;  //
    camera_speed = 5.0;   // 此三項主要影響視野遠近、相機移動速度，可自由實驗調整
    fov = 120;            //
    x1 = 0.0;
    y1 = 0.0;
    z1 = 0.0;
    x2 = 0.0;
    y2 = 0.0;
    z2 = 0.0;
    rx = 1;  // 初始化為最左上角的像素
    ry = 1;  //
    rot_x = 0.0;
    rot_y = 0.0;
    sin_x = 0.0;
    cos_x = 0.0;
    sin_y = 0.0;
    cos_y = 0.0;
}

void div_zero_adjust(float *n)  // 避免除以零，或是除以太小的數造成結果過大
{                               // 此處以指標傳入，因為需要更動到(*n)值
    if((*n) < 0.5)  // 只要 (*n) 小於0.5都設為0.5
    {
        *n = 0.5;
    }
}

void calc_tri()  // 事先運算三角函數值，避免計算量太大
{
    sin_x = sin(rot_x);  // 須注意角度以弧度計算
    sin_y = sin(rot_y);
    cos_x = cos(rot_x);
    cos_y = cos(rot_y);
}

