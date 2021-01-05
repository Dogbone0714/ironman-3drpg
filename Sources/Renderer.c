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

    allCubes = &allCubesHead;  // ���Х�����}�Y
    allCubes->next = &newCube;  // �NnewCube�s�W�}�Y
    allCubes = allCubes->next;  // ���в��ʨ�newCube�W
    allCubes->next = NULL;  // newCube���N�U�@������}�]��NULL
    allCubes->cx = 0;       // �H�U���]�w�U���ݩ�
    allCubes->cy = 5;
    allCubes->cz = -150;
    allCubes->left = 50;
    allCubes->right =50;
    allCubes->top = 2;
    allCubes->bottom = 2;
    allCubes->f = 50;
    allCubes->r = 50;
    allCubes = &allCubesHead;  // ���Ц^��}�Y
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

void render_line(char style, int lx1, int ly1, int lz1, int lx2, int ly2, int lz2)
{                                            // �Ѽƨ̧Ǭ��Gstyle-�c���C���I���r��
                                             //     lx1, ly1, lz1-���u�Ĥ@�Ӻ��I��x, y, z
                                             //     lx2, ly2, lz2-���u�ĤG�Ӻ��I��x, y, z

    int rx1 = 0, rx2 = 0, ry1 = 0, ry2 = 0;  // �̫��ഫ�X����դG���y���I�Aø�s��RenderMemory��
    
    /*�N�y���I��h��v����m*/
    x1 = (float)(lx1 - camera_x_pos);  // �N��J���y���I��h�ۤv��v������m�A
    y1 = (float)(ly1 - camera_y_pos);  // �N�O�۹����v�����y��
    z1 = (float)(lz1 - camera_z_pos);
    x2 = (float)(lx2 - camera_x_pos);
    y2 = (float)(ly2 - camera_y_pos);
    z2 = (float)(lz2 - camera_z_pos);

    float temp_x1 = 0.0, temp_y1 = 0.0, temp_x2 = 0.0, temp_y2 = 0.0;
    
    /*¶y�b����A�������аѦ�Day10*/
    temp_x1 = x1;  //����x1�Q�U���o��«��L�A�v�Tz1���B�⵲�G(�]��x1�w�bz1��ȫe�N�Q«��)
    x1 = (z1 * sin_y) + (x1 * cos_y);
    z1 = (z1 * cos_y) - (temp_x1 * sin_y);

    temp_x2 = x2;  //����x2�Q�U���o��«��L�A�v�Tz2���B�⵲�G(�]��x2�w�bz2��ȫe�N�Q«��)
    x2 = (z2 * sin_y) + (x2 * cos_y);
    z2 = (z2 * cos_y) - (temp_x2 * sin_y);
    
    /*¶x�b����A�������аѦ�Day10*/
    /* x1 = x1; */
    temp_y1 = y1;  //����y1�Q�U���o��«��L�A�v�Tz1���B�⵲�G(�]��y1�w�bz1��ȫe�N�Q«��)
    y1 = (y1 * cos_x) - (z1 * sin_x);
    z1 = (temp_y1 * sin_x) + (z1 * cos_x);

    /* x2 = x2; */
    temp_y2 = y2;  //����y2�Q�U���o��«��L�A�v�Tz2���B�⵲�G(�]��y2�w�bz2��ȫe�N�Q«��)
    y2 = (y2 * cos_x) - (z2 * sin_x);
    z2 = (temp_y2 * sin_x) + (z2 * cos_x);
    
    /*�T����v�G���A�������аѦ�Day6*/
    div_zero_adjust(&z1);  // z1�N�|�b�����A�Y�䬰0�A�N�ߥX���`�A�]���N����m����0.5
    rx1 = round(fov*(x1/z1));  // ��v����(�T�� -> �G��)
    ry1 = round(fov*(y1/z1));

    div_zero_adjust(&z2);  // z2�N�|�b�����A�Y�䬰0�A�N�ߥX���`�A�]���N����m����0.5
    rx2 = round(fov*(x2/z2));  // ��v����(�T�� -> �G��)
    ry2 = round(fov*(y2/z2));

    /*DDA�t��k�A�������аѦ�Day8*/
    int dx = rx2 - rx1, dy = ry2 - ry1, steps, k;
    float xinc, yinc, x, y;
    if(abs(dx) > abs(dy)) steps = abs(dx);
    else steps = abs(dy);
    xinc = dx/(float)steps;
    yinc = dy/(float)steps;
    x = rx1;
    y = ry1;
    rx = round(x);
    ry = round(y);
    if((rx + (SCREEN_WIDTH/2) >= 0 &&
        rx + (SCREEN_WIDTH/2) < SCREEN_WIDTH) &&
       (ry + (SCREEN_HEIGHT/2) >= 0 &&
        ry + (SCREEN_HEIGHT/2) < SCREEN_HEIGHT))
    {
        render_memory[ry + (SCREEN_HEIGHT/2)][rx + (SCREEN_WIDTH/2)] = style;
    }
    for(k=0;k<steps;k++)
    {
        x += xinc;
        y += yinc;
        rx = round(x);
        ry = round(y);
        if((rx + (SCREEN_WIDTH/2) >= 0 &&
            rx + (SCREEN_WIDTH/2) < SCREEN_WIDTH) &&
           (ry + (SCREEN_HEIGHT/2) >= 0 &&
            ry + (SCREEN_HEIGHT/2) < SCREEN_HEIGHT))
        {
            render_memory[ry + (SCREEN_HEIGHT/2)][rx + (SCREEN_WIDTH/2)] = style;
        }
    }
    
    isFrameUpdated = True;
}

