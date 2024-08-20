/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int A=0, B=0,C=0;
    cin >> A >> B >> C;

    if (A<B)
    {
        // A보다 B가 더 크다.
        if(B>C)
        {
            //B가더 크다
            //B가 가장 크다
            if (A>C)
            {
                cout << A;
            }
            else
            {
                cout << C;
            }
        }
        else
        {
            //C가 가장 크다.
            cout << B;
        }
    }
    else 
    {
        // B보다 A가 더 크다.
        if(A>C)
        {
            //C보다 A가 더 크다
            //A가 가장 크다
            if (C>B)
            {
                cout << C;
            }
            else
            {
                cout << B;
            }
        }
        else
        {
            // A보다 C가 더 크다.
            // C가 가장 크다.
            cout << A;
        }
    }
    
}
