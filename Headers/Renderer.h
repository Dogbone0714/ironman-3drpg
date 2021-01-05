/* File: Renderer.h */

#ifndef __RENDERER_H__
#define __RENDERER_H__

#define _CLEAN_MODE_ 0  // 底下render_screen的參數所需，事先定義好
#define _RENDER_MODE_ 1

typedef struct cube  // 定義方塊
{
    struct cube *next;  // 指向下一塊方塊
    char style;  // 以下屬性是render_cube函數所需參數，
    int cx;      // 同時也是繪製方塊所需的資料。
    int cy;      // 我們可以在玩家按下"m"的時候將方塊資訊加入到linklist中，
    int cz;      // 此方塊就正式「加入」這個世界，
    int left;    // 因為往後的每次render_screen都會將linklist中所有方塊繪製出來。
    int right;
    int top;
    int bottom;
    int f;
    int r;
}Cube;

Cube allCubesHead;  // linklist的頭，標的物
Cube *allCubes;     // Cube指標，用來依序指向每一塊方塊
Cube newCube;       // 遊戲開始時預設在世界中的方塊，也就是類似以前的「大平台」

float camera_x_pos, camera_y_pos, camera_z_pos;  // 攝影機(大家的螢幕)位置
float camera_speed;  // 相機移動速度，決定按下同樣按鍵時間攝影機移動快慢
float fov;  // 視野，等同於前幾天所說的esd(眼睛到螢幕距離)
float x1, y1, z1, x2, y2, z2;  // 畫直線時用來暫存兩端點的變數
double rot_x, rot_y;  // 沿x, y軸轉動的角度
double sin_x, cos_x, sin_y, cos_y;  // 算好後的三角函數放這裡
int rx, ry;  // 最後輸出到螢幕上的二維座標

void init_renderer();  // 初始化以上所有變數
void div_zero_adjust(float *n);  // 遇到z = 0的特殊情況時，將z調整為0.5避免程式出錯

void render_line(char style, int lx1, int ly1, int lz1, int lx2, int ly2, int lz2);
// 畫線的函數，所有圖形繪製中樞

void render_zplane(char style, int cx, int cy, int cz, int left, int right, int top, int bottom);
void render_yplane(char style, int cx, int cy, int cz, int left, int right, int f, int r);
void render_xplane(char style, int cx, int cy, int cz, int top, int bottom, int f, int r);
// 畫平面的函數，由多組render_line組合而成

void render_cube(char style, int cx, int cy, int cz, int left, int right, int top, int bottom, int f, int r);
// 畫方塊，由畫平面的組合而成

void render_screen(int mode);
// 繪製出一幀內所有存在的圖形

void calc_tri();
// 事先計算三角函數值(較費時)

#endif // __RENDERER_H__