#include <windows.h>

int main()
{
    for(;;)
    {
        if(GetAsyncKeyState(VK_SPACE) != 0)  //如果空白鍵的狀態不是0(被按下)
        {
            printf("space key was clicked!\n");  //輸出「空白鍵被按下」的字
        }
        Sleep(1000);  //休息1秒
    }
    
    return 0;
}