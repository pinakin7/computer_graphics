# Computer Graphics Algorithms
Computer Graphics involves technology to access. The Process transforms and presents information in a visual form. The role of computer graphics insensible. In today life, computer graphics has now become a common element in user interfaces, T.V. commercial motion pictures.<br>

Computer Graphics is the creation of pictures with the help of a computer. The end product of the computer graphics is a picture it may be a business graph, drawing, and engineering.<br>

In computer graphics, two or three-dimensional pictures can be created that are used for research. Many hardware devices algorithm has been developing for improving the speed of picture generation with the passes of time. It includes the creation storage of models and image of objects. These models for various fields like engineering, mathematical and so on. <br>

Today computer graphics is entirely different from the earlier one. It is not possible. It is an interactive user can control the structure of an object of various input devices.<br>

## Scan Convertion : 
It is a process of representing graphics objects a collection of pixels. The graphics objects are continuous. The pixels used are discrete. Each pixel can have either on or off state.


## Line Drawing Algorithms : 
A straight line may be defined by two endpoints & an equation. In fig the two endpoints are described by (x1,y1) and (x2,y2). The equation of the line is used to determine the x, y coordinates of all the points that lie between these two endpoints.<br>

![Scan Conversion of Straight Line](scan_line.jpg)

Using the equation of a straight line, y = mx + b where m = Scan Converting a Straight Line & b = the y interrupt, we can find values of y by incrementing x from x =x1, to x = x2. By scan-converting these calculated x, y values, we represent the line as a sequence of pixels.


### 1. Digital Differential Analyzer Line Drawing Algorithm 
DDA stands for Digital Differential Analyzer. It is an incremental method of scan conversion of line. In this method calculation is performed at each step but by using results of previous steps.<br>

Suppose at step i, the pixels is (xi,yi) <br>

The line of equation for step i <br>
              yi=mxi+b......................equation 1 <br>


Next value will be <br>
              yi+1=mxi+1+b.................equation 2 <br>
              m =DDA Algorithm<br>
              yi+1-yi=∆y.......................equation 3<br>
              yi+1-xi=∆x......................equation 4<br>
              yi+1=yi+∆y<br>
              ∆y=m∆x<br>
              yi+1=yi+m∆x<br>
              ∆x=∆y/m<br>
              xi+1=xi+∆x<br>
              xi+1=xi+∆y/m<br>

Case1: When |M|<1 then (assume that x12)<br>
              x= x1,y=y1 set ∆x=1<br>
              yi+1=y1+m,     x=x+1<br>
              Until x = x2<br>

Case2: When |M|<1 then (assume that y12)<br>
              x= x1,y=y1 set ∆y=1<br>
              xi+1=DDA Algorithm,     y=y+1<br>
              Until y → y2<br>
              
### 2. Bresenhams Line Drawing Algorithm

## Circle Generation Line Drawing Algorithm : 

### 1. Bresenhams Circle Generation Algorithm
### 2. Midpoint Circle Generation Algorithm

