#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;


#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

struct point{
    int x;
    int y;
};

class polygon{
    private:
        point p[20];
        point t[20];
        int tx,ty;
        int pivot_x,pivot_y;
        float sx,sy;
        int polygon_size;
        int theta;
        int A,B;
        float Sx,Sy;
        int C,D;
    public:
        void read_coordinates();
        void display_polygon();
        void display_transformed();
        void transformations();
        void translation();
        void rotation();
        void scaling();
        void reflection();
        void shearing();
        void init();

};

void polygon::init(){
    for(int i = 0; i <= polygon_size; i++){
        t[i].x = p[i].x;
        t[i].y = p[i].y;
    }
}

void polygon::display_polygon(){
    setcolor(4);
    for(int i = 0; i < polygon_size; i++){
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
}

void polygon::display_transformed(){
    setcolor(2);
    for(int i = 0; i < polygon_size; i++){
        line(t[i].x,t[i].y,t[i+1].x,t[i+1].y);
    }
}

void polygon::read_coordinates(){
    cout<<" Enter the number of Vertices of the Polygon : ";
    cin>>polygon_size;
    int i;
    for(i = 0; i < polygon_size; i++){
        cout<<" Enter x coordinate : ";
        cin>>p[i].x;
        cout<<" Enter y coordinate : ";
        cin>>p[i].y;
    }
    p[i].x = p[0].x;
    p[i].y = p[0].y;

    init();

}

void polygon::translation(){
    for(int i = 0; i <= polygon_size; i++){
        t[i].x = t[i].x + tx;
        t[i].y = t[i].y + ty;
    }

}

void polygon::rotation(){
    for(int i = 0; i <= polygon_size; i++){

        int x_shifted = t[i].x - pivot_x;
        int y_shifted = t[i].y - pivot_y;

        t[i].x = (x_shifted*COS(theta) - y_shifted*SIN(theta)) + pivot_x;
        t[i].y = (x_shifted*SIN(theta) + y_shifted*COS(theta)) + pivot_y;
    }
}

void polygon::scaling(){
    for(int i = 0; i <= polygon_size; i++){
        t[i].x = t[i].x*sx;
        t[i].y = t[i].y*sy;
    }
}

void polygon::reflection(){

    if(A==0 && B==0){
        for(int i = 0; i <= polygon_size; i++){
            t[i].x = (-1)*t[i].x;
            t[i].y = (-1)*t[i].y;
        }
    }

    else if(A==0 && B!=0){
        for(int i = 0; i <= polygon_size; i++){
            t[i].x = t[i].x;
            t[i].y = (-1)*t[i].y;
        }
    }

    else if(A!=0 && B==0){
        for(int i = 0; i <= polygon_size; i++){
            t[i].x = (-1)*t[i].x;
            t[i].y = t[i].y;
        }
    }

    else if(A==1 && B==1){
        for(int i = 0; i <= polygon_size; i++){
            int temp = t[i].x;
            t[i].x = t[i].y;
            t[i].y = temp;
        }
    }

    else if(A==-1 && B==1){
        for(int i = 0; i <= polygon_size; i++){
            int temp = t[i].x;
            t[i].x = (-1)*t[i].y;
            t[i].y = (-1)*temp;
        }
    }

}

void polygon::shearing(){
    if(C==1 && D!=1){
        cout<<"\n Enter the Shearing Factor About X-Axis : ";
        cin>>Sx;
        for(int i = 0; i <= polygon_size; i++){
            int temp=t[i].y;
            t[i].x = t[i].x+(temp*Sx);
            t[i].y = temp;
        }
    }
    else if(C!=1 && D==1){
        cout<<"\n Enter the Shearing Factor About Y-Axis : ";
        cin>>Sy;
        for(int i = 0; i <= polygon_size; i++){
            int temp = t[i].x;
            t[i].x = temp;
            t[i].y = t[i].y+(temp*Sy);
        }
    }
    else if(C==1 && D==1){
        cout<<"\n Enter the Shearing Factor About X-Axis : ";
        cin>>Sx;
        cout<<"\n Enter the Shearing Factor About Y-Axis : ";
        cin>>Sy;
        for(int i = 0; i <= polygon_size; i++){
            int tempx = t[i].x;
            int tempy = t[i].y;
            t[i].x = tempx+(tempy*Sx);
            t[i].y = tempy+(tempx*Sy);
        }
    }

}

void polygon::transformations(){

    int ch;
    cout<<"\n\t\t 2D Transformations : \n";
    while(true){
        cout<<" \n\t\t\t 1. Translation \n\t\t\t 2. Rotation \n\t\t\t 3. Scaling \n\t\t\t 4. Reflection \n\t\t\t 5. Shearing \n\t\t\t 6. Exit \n";
        cout<<" \n\t  Enter The Choice For Transforming the given Polygon using this 2D Transformations : ";

        cin>>ch;

        switch(ch){
            case 1:
                cout<<"\n Enter Translation Distance for x : ";
                cin>>tx;
                cout<<"\n Enter Translation Distance for y : ";
                cin>>ty;
                translation();
                break;

            case 2:
                cout<<"\n Enter The Pivot point for x : ";
                cin>>pivot_x;
                cout<<"\n Enter The Pivot point for y : ";
                cin>>pivot_y;
                cout<<"\n Enter the angle of rotation : ";
                cin>>theta;
                rotation();
                break;

            case 3:
                cout<<"\n Enter The Scaling Factor for x : ";
                cin>>sx;
                cout<<"\n Enter The Scaling Factor for y : ";
                cin>>sy;
                scaling();
                break;

            case 4:
                cout<<"\n Reflection about Ax = By \n ";
                cout<<" Enter the values of A and B : ";
                cin>>A>>B;
                reflection();
                break;

            case 5:
                cout<<"\n Shearing about Cx,Dy \n ";
                cout<<" Enter the values of C and D : ";
                cin>>C>>D;
                shearing();
                break;

            default:
                return false;
        }
        display_transformed();
    }

}

int main(){


    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"D:\\Programs\\c cpp\\graphics\\BGI");


    polygon p;
    p.read_coordinates();
    p.display_polygon();

    p.transformations();
    setcolor(15);
    p.display_transformed();

    getch();
    closegraph();

return 0;
}
