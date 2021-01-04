/* File: SystemSetting.c */

#include   <stdio.h>
#include   <windows.h>
#include   "RenderMemory.h"  // 需要用到繪製記憶體檔案中的變數，需含括進來
#include   "SystemSetting.h"

void selfCls(){  // 此清空螢幕原理是直接將光標帶到最左上角，再直接複寫更新畫面

    **System Setting**
    handler = GetStdHandle(STD_OUTPUT_HANDLE);  // 取得標準輸出的handle
    xyPoint.X = 0;  // 希望x, y座標都能到0的位置
    xyPoint.Y = 0;
    SetConsoleCursorPosition(handler, xyPoint);  // 將座標設置到該位置
    cursorInfo.bVisible = FALSE;  // 光標設為不可見
    cursorInfo.dwSize = 1;  // 光標大小用不到，先設為1
    SetConsoleCursorInfo(handler, &cursorInfo);  // 設置光標資訊
}

void setting_system(){

    char system_command[50] = "";
    char cols_str[8] = "";
    sprintf(cols_str, "%d", SCREEN_WIDTH);
    char lines_str[8] = "";
    sprintf(lines_str, "%d", SCREEN_HEIGHT + 16);  // 多出來的16列可以顯示座標資訊、角度資訊等等
    strcat(system_command, "mode con:cols=");
    strcat(system_command, cols_str);   //
    strcat(system_command, " lines=");  // 將指令們拼接成文字，再送出給system
    strcat(system_command, lines_str);  //
    system(system_command);  // 由system將指令送給作業系統
    system("@echo off");  // 關閉回顯
    system("TITLE 3D Game");  // 設置標題
    SetWindowPos(GetConsoleWindow(),HWND_TOPMOST,500,100,0,0,SWP_NOSIZE);  // 設定視窗位置
}
