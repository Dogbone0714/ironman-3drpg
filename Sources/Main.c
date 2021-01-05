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

        if(GetAsyncKeyState(87) != 0)  /*W*/ //�e�i  // W�O�_�Q���U
        {
            render_screen(_CLEAN_MODE_);  // �M���¦��e��
            camera_z_pos += cos_y * camera_speed;  // �b�����ਤ�ת����ΤU�A
            camera_x_pos -= sin_y * camera_speed;  // ���u�e�i�ݭn�Ҽ{x, z��V���q
            render_screen(_RENDER_MODE_);  // ø�s
            isFrameUpdated = True;  // �U�@�g���N��s��e���W
        }
        if(GetAsyncKeyState(83) != 0)  /*S*/ //��h // S�O�_�Q���U
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos -= cos_y * camera_speed;
            camera_x_pos += sin_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(65) != 0)  /*A*/ //���� // A�O�_�Q���U
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos -= sin_y * camera_speed;
            camera_x_pos -= cos_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(68) != 0)  /*D*/ //�k�� // D�O�_�Q���U
        {
            render_screen(_CLEAN_MODE_);
            camera_z_pos += sin_y * camera_speed;
            camera_x_pos += cos_y * camera_speed;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(66) != 0)  /*B*/  //�W��  // B�O�_�Q���U
        {
            render_screen(_CLEAN_MODE_);
            camera_y_pos -= 2;  // ����ä��v�T�W�U���ʡA���������v��y��m
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(78) != 0)  /*N*/  //�U��  // N�O�_�Q���U
        {
            render_screen(_CLEAN_MODE_);
            camera_y_pos += 2;
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_RIGHT) != 0 || GetAsyncKeyState(VK_LEFT) != 0)
        {
            render_screen(_CLEAN_MODE_);
            if(GetAsyncKeyState(VK_RIGHT) != 0)  // �uy�b����A�����Y���k�\�ʡA�ѥ��k��V�䱱��
            {
                rot_y -= camera_speed * 0.006;  // 0.006�O�@�ӽվ�L���ѼơA�j�a�i�H�r�u���ƭ�
            }                                   // ������T���ܤj�G�[�j���ƭȡA�Ϥ��h��p
            if(GetAsyncKeyState(VK_LEFT) != 0)
            {
                rot_y += camera_speed * 0.006;
            }
            if(rot_y > M_PI * 2 || rot_y < -(M_PI * 2)) rot_y = 0.0;  // ������360�׻P
            render_screen(_RENDER_MODE_);                             // -360�׮ɡA�k�s
            isFrameUpdated = True;                                    // �T�O�i�L������
        }
        if(GetAsyncKeyState(VK_UP) != 0 || GetAsyncKeyState(VK_DOWN) != 0)
        {
            render_screen(_CLEAN_MODE_);
            if(GetAsyncKeyState(VK_UP) != 0)  // �ux�b����A�����Y�W�U�\�ʡA�ѤW�U��V�䱱��
            {
                rot_x -= camera_speed * 0.006;
            }
            if(GetAsyncKeyState(VK_DOWN) != 0)
            {
                rot_x += camera_speed * 0.006;
            }
            if(rot_x > M_PI / 10) rot_x = M_PI / 10;  // �o��ڳ]�w���W��18�׮ɴN����A
            else if(rot_x < -(M_PI / 10)) rot_x = -(M_PI / 10);  // ���U18�׮ɤ]����C
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
        if(GetAsyncKeyState(VK_ESCAPE) != 0)  // ���UEsc�ɡA�C�������I
        {
            return 0;
        }
        if(GetAsyncKeyState(77) != 0)  /*M*/  // put a cube
        {
            render_screen(_CLEAN_MODE_);
            while(allCubes->next != NULL)  // �N���в���̫�@��
            {
                allCubes = allCubes->next;
            }
            
            allCubes->next = (Cube *)malloc(sizeof(Cube));  // ��malloc�t�m�@���������U�@��
            allCubes = allCubes->next;  // ���в��ʨ�s���
            allCubes->cx = camera_x_pos;  // �H�U�]�m�Ҧ��ݩ�
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
            allCubes = &allCubesHead;  // ���в��ʦ^�Y
            render_screen(_RENDER_MODE_);
            isFrameUpdated = True;
        }
    }
    

    return 0;
}