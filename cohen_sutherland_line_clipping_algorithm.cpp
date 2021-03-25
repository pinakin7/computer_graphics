#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

// Region Codes
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

// Window Coordinates
const double x_min = 100,x_max = 500,y_min = 100,y_max = 500;

int point_codes(double x, double y){
    int code = INSIDE;
    if( x < x_min)
        code |= LEFT;
    else if(x > x_max)
        code |= RIGHT;
    if(y < y_min)
        code |= BOTTOM;
    else if(y > y_max)
        code |= TOP;
    return code;
}

void cohensutherlandlinecliping(double x1,double y1,double x2,double y2){

    //Codes of the points
    int code1 = point_codes(x1,y1);
    int code2 = point_codes(x2,y2);

    bool accept = false;

    while(true){

        if((code1 == INSIDE) && (code2 == INSIDE)){
            accept = true;
            break;
        }
        else if(code1 & code2){
            break;
        }
        else{

            int code_out;
            double x,y;

            if(code1 !=0)
                code_out = code1;
            else
                code_out = code2;

            double m = (y2 - y1)/(x2 - x1);
            if(code1 & TOP){
                y = y_max;
                x = (y_max - y1)/m + x1;
            }
            else if(code_out & BOTTOM){
                y = y_min;
                x = (y_min - y1)/m + x1;
            }
            else if(code_out & LEFT){
                x = x_min;
                y = m*(x_min - x1) + y1;
            }
            else if(code_out & RIGHT){
                x = x_max;
                y = m*(x_max - x1) + y1;
            }
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = point_codes(x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                code2 = point_codes(x2, y2);
            }
        }
    }

    if(accept){
        //Draw line from (x1,y1) to (x2,y2) green
        setcolor(2);
        line(x1,y1,x2,y2);
    }
    else{
        //Draw line from (x1,y1) to (x2,y2) red
        setcolor(4);
        line(x1,y1,x2,y2);
    }

}

void main(){
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C://TURBOC3//BGI");

    // Draw Clipping Window
    rectangle(x_min,x_max,x_max,y_min);

    // Draw Lines
    setcolor(4);
    line(100,200,300,400);
    line(50,40,30,40);
    line(500,700,100,200);

    int a;
    cout<<" Do you want to Clip the Lines into the Window ? :";
    cin>>a;

    if(a==1){
        cohensutherlandlinecliping(100,200,300,400);
        cohensutherlandlinecliping(50,40,30,40);
        cohensutherlandlinecliping(500,700,100,200);
    }

    getch();
    closegraph();

}
