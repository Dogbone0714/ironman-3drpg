/* File: SystemSetting.c */

#include   <stdio.h>
#include   <windows.h>
#include   "RenderMemory.h"  // �ݭn�Ψ�ø�s�O�����ɮפ����ܼơA�ݧt�A�i��
#include   "SystemSetting.h"

void selfCls(){  // ���M�ſù���z�O�����N���бa��̥��W���A�A�����Ƽg��s�e��

    **System Setting**
    handler = GetStdHandle(STD_OUTPUT_HANDLE);  // ���o�зǿ�X��handle
    xyPoint.X = 0;  // �Ʊ�x, y�y�г����0����m
    xyPoint.Y = 0;
    SetConsoleCursorPosition(handler, xyPoint);  // �N�y�г]�m��Ӧ�m
    cursorInfo.bVisible = FALSE;  // ���г]�����i��
    cursorInfo.dwSize = 1;  // ���Фj�p�Τ���A���]��1
    SetConsoleCursorInfo(handler, &cursorInfo);  // �]�m���и�T
}

void setting_system(){

    char system_command[50] = "";
    char cols_str[8] = "";
    sprintf(cols_str, "%d", SCREEN_WIDTH);
    char lines_str[8] = "";
    sprintf(lines_str, "%d", SCREEN_HEIGHT + 16);  // �h�X�Ӫ�16�C�i�H��ܮy�и�T�B���׸�T����
    strcat(system_command, "mode con:cols=");
    strcat(system_command, cols_str);   //
    strcat(system_command, " lines=");  // �N���O�̫�������r�A�A�e�X��system
    strcat(system_command, lines_str);  //
    system(system_command);  // ��system�N���O�e���@�~�t��
    system("@echo off");  // �����^��
    system("TITLE 3D Game");  // �]�m���D
    SetWindowPos(GetConsoleWindow(),HWND_TOPMOST,500,100,0,0,SWP_NOSIZE);  // �]�w������m
}
