/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int Y[42];
    for(int i = 0;i<42;i++){
        Y[i] = 0; 
    }
    for(int i =0;i<10;i++){
        int b = 0;
        cin >> b;
        Y[b%42]++;
    }
    int d = 0;
    for(int i = 0;i<42;i++){
        if(Y[i])d++;
    }
    cout << d;
}