/*ø�sZ����*/
void render_zplane(char style, int cx, int cy, int cz, int left, int right, int top, int bottom)
{
    render_line(style, cx-left, cy-top, cz, cx+right, cy-top, cz);
    render_line(style, cx+right, cy-top, cz, cx+right, cy+bottom, cz);
    render_line(style, cx-left, cy+bottom, cz, cx+right, cy+bottom, cz);
    render_line(style, cx-left, cy+bottom, cz, cx-left, cy-top, cz);
}

/*ø�sY����*/
void render_yplane(char style, int cx, int cy, int cz, int left, int right, int f, int r)
{
    render_line(style, cx-left, cy, cz+f, cx+right, cy, cz+f);
    render_line(style, cx+right, cy, cz+f, cx+right, cy, cz-r);
    render_line(style, cx-left, cy, cz-r, cx-left, cy, cz+f);
    render_line(style, cx+right, cy, cz-r, cx-left, cy, cz-r);
}

/*ø�sX����*/
void render_xplane(char style, int cx, int cy, int cz, int top, int bottom, int f, int r)
{
    render_line(style, cx, cy-top, cz+f, cx, cy+bottom, cz+f);
    render_line(style, cx, cy+bottom, cz+f, cx, cy+bottom, cz-r);
    render_line(style, cx, cy-top, cz-r, cx, cy-top, cz+f);
    render_line(style, cx, cy+bottom, cz-r, cx, cy-top, cz-r);
}

void render_cube(char style, int cx, int cy, int cz, int left, int right, int top, int bottom, int f, int r)
{
    render_zplane(style, cx, cy, cz+f, left, right, top, bottom);
    render_zplane(style, cx, cy, cz-r, left, right, top, bottom);
    render_yplane(style, cx, cy-top, cz, left, right, f, r);
    render_yplane(style, cx, cy+bottom, cz, left, right, f, r);
    render_xplane(style, cx-left, cy, cz, top, bottom, f, r);
    render_xplane(style, cx+right, cy, cz, top, bottom, f, r);
}

void render_screen(int mode)
{
    char render_style = '#';  // �]�m�n�H���Ӧr��ø�s

    if(mode == _CLEAN_MODE_)  // �C����s�e���ݭn��e�@�������e�M��
    {
        render_style = ' ';
    }
    else if(mode == _RENDER_MODE_)  // ø�s�Ҧ�
    {
        render_style = '#';
    }
    else  /* �w�] */
    {
        render_style = '#';
    }

    calc_tri();  /* �C����s�ù����s�p��@����U�T����ƭ� */

    render_cube(render_style, 0, 5, -150, 50, 50, 2, 2, 50, 50);  // ø�s�@�Ӽe���x

    while(allCubes->next != NULL)  // ����linklist����ݫe��
    {
        render_cube(render_style, allCubes->next->cx, allCubes->next->cy, allCubes->next->cz,
                    allCubes->next->left, allCubes->next->right, allCubes->next->top,
                    allCubes->next->bottom, allCubes->next->f, allCubes->next->r);
        allCubes = allCubes->next;  // ø�s�C�@������A���Ы���U�@��
    }
    allCubes = &allCubesHead;       // ���e������Ц^��}�Y
}
