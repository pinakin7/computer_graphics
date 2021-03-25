#include <std/c++.h>

using namespace std;

void DDA(int x1,int y1,int x2,int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_inc = dx / (float) steps;
    float y_inc = dy / (float) steps;
    float x = x1;
    float y = y1;
    while(steps--){
        putpixel(x,y,WHITE);
        x += x_inc;
        y += y_inc;
        delay(200);
    }
}

void main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C://TURBOC3//BGI//");
    int x1,x2,y1,y2;
    cout<<" Enter the coordinates (X1,Y1) : ";
    cin>>x1>>y1;
    cout<<" Enter the coordinates (X2,Y2) : ";
    cin>>x2>>y2;
    DDA(x1,y1,x2,y2);
    getch();
}

//
//Advantages :
//
//It is simple and easy to implement algorithm.
//It avoid using multiple operations which have high time complexities.
//It is faster than the direct use of the line equation because it does not use any floating point multiplication and it calculates points on the line.
//
//Disadvantages :
//
//It deals with the rounding off operation and floating point arithmetic so it has high time complexity.
//As it is orientation dependent, so it has poor endpoint accuracy.
//Due to the limited precision in the floating point representation it produces cumulative error.
