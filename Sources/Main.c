/* File: Main.c */

#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
#include <math.h>  
#include "RenderMemory.h"
#include "SystemSetting.h"
#include "GameStatus.h"

int main(int argc, char *argv[])
{
    init_render_memory();
    setting_system();
    initGameStatus();  // ��l�ƹC�����A(�e���O�_��s��l�Ƭ�True)

    
    return 0;
}