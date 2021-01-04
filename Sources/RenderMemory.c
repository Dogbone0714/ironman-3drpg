/* File: RenderMemory.c */

#include "RenderMemory.h"  



void init_render_memory()
{
    int i = 0, j = 0;

    for(i=0;i<SCREEN_HEIGHT;i++)  // 蛮癹伴盢memoryず场恶' ' (フ才)
    {
        for(j=0;j<SCREEN_WIDTH;j++)
        {
            if(j == SCREEN_WIDTH - 1)  // 矪碞琌ぐ或惠璶盢糴
            {                          // 璝糴场だ程玥恶传︽('\n')
                render_memory[i][j] = '\n';
            }
            else                       // はぇ碞琌
            {
                render_memory[i][j] = ' ';
            }
        }
    }
}
