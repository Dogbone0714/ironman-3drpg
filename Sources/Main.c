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

        if(GetAsyncKeyState(87) != 0)  /*W*/ //前進  // W是否被按下
        {
            render_screen(_CLEAN_MODE_);  // 清空舊有畫面
            camera_z_pos += cos_y * camera_speed;  // 在有旋轉角度的情形下，
            camera_x_pos -= sin_y * camera_speed;  // 直線前進需要考慮x, z方向分量
            render_screen(_RENDER_MODE_);  // 繪製
            isFrameUpdated = True;  // 下一週期將更新到畫面上
        }
        if(GetAsyncKeyState(83) != 0)  /*S*/ //後退 // S是否被按下
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos -= cos_y * camera_speed;
            camera_x_pos += sin_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(65) != 0)  /*A*/ //左移 // A是否被按下
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos -= sin_y * camera_speed;
            camera_x_pos -= cos_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(68) != 0)  /*D*/ //右移 // D是否被按下
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos += sin_y * camera_speed;
            camera_x_pos += cos_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(66) != 0)  /*B*/  //上升  // B是否被按下
        {
            render_screen(_CLEAN_MODE_);
            camera_y_pos -= 2;  // 旋轉並不影響上下移動，直接更改攝影機y位置
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(78) != 0)  /*N*/  //下降  // N是否被按下
        {
            render_screen(_CLEAN_MODE_);
            camera_y_pos += 2;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_RIGHT) != 0 || GetAsyncKeyState(VK_LEFT) != 0)
        {
            render_screen(_CLEAN_MODE_);
            if(GetAsyncKeyState(VK_RIGHT) != 0)  // 沿y軸旋轉，類似頭左右擺動，由左右方向鍵控制
            {
                rot_y -= camera_speed * 0.006;  // 0.006是一個調整過的參數，大家可以斟酌此數值
            }                                   // 讓旋轉幅度變大：加大此數值，反之則減小
            if(GetAsyncKeyState(VK_LEFT) != 0)
            {
                rot_y += camera_speed * 0.006;
            }
            if(rot_y > M_PI * 2 || rot_y < -(M_PI * 2)) rot_y = 0.0;  // 當旋轉到360度與
            render_screen(_RENDER_MODE_);                             // -360度時，歸零
            isFrameUpdated = True;                                    // 確保可無限旋轉
        }
        if(GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(VK_DOWN) != 0)
        {
            render_screen(_CLEAN_MODE_);
            if(GetAsyncKeyState(VK_UP) != 0)  // 沿x軸旋轉，類似頭上下擺動，由上下方向鍵控制
            {
                rot_x -= camera_speed * 0.006;
            }
            if(GetAsyncKeyState(VK_DOWN) != 0)
            {
                rot_x += camera_speed * 0.006;
            }
            if(rot_x > M_PI / 10) rot_x = M_PI / 10;  // 這邊我設定成上仰18度時就停止，
            else if(rot_x < -(M_PI / 10)) rot_x = -(M_PI / 10);  // 往下18度時也停止。
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_ESCAPE) != 0)  // 按下Esc時，遊戲結束！
        {
            return 0;
        }
        if(GetAsyncKeyState(77) != 0)  /*M*/  // put a cube
        {
            render_screen(_CLEAN_MODE_);
            while(allCubes->next != NULL)  // 將指標移到最後一塊
            {
                allCubes = allCubes->next;
            }
            
            allCubes->next = (Cube *)malloc(sizeof(Cube));  // 用malloc配置一塊方塊接到下一塊
            allCubes = allCubes->next;  // 指標移動到新方塊
            allCubes->cx = camera_x_pos;  // 以下設置所有屬性
            allCubes->cy = camera_y_pos;
            allCubes->cz = camera_z_pos;
            allCubes->style = '#';
            allCubes->left = 2;
            allCubes->right = 2;
            allCubes->top = 2;
            allCubes->bottom = 2;
            allCubes->f = 2;
            allCubes->r = 2;
            allCubes->next = NULL;
            allCubes = &allCubesHead;  // 指標移動回頭
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
    }
    

    return 0;
}