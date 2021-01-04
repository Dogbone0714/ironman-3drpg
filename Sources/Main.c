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
    initGameStatus();  // 初始化遊戲狀態(畫面是否更新初始化為True)

    
    return 0;
}