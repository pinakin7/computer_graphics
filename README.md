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
### 2. Bresenhams Line Drawing Algorithm

## Circle Generation Line Drawing Algorithm : 
Circle is an eight-way symmetric figure. The shape of circle is the same in all quadrants. In each quadrant, there are two octants. If the calculation of the point of one octant is done, then the other seven points can be calculated easily by using the concept of eight-way symmetry.
<br>
![Eight Way Symmerty of a Circle](circle.jpg)
<br>


### 1. Bresenhams Circle Generation Algorithm
### 2. Midpoint Circle Generation Algorithm

## Clipping Techniques

When we have to display a large portion of the picture, then not only scaling & translation is necessary, the visible part of picture is also identified. This process is not easy. Certain parts of the image are inside, while others are partially inside. The lines or elements which are partially visible will be omitted.
<br>
For deciding the visible and invisible portion, a particular process called clipping is used. Clipping determines each element into the visible and invisible portion. Visible portion is selected. An invisible portion is discarded.
<br>
#### Types of Lines:
##### Lines are of three types:
<br>
![Types of Lines](clip1.jpg)
<br>
Visible: A line or lines entirely inside the window is considered visible<br>
Invisible: A line entirely outside the window is considered invisible<br>
Clipped: A line partially inside the window and partially outside is clipped. For clipping point of intersection of a line with the window is determined.<br>
Clipping can be applied through hardware as well as software. In some computers, hardware devices automatically do work of clipping. In a system where hardware clipping is not available software clipping applied.<br>
<br>
###### Following figure show before and after clipping
<br>
![](clip2.jpg)
<br>
The window against which object is clipped called a clip window. It can be curved or rectangle in shape.<br>

### 1. Point Clipping
### 2. Line Clipping
### 3. Polygon Clipping
### 4. Text Clipping
### 5. Curve Clipping

