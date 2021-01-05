/* File: Main.c */

#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
#include <math.h>  
#include "RenderMemory.h"
#include "SystemSetting.h"
#include "GameStatus.h"
#include "Renderer.h"  

#define M_PI acos(-1.0)

int main(int argc, char *argv[])
{
    init_render_memory();
    setting_system();
    initGameStatus();  // 初始化遊戲狀態(畫面是否更新初始化為True)
    init_renderer();

    int i = 0, j = 0;  // 設置好給for迴圈使用的計數器

    for(;;)  /* 主要的無窮迴圈，每循環一次一個週期 */
    {
        if(isFrameUpdated)  // 若上個週期更新了Renderer中的變數，
        {                   // 則isFrameUpdated已被設為True，此週期將清空原畫面並以新變數重繪
            selfCls();  // 游標移到左上角，準備覆蓋舊畫面
            for(i=0;i<SCREEN_HEIGHT;i++)
            {
                for(j=0;j<SCREEN_WIDTH;j++)
                {
                    printf("%c", render_memory[i][j]);  // 印出繪製記憶體中的畫面
                }
            }

            // 以下部分為Debug用，可看出各項變數變化
            printf("Camera x: %f\n", camera_x_pos);
            printf("Camera y: %f\n", camera_y_pos);
            printf("Camera z: %f\n", camera_z_pos);
            printf("sin x: %f\n", sin_x);
            printf("sin y: %f\n", sin_y);
            printf("cos x: %f\n", cos_x);
            printf("cos y: %f\n", cos_y);
            printf("rotate x: %f\n", rot_x);
            printf("rotate y: %f\n", rot_y);
            printf("FOV: %f\n", fov);

            isFrameUpdated = False;  // 將上一周期被設為True的isFrameUpdated設回False
        }
    }
    
    return 0;
}