// Design ‘Big N’ with character ‘N’, Vary the size of ‘Big N’ as per user input, like 10, 15, 20 e.t.c.

#include <iostream>

using namespace std;

int main()
{
    
    int n;
    while(true){
        while(true){
            cout<<"Enter number of lines : ";
            cin>>n;
            if(n > 2)
                break;
            else
                cout<<"Number of lines must be greater than 2\n";
        }
    
        for(int i=0; i<n; i++){
            // first N
            cout<<"N";
            for(int j=1; j<n; j++){
                //Middle N || End N
                if(j==i || j==n-1)
                cout<<"N";
                else
                cout<<" ";
            }
            cout<<"\n";
        }
        string x;
        cout<<"Go Again? (Y/N) : ";
        cin>>x;
        if(x == "n" || x == "N")
            break;
    }
    cout<<"Exiting...";
    return 0;
}
