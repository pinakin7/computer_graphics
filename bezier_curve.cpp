#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

struct control_points{
    int x;
    int y;
};

class curve{
    private:
        control_points controlpoints[100];
        double u;
        int n_cp;
        int degree;
        double fact;
        double x,y;
    public:
        void get_points();
        void display_points();
        double factorial(int);
        double nCr(int);
        double bernstein_func(int);
        double distance(int,int);
        void curve_func();
        void driver();
};

double curve::factorial(int n){
    double res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

double curve::nCr(int r){
    return fact / (factorial(r) * factorial(n_cp - r));
}

double curve::distance(int x1, int y1){
    return sqrt(pow(x1,2) + pow(y1,2));
}

void curve::display_points(){
    setcolor(4);
    control_points cp[n_cp];
    for(int i = 0; i < n_cp; i++){
        cp[i].x = controlpoints[i].x;
        cp[i].y = controlpoints[i].y;
    }
    for(int i = 0; i < n_cp; i++){
        for(int j = 0; j < n_cp-i-1; j++){
            if(distance(cp[j].x,cp[j].x) > distance(cp[j+1].x,cp[j+1].x)){
                // swap
                int temp;

                temp = cp[j].x;
                cp[j].x = cp[j+1].x;
                cp[j+1].x = temp;

                temp = cp[j].y;
                cp[j].y = cp[j+1].y;
                cp[j+1].y = temp;

            }
        }
    }

    for(int i = 0; i < n_cp - 1; i++){
        setcolor(4);
        line(cp[i].x,cp[i].y,cp[i+1].x,cp[i+1].y);
    }

}

void curve::get_points(){
    cout<<"\n Enter the Total Number of Control Points : ";
    cin>>n_cp;
    degree = n_cp-1;
    cout<<"\n Enter the Coordinates of Control Points : ";
    for(int i = 0; i < n_cp; i++){
        cout<<"\n Enter the x coordinate : ";
        cin>>controlpoints[i].x;
        cout<<"\n Enter the y coordinate : ";
        cin>>controlpoints[i].y;
    }

    fact = factorial(n_cp);
    display_points();

}


double curve::bernstein_func(int i){
    double B = 0;
    B = nCr(i) * pow((1 - u),(n_cp-i)) * pow(u,i);
    return(B);
}

void curve::curve_func(){
    for(u = 0; u < 1; u+=0.0001){
        x = 0;
        y = 0;
        for(int i = 0; i < n_cp; i++){
            x += controlpoints[i].x * bernstein_func(i);
            y += controlpoints[i].y * bernstein_func(i);
        }
//        cout<<x<<" "<<y<<endl;
        putpixel(x,y,15);
    }
}

void curve::driver(){
    cout<<"\n \t\t\t\t\t\t\t Bezier Curve ";
    get_points();
    stringstream ss;
    string deg;
    ss<<degree;
    ss>>deg;
    int height = getwindowheight();
    int width = getwindowwidth();
    string text(" Bezier Curve of Degree ");
    text = text + deg;
    const char *c = text.c_str();
    setcolor(14);
    outtextxy(width/3,3,c);
    curve_func();
}

int main(){

    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"D:\Programs\c cpp\graphics\BGI");

    curve bezier;
    bezier.driver();

    getch();
    closegraph();

return 0;
}
