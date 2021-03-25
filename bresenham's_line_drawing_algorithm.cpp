#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>


//using namespace std;

void bresenham(int x1,int y1,int x2,int y2){
    int m = 2 * (y2 - y1);
    int slope_error = m - (x2 - x1);
    for(int x = x1,y = y1; x <= x2; x++){
        putpixel(x,y,WHITE);
        slope_error += m;
        if(slope_error >= 0){
            y++;
            slope_error -= 2 * (x2 - x1);
        }
        delay(50);
    }

}

void main()
{
    int x1,x2,y1,y2;
    cout<<" Enter the coordinates (X1,Y1) : ";
    cin>>x1>>y1;
    cout<<" Enter the coordinates (X2,Y2) : ";
    cin>>x2>>y2;
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C://TURBOC3//BGI//");
    bresenham(x1,y1,x2,y2);
    closegraph();
    getch();
}
