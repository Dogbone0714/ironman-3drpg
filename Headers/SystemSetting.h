/* File: SystemSetting.h */

#ifndef __SYSTEMSETTING_H__
#define __SYSTEMSETTING_H__

HANDLE handler;  // ����������ܼơA����������������
COORD xyPoint;  // Windows�Ϊ�x, y�y�Ы��A
CONSOLE_CURSOR_INFO cursorInfo;  // �������Ъ���T�c�������c

void selfCls();  // �ۦ漶�g���M�ſù�
void setting_system();  // ���cmd�������U�س]�w

#endif // __SYSTEMSETTING_H__