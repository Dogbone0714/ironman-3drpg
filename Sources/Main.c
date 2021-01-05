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
    initGameStatus();  // ��l�ƹC�����A(�e���O�_��s��l�Ƭ�True)
    init_renderer();

    int i = 0, j = 0;  // �]�m�n��for�j��ϥΪ��p�ƾ�

    for(;;)  /* �D�n���L�a�j��A�C�`���@���@�Ӷg�� */
    {
        if(isFrameUpdated)  // �Y�W�Ӷg����s�FRenderer�����ܼơA
        {                   // �hisFrameUpdated�w�Q�]��True�A���g���N�M�ŭ�e���åH�s�ܼƭ�ø
            selfCls();  // ��в��쥪�W���A�ǳ��л\�µe��
            for(i=0;i<SCREEN_HEIGHT;i++)
            {
                for(j=0;j<SCREEN_WIDTH;j++)
                {
                    printf("%c", render_memory[i][j]);  // �L�Xø�s�O���餤���e��
                }
            }

            // �H�U������Debug�ΡA�i�ݥX�U���ܼ��ܤ�
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

            isFrameUpdated = False;  // �N�W�@�P���Q�]��True��isFrameUpdated�]�^False
        }
    }
    
    return 0;
}