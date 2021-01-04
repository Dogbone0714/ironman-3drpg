#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

double esd = 0.0;

int projectTo2d_x(double x, double y, double z)
{
    double ax = x;
    double eod = z;
    double result = ax * (esd / eod);
    return round(result);
}

int projectTo2d_y(double x, double y, double z)
{
    double ay = y;
    double eod = z;
    double result = ay * (esd / eod);
    return round(result);
}

int main(int argc, char *argv[])
{
    double x_3d = 0.0;
    double y_3d = 0.0;
    double z_3d = 0.0;

    int bx = 0;
    int by = 0;

    esd = 10.0;

    for(;;)
    {
        printf("輸入3D座標：\n");
        scanf("%lf %lf %lf", &x_3d, &y_3d, &z_3d);

        bx = projectTo2d_x(x_3d, y_3d, z_3d);
        by = projectTo2d_y(x_3d, y_3d, z_3d);

        printf("原3D座標：(%f, %f, %f)\n", x_3d, y_3d, z_3d);
        printf("轉換後2D座標：(%d, %d)\n", bx, by);
    }

    return 0;
}