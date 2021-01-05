/* File: Renderer.h */

#ifndef __RENDERER_H__
#define __RENDERER_H__

#define _CLEAN_MODE_ 0  // ���Urender_screen���ѼƩһݡA�ƥ��w�q�n
#define _RENDER_MODE_ 1

typedef struct cube  // �w�q���
{
    struct cube *next;  // ���V�U�@�����
    char style;  // �H�U�ݩʬOrender_cube��ƩһݰѼơA
    int cx;      // �P�ɤ]�Oø�s����һݪ���ơC
    int cy;      // �ڭ̥i�H�b���a���U"m"���ɭԱN�����T�[�J��linklist���A
    int cz;      // ������N�����u�[�J�v�o�ӥ@�ɡA
    int left;    // �]�����᪺�C��render_screen���|�Nlinklist���Ҧ����ø�s�X�ӡC
    int right;
    int top;
    int bottom;
    int f;
    int r;
}Cube;

Cube allCubesHead;  // linklist���Y�A�Ъ���
Cube *allCubes;     // Cube���СA�ΨӨ̧ǫ��V�C�@�����
Cube newCube;       // �C���}�l�ɹw�]�b�@�ɤ�������A�]�N�O�����H�e���u�j���x�v

float camera_x_pos, camera_y_pos, camera_z_pos;  // ��v��(�j�a���ù�)��m
float camera_speed;  // �۾����ʳt�סA�M�w���U�P�˫���ɶ���v�����ʧֺC
float fov;  // �����A���P��e�X�ѩһ���esd(������ù��Z��)
float x1, y1, z1, x2, y2, z2;  // �e���u�ɥΨӼȦs����I���ܼ�
double rot_x, rot_y;  // �ux, y�b��ʪ�����
double sin_x, cos_x, sin_y, cos_y;  // ��n�᪺�T����Ʃ�o��
int rx, ry;  // �̫��X��ù��W���G���y��

void init_renderer();  // ��l�ƥH�W�Ҧ��ܼ�
void div_zero_adjust(float *n);  // �J��z = 0���S���p�ɡA�Nz�վ㬰0.5�קK�{���X��

void render_line(char style, int lx1, int ly1, int lz1, int lx2, int ly2, int lz2);
// �e�u����ơA�Ҧ��ϧ�ø�s����

void render_zplane(char style, int cx, int cy, int cz, int left, int right, int top, int bottom);
void render_yplane(char style, int cx, int cy, int cz, int left, int right, int f, int r);
void render_xplane(char style, int cx, int cy, int cz, int top, int bottom, int f, int r);
// �e��������ơA�Ѧh��render_line�զX�Ӧ�

void render_cube(char style, int cx, int cy, int cz, int left, int right, int top, int bottom, int f, int r);
// �e����A�ѵe�������զX�Ӧ�

void render_screen(int mode);
// ø�s�X�@�V���Ҧ��s�b���ϧ�

void calc_tri();
// �ƥ��p��T����ƭ�(���O��)

#endif // __RENDERER_H__