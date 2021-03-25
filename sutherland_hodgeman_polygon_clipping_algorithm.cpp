#include<iostream>
#include<graphics.h>

using namespace std;

const int MAX_POINTS = 50;

int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int num = (x1*y2 - y1*x2) * (x3-x4) - (x1-x2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int num = (x1*y2 - y1*x2) * (y3-y4) - (y1-y2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

void display(int fig[][2],int n){
    for(int i = 0; i < n; i++){
        if(i == n-1){
            line(fig[i][0],fig[i][1],fig[0][0],fig[0][1]);
        }
        else{
            line(fig[i][0],fig[i][1],fig[i+1][0],fig[i+1][1]);
        }
    }

}

void clip(int polygon[][2], int &polygon_size, int x1, int y1, int x2, int y2){
	int new_points[MAX_POINTS][2], new_polygon_size = 0;

    for (int i = 0; i < polygon_size; i++){

		int k = (i+1) % polygon_size;
		int ix = polygon[i][0], iy = polygon[i][1];
		int kx = polygon[k][0], ky = polygon[k][1];


		int i_position = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);


		int k_position = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);


		if ((i_position < 0) && (k_position < 0)){
			new_points[new_polygon_size][0] = kx;
			new_points[new_polygon_size][1] = ky;
			new_polygon_size++;
		}


		else if ((i_position >= 0) && (k_position < 0)){

			new_points[new_polygon_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_points[new_polygon_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_polygon_size++;

			new_points[new_polygon_size][0] = kx;
			new_points[new_polygon_size][1] = ky;
			new_polygon_size++;
		}


		else if ((i_position < 0) && (k_position >= 0)){

			new_points[new_polygon_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_points[new_polygon_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
			new_polygon_size++;
		}
	}

	polygon_size = new_polygon_size;
	for (int i = 0; i < polygon_size; i++){
		polygon[i][0] = new_points[i][0];
		polygon[i][1] = new_points[i][1];
	}
}


void sutherland_hodgman(int polygon[][2], int polygon_size, int window[][2], int window_size){

	for (int i = 0; i < window_size; i++){
		int k = (i+1) % window_size;
		clip(polygon, polygon_size, window[i][0], window[i][1], window[k][0], window[k][1]);
	}


	for (int i = 0; i < polygon_size; i++){
        cout << '(' << polygon[i][0] <<", " << polygon[i][1] << ") ";
    }
    setcolor(2);
    display(polygon,polygon_size);
    setfillstyle(HATCH_FILL,BLUE);
//    setfillstyle(SOLID_FILL,GREEN);
    floodfill(polygon[0][0]-1,polygon[0][1]-1,2);
}

int main(){

    int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"D://Programs//c cpp//graphics//BGI");


	int window_size = 4;
	int window[][2] = {{100,100},{100,300},{300,300},{300,100}};
    display(window,window_size);

    int polygon_size = 3;
	int polygon[20][2] = {{100,50}, {200,350},{400,200}};
    setcolor(4);
    display(polygon,polygon_size);

    cout<<" \n Do you Want to Clip The Polygon ? ";
    int x;
    cin>>x;
	if(x==1){
        sutherland_hodgman(polygon, polygon_size, window, window_size);
	}
	else{
        cout<<" Thank You ";
	}
//    sutherland_hodgman(polygon, polygon_size, window, window_size);

    getch();
    closegraph();

	return 0;
}

