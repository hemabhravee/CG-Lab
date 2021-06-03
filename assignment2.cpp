// Design ‘Big N’ with character ‘N’, Vary the size of ‘Big N’ as per user input, like 10, 15, 20 e.t.c.

#include <iostream>
#include<vector> 
using namespace std;

// function to create Big N
vector<vector<char>> createBigN(int n){
    vector<vector<char>> matrix;
        for(int i=0; i<n; i++){
            vector<char> curLine;
            // first N
            curLine.push_back('N');
            for(int j=1; j<n; j++){
                //Middle N || End N
                if(j==i || j==n-1)
                    curLine.push_back('N');
                else
                    curLine.push_back(' ');
            }
            matrix.push_back(curLine);
        }
    return matrix;
}

// function to invert any matrix along X-Axis
vector<vector<char>> reflectXAxis(vector<vector<char>> matrix){
    vector<vector<char>> ans;
    int size = matrix.size();
    for(int i=0; i< size; i++){
        vector<char> temp(size,' ');
        ans.push_back(temp);
        for(int j=0; j< size; j++){
            ans[i][j] = matrix[size - i - 1][j];
        }
    }
    return ans;
}

// function to invert any matrix along Y-Axis
vector<vector<char>> reflectYAxis(vector<vector<char>> matrix){
    vector<vector<char>> ans;
    int size = matrix.size();
    for(int i=0; i< size; i++){
        vector<char> temp(size,' ');
        ans.push_back(temp);
        for(int j=0; j< size; j++){
            ans[i][j] = matrix[i][size-j-1];
        }
    }
    return ans;
}

// Function to print the 3 matrices together like reflections
void printMatrixWithReflections(vector<vector<char>> matrix, vector<vector<char>> Xmatrix, vector<vector<char>> Ymatrix, int x, int y){
    int size = matrix.size();
    for(int i=0; i< size; i++){
        for(int j=0; j<size; j++){
            cout<<matrix[i][j];
        }
        
        for(int j = 0; j < y; j++)
            cout<<' ';
        cout<<'|';
        for(int j = 0; j < y; j++)
            cout<<' ';
            
        for(int j=0; j<size; j++){
            cout<<Ymatrix[i][j];
        }
        cout<<"\n";
    }
    for(int i=1; i<x ; i++)
        cout<<"\n";
    for(int i=0; i<size; i++)
        cout<<'_';
    for(int i=0; i<=x ; i++)
        cout<<"\n";
    for(int i=0; i< size; i++){
        for(int j=0; j<size; j++){
            cout<<Xmatrix[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
    int n,x,y;
    while(true){
        while(true){
            cout<<"Enter number of lines : ";
            cin>>n;
            if(n > 2)
                {
                    cout<<"Enter distance from x-axis : ";
                    cin>>x;
                    cout<<"Enter distance from y-axis : ";
                    cin>>y;
                    break;
                }
            else
                cout<<"Number of lines must be greater than 2\n";
        }
        vector<vector<char>> matrix = createBigN(n);
        printMatrixWithReflections(matrix, reflectXAxis(matrix), reflectYAxis(matrix), x, y);
        
        string x;
        cout<<"\n\nGo Again? (Y/N) : ";
        cin>>x;
        if(x == "n" || x == "N")
            break;
    }
    cout<<"Exiting...\n";
    return 0;
}