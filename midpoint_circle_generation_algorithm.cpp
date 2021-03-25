#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

using namespace std;

void eight_way_symmetry(int h,int k,int x,int y){
    putpixel(x+h,y+k,RED);
    putpixel(x+h,-y+k,YELLOW);
    putpixel(-x+h,-y+k,GREEN);
    putpixel(-x+h,y+k,YELLOW);
    putpixel(y+h,x+k,12);
    putpixel(y+h,-x+k,14);
    putpixel(-y+h,-x+k,15);
    putpixel(-y+h,x+k,6);
//    sleep(1);
}

//Midpoint
int main(void){
    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    int h,k,x,y,d,r;
    cout<<" Enter the coordinates of center : ";
    cin>>h>>k;
    cout<<" Enter the radius : ";
    cin>>r;
    x = 0;
    y = r;
    d = 1 - r;
    eight_way_symmetry(h,k,x,y);
    while(x <= y){
        if(d < 0){
            x++;
            d = d + 2*x + 3;
        }
        else{
            x++;
            y--;
            d = d + 2*x - 2*y + 5;
        }
        eight_way_symmetry(h,k,x,y);
    }
    closegraph();
    getch();

}
