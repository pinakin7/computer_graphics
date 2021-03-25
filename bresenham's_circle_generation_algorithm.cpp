#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void eight_way_symmetry(int h,int k,int x,int y){
    putpixel(x+h,y+k,RED);
    putpixel(x+h,-y+k,YELLOW);
    putpixel(-x+h,-y+k,GREEN);
    putpixel(-x+h,y+k,YELLOW);
    putpixel(y+h,x+k,12);
    putpixel(y+h,-x+k,14);
    putpixel(-y+h,-x+k,15);
    putpixel(-y+h,x+k,6);
    sleep(1);
}
//Bresenham's
void main(){

    int gdriver = DETECT,gmode;
    int h,k,x,y,r,d;
    initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");
    cout<<" Enter The coordinates of center : ";
    cin>>h>>k;
    cout<<" Enter the radius : ";
    cin>>r;
    x=0;
    y=r;
    d=3-(2*r);
    eight_way_symmetry(h,k,x,y);

    while(x<=y){
      if(d<=0){
        d=d+(4*x)+6;
      }
     else{
        d=d+(4*x)-(4*y)+10;
        y=y-1;
        }
        x=x+1;
       eight_way_symmetry(h,k,x,y);
      }

    getch();
delay(100);
    closegraph();
}
