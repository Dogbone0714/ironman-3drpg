/* File: RenderMemory.h */

#ifndef __RENDERMEMORY_H__  // �ȧO�����Y�ɪ��w�q�����ӥ[���A�ߺD�O�g���Y�ɳ��|�[�C
#define __RENDERMEMORY_H__  // �R�W��W�h�G�⦸���u+���j�g�ɦW+�@�����u+�j�gH+�⦸���u



#define WIDTH_USER_SET 60  // �b�o��]�m�u���Q�n�����e
#define HEIGHT_USER_SET 30
#define SCREEN_WIDTH (WIDTH_USER_SET + 1)  // �b��r�������A�u����šv���M�L�k�Q�ݨ�A
                                           // �o�e�@��b����A�ҥH�����N�ڭ̳]�w���� + 1
#define SCREEN_HEIGHT (HEIGHT_USER_SET)

char render_memory[SCREEN_HEIGHT][SCREEN_WIDTH];  // char���A�G���}�C�@��ø�s�O����

void init_render_memory();  // �Nrender memory��l�ƥ�



#endif // __RENDERMEMORY_H__