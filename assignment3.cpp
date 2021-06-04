//Design a sinusoidal curve for one cycle with character “*”.
//Show the axises with character “#”.
//Level the axises appropriately.

#include <iostream>
#include <math.h>

using namespace std;
int amp = 20; // amplitude
int k = 5;    // (proportional to)time period
int req_constant = 101; //necessary constant DO NOT CHANGE

int main()
{
    // mapping sin values for x to y 
    float values[req_constant];
    for(int i=0; i<req_constant; i++){
        values[i] = -1*(round(amp * sin(i / (3.14 * k))) - amp);
    }
    
    // mapping x,y values to a 2d matrix
    int matrix[2*amp+1][req_constant];
    for(int i=0; i<req_constant; i++){
        int x = values[i];
        int y = i;
        matrix[x][y] = '*';
    }
    
    // printing the 2d matrix
    for(int i=0; i<1+(2* amp); i++){
        for(int j=0; j<req_constant-1; j++){
            if(i == amp && matrix[i][j] != '*')
                cout<<'#';
            else if(matrix[i][j] == '*')
                cout<<'*';
            else
                cout<<' ';
        }
        cout<<"\n";
    }
    return 0;
}

