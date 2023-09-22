/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int N=0,X=0;
    int A[10000];
    
    cin >> N >> X;
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    for(int i=0;i<N;i++)
    {
        if(A[i]<X)
        {
            cout << A[i]<< " ";
        }
    }
    
}
