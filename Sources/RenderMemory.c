/* File: RenderMemory.c */

#include "RenderMemory.h"  



void init_render_memory()
{
    int i = 0, j = 0;

    for(i=0;i<SCREEN_HEIGHT;i++)  // �����j��Nmemory��������W' ' (�ťղ�)
    {
        for(j=0;j<SCREEN_WIDTH;j++)
        {
            if(j == SCREEN_WIDTH - 1)  // ���B�N�O������ݭn�N�e���[�@�A
            {                          // �Y�e�������b�P�@�C���̫�@��A�h�񴫦�('\n')
                render_memory[i][j] = '\n';
            }
            else                       // �Ϥ��N�O�Ů�
            {
                render_memory[i][j] = ' ';
            }
        }
    }
}
