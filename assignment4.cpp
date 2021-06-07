//#include<stdio.h>
#include <iostream>
//#include<graphics.h>
#include<math.h>
using namespace std;

// Bresenham’s Line Drawing Algorithm
// Draws a line joining points (x1,y1) & (x2,y2)
// where x1 < x2 and y1 < y2
void bresenham(int x1, int y1, int x2, int y2)
{
    int dy = y2 - y1;
    int dx = x2 - x1;
   
    int slope_error_new = 2*dy - dx;
    int x = x1, y = y1;
    do
    {
      // paint the current coords
      // putPixel(x,y,BLACK);
      cout<<"("<<x<<","<<y<<")\n";
      
      // for next coords we choose from (x+1,y) & (x+1,y+1)
      // depending on the slope error
      if(slope_error_new >= 0){
          slope_error_new+=(2*dy - 2*dx);
          y++;
      }
      else{
          slope_error_new+=(2*dy);
      }
      x++;
    }while(x<=x2);
}

// DDA Line drawing Algorithm
// draws a line joining points (x1,y1) & (x2,y2)
void dda(int x1, int y1, int x2, int y2){
    float dy = y2 - y1;
    float dx = x2 - x1;
    
    // calculate steps required for generating pixels
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    
    // calculate increment in x & y for each steps
    float xi = dx / (float) steps;
    float yi = dy / (float) steps;
    
    float x = x1, y = y1;
    
    for(int i=0; i<=steps; i++){
        // paint the current coords
        //putPixel(round(x),round(y),LIGHTBLUE);
        cout<<"("<<x<<","<<y<<")\n";
        
        x+=xi;
        y+=yi;
    }
}
 
// driver function
int main()
{
   // nt gd = DETECT, gm;
 
    // Initialize graphics function
    //initgraph (&gd, &gm, "");  
    
    int x1 = 3, y1 = 2, x2 = 15, y2 = 5;
    bresenham(x1, y1, x2, y2);
    dda(x1, y1, x2, y2);
    
    //closeGraph();
    return 0;
}