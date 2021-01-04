/* File: Renderer.c */

#include"Renderer.h"
#include<stdlib.h>  // �зǨ禡�w
#include<math.h>  // �p��T����ơB�|�ˤ��J��
#include"RenderMemory.h"  // �ݭn����render_memory�G���}�C�A�~����k��s�e��
#include"GameStatus.h"  // isFrameUpdated�����λݭn�����Y��

void init_renderer()  // ��l�ƦU���ܼơA�䤤�X���i�H�ۥѽվ�A�ثe�O�ڴ��հ_�Ӹ����X�A����
{
    camera_x_pos = 0.0;
    camera_y_pos = 0.0;
    camera_z_pos = -150;  //
    camera_speed = 5.0;   // ���T���D�n�v�T��������B�۾����ʳt�סA�i�ۥѹ���վ�
    fov = 120;            //
    x1 = 0.0;
    y1 = 0.0;
    z1 = 0.0;
    x2 = 0.0;
    y2 = 0.0;
    z2 = 0.0;
    rx = 1;  // ��l�Ƭ��̥��W��������
    ry = 1;  //
    rot_x = 0.0;
    rot_y = 0.0;
    sin_x = 0.0;
    cos_x = 0.0;
    sin_y = 0.0;
    cos_y = 0.0;
}

void div_zero_adjust(float *n)  // �קK���H�s�A�άO���H�Ӥp���Ƴy�����G�L�j
{                               // ���B�H���жǤJ�A�]���ݭn��ʨ�(*n)��
    if((*n) < 0.5)  // �u�n (*n) �p��0.5���]��0.5
    {
        *n = 0.5;
    }
}

void calc_tri()  // �ƥ��B��T����ƭȡA�קK�p��q�Ӥj
{
    sin_x = sin(rot_x);  // ���`�N���ץH���׭p��
    sin_y = sin(rot_y);
    cos_x = cos(rot_x);
    cos_y = cos(rot_y);
}

